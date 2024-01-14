#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct  node{
    int data;
    struct node* next;
};
void traversal(node* ptr)
{  
        while(ptr!=NULL)
{
printf("%d \t",ptr->data);
    ptr=ptr->next;
}   
}

int main()
{
    node* head;
    node* first;
    node* second;
    head=( node*) malloc(sizeof( node));
    head->next=( node*) malloc(sizeof( node));
    head->next->next=( node*) malloc(sizeof( node));
    head->data=10;
    head->next->data=20;
    head->next->next->data=30;
    head->next->next->next=NULL;
    traversal(head);
    return 0;
}