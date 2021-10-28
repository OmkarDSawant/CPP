#include<bits/stdc++.h>

using namespace std;

struct Node{
    int prime;
    int index;
    int val;
    

    Node(int p, int i, int v){
        prime = p;
        index = i; 
        val = v;
    }
};

// This struct implements overloading.
struct CompareValue{

    bool operator()(Node const& n1, Node const& n2){
        //works as min heap
        return n1.val > n2.val; 
    }
};

int main(){

    int k;
    cin>>k;

    int primes[k];
    for(int i=0; i<k; i++){
        cin>>primes[i];
    }

    int n;
    cin>>n;

    int dp[n+1];
    dp[1] = 1; //1st ugly number

    priority_queue<Node, vector<Node>, CompareValue> pq;

    for(int i=0; i<k; i++){
        //prime, index, value
        pq.push(Node(primes[i], 1, primes[i]));
    }
    
    for(int i=2; i<=n; i++){
        Node currentNode = pq.top();
        pq.pop();

        if(currentNode.val != dp[i-1]){

            dp[i] = currentNode.val;

            //prime, index, value
            pq.push(Node(currentNode.prime, currentNode.index + 1, currentNode.prime * dp[currentNode.index + 1]));
        }
    }

    
    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
    }

    return 0;
}