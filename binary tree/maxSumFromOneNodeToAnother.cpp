#include<bits/stdc++.h>

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

int maxPathSumUtil(Node* root, int &ans){

    if(root==NULL){
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data , root->data + left + right), max(root->data + left, root->data + right));

    ans = max(ans,nodeMax);
    
    //Note: While returning we can't consider the entire subtree's sum as it is not a single path.
    return max(max(root->data,root->data+left), root->data + right);

}

int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main(){

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);


    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<maxPathSum(root);
    return 0;
}