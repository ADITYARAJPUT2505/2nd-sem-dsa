#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;

	node(int t) {
		data = t;
		next = prev = NULL;
	}
};

void printlist(node* head) {
	node* curr = head;
	if (head == NULL) {
		return;
	}

	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
}

node* insertbegin(node* head, int val) {
	node* first = new node(val);
	first->next = head;
	if (head != NULL) {
		head->prev = first;
	}

	return first;
}

node *insertpos(node*  head, int val, int pos) {
	node* temp = new node(val);
	node* curr = head;
	if (head == NULL) {
		return temp;
	}
	int t = 1;
	while (curr->next != NULL && t != pos - 1) {
		t++;
		curr = curr->next;
	}
	if (curr->next == NULL) {
		cout << "Invalid position" << endl;
	} else {
		temp->next = curr->next;
		curr->next->prev = temp;
		curr->next = temp;
		temp->prev = curr;
	}
	return head;
}

node* del(node* head) {
	if (head == NULL) {
		return NULL;
	} else {
		node* temp = head->next;
		delete head;
		temp->prev = NULL;
		return temp;
	}
}

node* deltail(node* head) {
	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	node* curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->prev->next = NULL;
	delete curr;
	return head;
}

node* delpos(node* head, int pos) {
	if (head == NULL) {
		return NULL;
	}
	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	node* curr = head;
	int t = 1;
	while (curr->next != NULL && t != pos - 1) {
		t++;
		curr = curr->next;
	}
	node* temp = curr->next;
	curr->next = temp->next;
	curr->next->prev = curr;
	delete temp;
	return head;
}

int main() {
	node* head = NULL;

	int choice;
	int val, pos;

	while (true) {
		cout << "1. Insert at the beginning" << endl;
		cout << "2. Insert at a position" << endl;
		cout << "3. Delete from the beginning" << endl;
		cout << "4. Delete from the end" << endl;
		cout << "5. Delete from a position" << endl;
		cout << "6. Print the list" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter the value to insert at the beginning: ";
				cin >> val;
				head = insertbegin(head, val);
				break;
			case 2:
				cout << "Enter the value to insert: ";
				cin >> val;
				cout << "Enter the position to insert at: ";
				cin >> pos;
				head = insertpos(head, val, pos);
				break;
			case 3:
				head = del(head);
				break;
			case 4:
				head = deltail(head);
				break;
			case 5:
				cout << "Enter the position to delete: ";
				cin >> pos;
				head = delpos(head, pos);
				break;
			case 6:
				cout << "Linked List: ";
				printlist(head);
				cout << endl;
				break;
			case 7:
				cout << "Exiting..." << endl;
				exit(0);
			default:
				cout << "Invalid choice! Please try again." << endl;
		}
	}

	return 0;
}

