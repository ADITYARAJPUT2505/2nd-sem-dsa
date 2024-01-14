#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;

	node(int t)
	{
		data = t;
		next = NULL;
	}
};

void printlist(node* head)
{
	node* curr = head;
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

node* insertbegin(node* head, int val)
{
	node* first = new node(val);
	first->next = head;
	return first;
}

node* insertend(node* head, int val)
{
	node* last = new node(val);
	if (head == NULL)
	{
		head = last;
		return head;
	}
	node* curr = head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = last;
	return head;
}

node* deletebegin(node* head)
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return NULL;
	}
	node* temp = head->next;
	delete head;
	return temp;
}

node* deletetail(node* head)
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return NULL;
	}
	if (head->next == NULL)
	{
		delete head;
		return NULL;
	}
	node* curr = head;
	while (curr->next->next != NULL)
	{
		curr = curr->next;
	}
	delete curr->next;
	curr->next = NULL;
	return head;
}

node* insertpos(node* head, int pos, int val)
{
	node* newnode = new node(val);
	if (head == NULL)
	{
		head = newnode;
		return head;
	}
	if (pos == 1) // Insert at the beginning
	{
		newnode->next = head;
		head = newnode;
		return head;
	}
	node* curr = head;
	int t = 1; // Start from position 1
	while (curr != NULL && t != pos - 1) // Check for curr != NULL
	{
		t++;
		curr = curr->next;
	}
	if (curr == NULL) // If curr becomes NULL before reaching the desired position
	{
		cout << "Invalid position!" << endl;
		return head;
	}
	node* temp = curr->next;
	curr->next = newnode;
	newnode->next = temp;

	return head;
}

node* delpos(node* head, int pos)
{
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return NULL;
	}
	if (pos == 1)
	{
		node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}
	node* curr = head;
	int t = 1;
	while (curr != NULL && t != pos - 1)
	{
		t++;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout << "Invalid position!" << endl;
		return head;
	}
	node* temp = curr->next;
	curr->next = temp->next;
	delete temp;
	return head;
}

int main()
{
	node* head = NULL;
	int choice, val, pos;

	while (true)
	{
		cout << "1. Insert at the beginning" << endl;
		cout << "2. Insert at the end" << endl;
		cout << "3. Delete from the beginning" << endl;
		cout << "4. Delete from the end" << endl;
		cout << "5. Insert at a given position" << endl;
		cout << "6. Delete from a given position" << endl;
		cout << "7. Print the list" << endl;
		cout << "8. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter value to insert at the beginning: ";
			cin >> val;
			head = insertbegin(head, val);
			break;
		case 2:
			cout << "Enter value to insert at the end: ";
			cin >> val;
			head = insertend(head, val);
			break;
		case 3:
			head = deletebegin(head);
			break;
		case 4:
			head = deletetail(head);
			break;
		case 5:
			cout << "Enter position to insert: ";
			cin >> pos;
			cout << "Enter value to insert: ";
			cin >> val;
			head = insertpos(head, pos, val);
			break;
		case 6:
			cout << "Enter position to delete: ";
			cin >> pos;
			head = delpos(head, pos);
			break;
		case 7:
			cout << "The list is: ";
			printlist(head);
			break;
		case 8:
			exit(0);
		default:
			cout << "Invalid choice" << endl;
		}
	}

	return 0;
}

