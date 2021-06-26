#include<iostream>
#include<climits>

using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Info{
    int size; // current size
    int max; // current maximum
    int min; // current minimum
    int ans; // largest BST size yet
    bool isBST; // whether current node satisfies the conditions.
};

Info largestBSTinBT(Node* root){
    if(root == NULL){
        return {0,INT_MIN,INT_MAX,0,true}; // implicitly typecasted.
    }

    if(root->left == NULL && root->right == NULL){
        return {1,root->data,root->data,1,true};
    }

    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);

    Info curr;

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        //We have to calculate curr.min and curr.max only when left.isBST and right.isBST are true.
        curr.size = (1 + leftInfo.size + rightInfo.size);
        curr.min = min(leftInfo.min,min(rightInfo.min,root->data)); 
        curr.max = max(rightInfo.max,max(leftInfo.max,root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }
    curr.ans = max(leftInfo.ans,rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(17);

    cout<<largestBSTinBT(root).ans;
    return 0;
}