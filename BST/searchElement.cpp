#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* left, *right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* searchBST(Node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key == root->data){
        return root;
    }
    if(key < root->data){
        return searchBST(root->left,key);
    }
    return searchBST(root->right,key);
}

Node* insertBST(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insertBST(root->left,val);
    }else{
        root->right = insertBST(root->right,val);
    }
    return root;
}

int main(){
    Node* root = insertBST(NULL,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);

    if(searchBST(root,7)==NULL){
        cout<<"Element not present";
    }else{
        cout<<"Element present";
    }
    return 0;
}