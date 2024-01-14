#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    TreeNode* newNode = new TreeNode(val);
    if (root == NULL) {
        return newNode;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current->left == NULL) {
            current->left = newNode;
            return root;
        } else {
            q.push(current->left);
        }

        if (current->right == NULL) {
            current->right = newNode;
            return root;
        } else {
            q.push(current->right);
        }
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = NULL;

    // Inserting nodes into the binary tree
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);

    // Inorder traversal to display the elements of the tree
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

