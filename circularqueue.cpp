#include<iostream>
using namespace std;
struct queue{
	int* arr;
	int front,cap, size;
	queue(int c)
	{   
	    arr = new int[cap];
		cap=c;
		size=0;
		front=0;
	}
	int getfront()
{
	return front;
}
int getrear()
{
	if(size==0)
	{
		return -1;
	}
	else
	{
		return (front+size-1)%cap;
	}
}
void enqueue(int val)
{
	if(cap==size)
	{
		return ;
	}
	int rear=getrear();
	rear=(rear+1)%cap;
	arr[rear]=val;
	size++;
}
void dequeue()
{
	if(size==0)
	{
		return ;
	}
	front=(front+1)%cap;
	size--;
}
void display()
{
	if(size==0)
	{
		cout<<"queue is empty"<<endl;
	}
	else {
            cout << "Queue elements: ";
            for (int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
}
};
int main()
{
	int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    queue queue(capacity);

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
