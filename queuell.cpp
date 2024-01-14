#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val)
    {
    	data=val;
    	next=NULL;
	}
};

Node* head = NULL;
Node* tail = 	NULL;

void enqueue(int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    std::cout << val << " enqueued to the list." << std::endl;
}

int dequeue() {
    if (head == NULL) {
        std::cout << "Cannot dequeue from an empty list." << std::endl;
        return -1;
    }
    int val = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == NULL) {
        tail = NULL;
    }
    std::cout << val << " dequeued from the list." << std::endl;
    return val;
}

bool isEmpty() {
    return head == NULL;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();
    dequeue();

    dequeue(); // Trying to dequeue from an empty list

    return 0;
}

