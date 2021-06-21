#include<iostream>

using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//case 1
void printSubtree(Node* root, int k){
    if(root == NULL || k<0){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printSubtree(root->left,k-1);
    printSubtree(root->right,k-1);
}

//case 2: distance from target to root is calculated and then passed accordingly to printSubtree function.
int nodesAtK(Node* root, Node* target, int k){
    if(root==NULL){
        return -1; // target node not found.
    }

    if(root == target){
        printSubtree(root,k);
        return 0;
    }

    int dl = nodesAtK(root->left,target,k);
    if(dl!=-1){
        if(dl+1 == k){
            cout<<root->data<<" ";
        }else{
            printSubtree(root->right,k-dl-2);
        }
        return 1+dl;
    }

    int dr = nodesAtK(root->right,target,k);
    if(dr!=-1){
        if(dr+1 == k){
            cout<<root->data<<" ";
        }else{
            printSubtree(root->left,k-dl-2);
        }
        return 1+dr;
    }

    return -1; // Element not found in left and right as well
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->left->left = new Node(5);
    root->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    nodesAtK(root,root->left,3);

    return 0;
}