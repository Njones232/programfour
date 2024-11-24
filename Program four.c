#ifndef SPECIALSTACK_H
#define SPECIALSTACK_H

#include <stack>
#include <iostream>
#include <stdexcept>

using namespace std;

class SpecialStack {
private:
    stack<int> stk;  // The main stack

public:
    // Push an element onto the stack
    void push(int value) {
        stk.push(value);
    }

    // Pop the top element from the stack
    void pop() {
        if (stk.empty()) {
            throw runtime_error("Stack is empty!");
        }
        stk.pop();
    }

    // Peek at the top element without popping it
    int peek() {
        if (stk.empty()) {
            throw runtime_error("Stack is empty!");
        }
        return stk.top();
    }

    // Check if the stack is empty
    bool empty() {
        return stk.empty();
    }

    // Print the stack elements from top to bottom
    void printStack() {
        if (stk.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        stack<int> temp = stk;  // Create a temporary copy of the stack
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    // Pop the most recent odd number from the stack
    void popOdd() {
        if (stk.empty()) {
            throw runtime_error("Stack is empty!");
        }

        stack<int> temp;
        bool popped = false;

        // Find and remove the odd element
        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            if (!popped && top % 2 != 0) {
                popped = true;  // Remove the first odd number
            } else {
                temp.push(top);
            }
        }

        // Restore the elements back into the stack
        while (!temp.empty()) {
            stk.push(temp.top());
            temp.pop();
        }

        if (!popped) {
            throw runtime_error("No odd element to pop!");
        }
    }

    // Pop the most recent even number from the stack
    void popEven() {
        if (stk.empty()) {
            throw runtime_error("Stack is empty!");
        }

        stack<int> temp;
        bool popped = false;

        // Find and remove the even element
        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            if (!popped && top % 2 == 0) {
                popped = true;  // Remove the first even number
            } else {
                temp.push(top);
            }
        }

        // Restore the elements back into the stack
        while (!temp.empty()) {
            stk.push(temp.top());
            temp.pop();
        }

        if (!popped) {
            throw runtime_error("No even element to pop!");
        }
    }
};

#endif // SPECIALSTACK_H

#include "SpecialStack.h"

#include <iostream>
#include "SpecialStack.h"

int main() {
    SpecialStack one, two, three, four;

    try {
        cout << "Stack one" << endl;
        one.push(41);
        one.push(66);
        one.push(91);
        one.push(88);
        one.push(33);
        one.popEven();
        one.printStack();
    }
    catch (const exception& e) {
        cout << "Unable to complete operations: " << e.what() << endl << endl;
    }

    try {
        cout << "Stack two" << endl;
        two.push(1);
        two.push(9);
        two.push(6);
        two.push(2);
        two.push(8);
        two.push(6);
        two.push(4);
        two.popOdd();
        two.printStack();
    }
    catch (const exception& e) {
        cout << "Unable to complete operations: " << e.what() << endl << endl;
    }

    try {
        cout << "Stack three" << endl;
        three.popEven();
        three.printStack();
    }
    catch (const exception& e) {
        cout << "Unable to complete operations: " << e.what() << endl << endl;
    }

    try {
        cout << "Stack four" << endl;
        four.pop();
        four.printStack();
    }
    catch (const exception& e) {
        cout << "Unable to complete operations: " << e.what() << endl << endl;
    }

    return 0;
}

