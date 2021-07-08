#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void verticalOrder(map <int, vector<int>> &vOrder, int hdis, Node *root){
    if(root == NULL){
        return;
    }
    vOrder[hdis].push_back(root->data);

    verticalOrder(vOrder, hdis-1, root->left);
    verticalOrder(vOrder, hdis+1, root->right);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(9);
    root->left->left = new Node(11);
    root->left->right = new Node(15);
    root->right->left = new Node(14);
    root->right->right = new Node(19);

    map <int, vector<int>> vOrder;
    int hdis = 0;

    verticalOrder(vOrder, hdis, root);

    map <int, vector<int>> :: iterator it;

    for(it=vOrder.begin(); it!=vOrder.end(); it++){
        cout<<it->first<<" -> ";
        for(int i=0; i<(it->second).size(); i++){
            cout<<(it->second)[i]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}