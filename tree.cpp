#include <iostream>
#include <algorithm>

struct node {
    int data;
    node* left;
    node* right;

    node(int t) {
        data = t;
        left = right = NULL;
    }
};

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

int height(node* head) {
    if (head == NULL) {
        return 0;
    } else {
        return std::max(height(head->left), height(head->right)) + 1;
    }
}

int main() {
    node* head = new node(10);
    head->left = new node(20);
    head->left->left = new node(30);
    head->left->right = new node(40);
    head->right = new node(50);
    head->right->left = new node(60);
    head->right->right = new node(70);

    printf("Preorder traversal:\n");
    preorder(head);
    printf("\n");

    printf("Inorder traversal:\n");
    inorder(head);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder(head);
    printf("\n");

    int treeHeight = height(head);
    printf("Height of the tree: %d\n", treeHeight);

    return 0;
}

