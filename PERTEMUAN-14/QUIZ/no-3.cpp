// Referensi https://www.geeksforgeeks.org/cpp/inorder-traversal-of-binary-tree-in-c/
#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() { root = NULL; }

    void inorderTraversal(Node* node)
    {
        if (node != NULL) {

            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
};

int main()
{
    BinaryTree btree;
    btree.root = new Node('A');
    btree.root->left = new Node('B');
    btree.root->right = new Node('C');
    btree.root->left->left = new Node('D');
    btree.root->left->right = new Node('E');

    cout << "The inorder traversal of the binary tree is:"
         << endl;
    btree.inorderTraversal(btree.root);
    cout << endl;

    return 0;
}
