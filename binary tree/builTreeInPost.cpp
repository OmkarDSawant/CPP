#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postorder[], int inorder[], int start, int end){

    if(start>end){
        return NULL;
    }

    static int idx=4; //Only one instance in all stacks. Initialized only once.

    int curr = postorder[idx];
    idx--;

    Node* node = new Node(curr);

    int pos = search(inorder,start,end,curr);

    if(start==end){
        return node;
    }

    node->right = buildTree(postorder,inorder,pos+1,end);
    node->left = buildTree(postorder,inorder,start,pos-1);
    
    return node;    
}

void inorderT(Node* root){

    if(root==NULL){
        return;
    }

    inorderT(root->left);
    cout<<root->data<<" ";
    inorderT(root->right);
}

int main(){

    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    Node* root = buildTree(postorder,inorder,0,4);

    inorderT(root);

    return 0;
}