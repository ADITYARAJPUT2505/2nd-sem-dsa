#include <iostream>
#include <algorithm>
using namespace std;

struct mystack {
    int* arr;
    int cap;
    int top;

    mystack(int c) {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    void push(int val) {
        if (top == cap - 1) {
            cout << "Stack is full. Cannot push element " << val << endl;
            return;
        }
        top++;
        arr[top] = val;
        cout << "Pushed element " << val << " onto the stack" << endl;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return -1;
        }
        int res = arr[top];
        top--;
        return res;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }

    int size() {
        return (top + 1);
    }

    void showStack() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Elements in the stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    mystack stack(capacity);

    int choice, value;

    while (true) {
        cout << "----- Menu -----" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Peek element" << endl;
        cout << "4. Get stack size" << endl;
        cout << "5. Show stack elements" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != -1) {
                    cout << "Popped element: " << value << endl;
                }
                break;
            case 3:
                value = stack.peek();
                if (value != -1) {
                    cout << "Top element: " << value << endl;
                }
                break;
            case 4:
                cout << "Size of the stack: " << stack.size() << endl;
                break;
            case 5:
                stack.showStack();
                break;
            case 6:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

