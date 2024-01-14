#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
	node(int t)
	{
		data=t;
		left=NULL;
		right=NULL;
	}
};

node *constructNode(int val)
{
	node *newNode = new node(val);
	return newNode;
}
void preorder(node* head) {
    if (head != NULL) {
        printf("%d\t", head->data);
        preorder(head->left);
        preorder(head->right);
    }
}

void inorder(node* head) {
    if (head == NULL) {
        return;
    }

    inorder(head->left);
    printf("%d\t", head->data);
    inorder(head->right);
}

void postorder(node* head) {
    if (head != NULL) {
        postorder(head->left);
        postorder(head->right);
        printf("%d\t", head->data);
    }
}
node* insert(node* head,int val)
{
	if (head == NULL)
		return  constructNode(val);
	else if (head->data < val)
		head->right = insert(head->right, val);
	else if (head->data > val)
		head->left = insert(head->left, val);
	return head;
}
int main()
{
	int n;
	cin>>n;
	node* head=NULL;
	for(int i=0 ; i<n ; i++)
	{
		int val; 
		cin>>val;
		head= insert(head,val);
	}
	inorder(head);
	return 0;
}
