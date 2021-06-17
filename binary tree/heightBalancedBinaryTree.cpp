//mod(leftSubTree - rightSubTree) <= 1

#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isBalanced(Node* root, int* height){//Time complexity O(n^2)

    if(root==NULL){
        return true;
    }

    int lh = 0, rh = 0;

    if(isBalanced(root->left,&lh) == false){
        return false;
    }

    if(isBalanced(root->right,&rh) == false){
        return false;
    }

    *height = max(lh,rh) + 1;

    if(abs(lh-rh)<=1){ //Imp
        return true;
    }else{
        return false;
    }
}

int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);


    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int height = 0;

    if(isBalanced(root,&height)){
        cout<<"Balanced Tree";
    }else{
        cout<<"Unbalanced Tree";
    }

    return 0;
}