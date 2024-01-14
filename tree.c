#include<iostream>
#include<stdio.h>
struct node{
	int data ;
	node* left;
	node* right;
	node(int t)
	{
		data=t;
		left=right=NULL;
	}
};
int preorder(node* head)
{
	if(head==NULL)
	{
		return NULL;
	}
	printf("%d\t",(head->data));
	return preorder(head->left);
	return preorder(head->right);
	printf("\n");
}
int inorder(node* head)
{
	if(head==NULL)
	{
		return NULL;
	}
	return inorder(head->left);
	printf("%d\t",(head->data));	
	return inorder(head->right);
	printf("\n");
}
int postorder(node* head)
{
	if(head==NULL)
	{
		return NULL;
	}
	return postorder(head->left);
	return postrder(head->right);
	printf("%d\t",(head->data));
	printf("\n");
}
int main()
{
	node* head=new node(10);
    head->left=new node(20);
    head->left->left= new  node(30);
    head->left->right=new  node(40);
    node->right=new node(50);
    node->right->left=new node(60);
    node->right->rightnew node(70);
    preorder(head);
    inorder(head);
    postorder(head);
    
}
