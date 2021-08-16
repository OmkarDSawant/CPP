#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;

    int prices[n];

    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    int lstd = INT_MAX;
    int op = 0; //Overall max profit
    int cp = 0; //Current profit

    for(int i=0; i<n; i++){
        if(prices[i] < lstd){
            lstd = prices[i];
        }
        cp = prices[i] - lstd;
        if(cp>op){
            op = cp;
        }
    }

    cout<<op;
    return 0;
}