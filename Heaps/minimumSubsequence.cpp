//Length of minimum subsequence whose sum is greater than k
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;

    int a[n];
    priority_queue<int, vector<int>> maxHeap;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n; i++){
        maxHeap.push(a[i]);
    }

    int sum = 0;
    int cnt = 0;
    while(!maxHeap.empty()){
        sum+=maxHeap.top();
        maxHeap.pop();
        cnt++;

        if(sum >= k){
            break;
        }
    }

    if(sum<k){
        cout<<"Subsequence doesn't exist.\n";
    }else{
        cout<<"Minimum subsequence length is : "<<cnt;
    }
    return 0;
}