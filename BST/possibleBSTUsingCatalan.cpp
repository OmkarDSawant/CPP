#include<iostream>
#include<vector>

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

//This function will return vector of Node *s containing root of all possible BSTs.
vector<Node*> constructBST(int start, int end){
    vector<Node*> trees;

    if(start>end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++){ //Here i is taken as Node to be built.
        vector<Node*> leftSubtree = constructBST(start,i-1);
        vector<Node*> rightSubtree = constructBST(i+1,end);

        for(int j=0;j<leftSubtree.size();j++){
            Node* left = leftSubtree[j];

            for(int k=0;k<rightSubtree.size();k++){
                Node* right = rightSubtree[k];

                Node* node = new Node(i);
                node->left = left;
                node->right = right;

                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    vector<Node*> totalTrees = constructBST(1,3);

    for(int i=0;i<totalTrees.size();i++){
        cout<<i+1<<": ";
        preorder(totalTrees[i]);
        cout<<endl;
    }

    return 0;
}