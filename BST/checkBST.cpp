#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//For a node if the min and max allowed is satisfied and left and right subtree are also valid then the tree is a BST.
//Time Complexity O(n).
bool isBST(Node* root, Node* min, Node* max){
    if(root==NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return (leftValid && rightValid);
}

int main(){
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    cout<<isBST(root1, NULL, NULL);
    cout<<"\n";

    
    return 0;
}