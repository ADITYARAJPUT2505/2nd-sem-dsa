#include <iostream>
#include <stack>
using namespace std;

struct node {
    int data;
    node* next;


    node(int x) {
        data = x;
        next = NULL;
    }

    
};

struct mystack {
    node* head;
    int s;


    mystack() {
        head = NULL;
        s = 0;
    }

    int size() {
        return s;
    }

    void push(int x) {
        node* temp = new node(x);
        temp->next = head;
        head = temp;
        s++;
    }

    int pop() {
        if (head == NULL) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return -1;
        }
        node* temp = head;
        head = head->next;
        int res = temp->data;
        delete temp;
        s--;
        return res;
    }

    int peek() {
        if (head == NULL) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return head->data;
    }

    void print() {
        if (head == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    mystack stack;

    int choice, value;

    while (true) {
        cout << "----- Menu -----" << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Peek element" << endl;
        cout << "4. Get stack size" << endl;
        cout << "5. Print stack" << endl;
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
                cout << "Stack elements: ";
                stack.print();
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

