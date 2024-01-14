#include <iostream>
#include <algorithm>
using namespace std;

struct myqueue {
    int* arr;
    int size, cap;

    myqueue(int c) {
        cap = c;
        size = 0;
        arr = new int[cap];
    }

    void enqueue(int x) {
        if (size == cap) {
            cout << "Queue is full. Cannot enqueue element " << x << endl;
            return;
        }
        arr[size] = x;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    myqueue queue(capacity);

    int choice, value;

    while (true) {
        cout << "----- Menu -----" << endl;
        cout << "1. Enqueue element" << endl;
        cout << "2. Dequeue element" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}

