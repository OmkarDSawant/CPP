#include<iostream>
#include<stack>

using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigzagTraversal(Node *root){
    if(root == NULL){
        return;
    }

    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);

    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            
            cout<<temp->data<<" ";

            if(leftToRight){
                if(temp->left){
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right);
                }
            }else{
                if(temp->right){
                    nextLevel.push(temp->right);
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }

        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel,nextLevel);
        }
    }
}

int main(){

    Node* root = new Node(14);
    root->left = new Node(6);
    root->right = new Node(21);
    root->left->right = new Node(8);
    root->right->right = new Node(27);

    zigzagTraversal(root);

    return 0;
}