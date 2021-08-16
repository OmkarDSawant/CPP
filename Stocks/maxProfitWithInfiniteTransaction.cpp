//Only condition: No two transactions must be overlapping.

#include<iostream>

using namespace std;

int main(){
    int n; cin>>n;

    int prices[n];

    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    int profit = 0;
    int b = 0;
    int s = 0;

    for(int i=1; i<n; i++){
        if(prices[i] >= prices[i-1]){
            s++;
        }else{
            profit += prices[s] - prices[b];
            b = s = i; 
        }
    }
    profit += prices[s] - prices[b];

    cout<<profit;

    return 0;
}