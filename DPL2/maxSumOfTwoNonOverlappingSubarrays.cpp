#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int x,y;
    cin>>x>>y;

    //Case 1
    vector<int> dpl(n,0);
    vector<int> dpr(n,0);

    int window = 0;
    for(int i=0; i<n; i++){
        if(i<x){
            window += arr[i];
            dpl[i] = window;
        }else{
            window += arr[i] - arr[i-x]; // Don't forget to update window
            dpl[i] = max(window, dpl[i-1]);
        }
    }

    window = 0;
    for(int i=n-1; i>=0; i--){
        if(i+y >= n){
            window += arr[i];
            dpr[i] = window; 
        }else{
            window += arr[i] - arr[i+y];
            dpr[i] = max(window, dpr[i+1]);
        }
    }

    int ans = 0;
    for(int i=x-1; i<n-y; i++){
        ans = max(ans, dpl[i]+dpr[i+1]);
    }
    
    //Case 2
    fill(dpl.begin(), dpl.end(), 0);
    fill(dpr.begin(), dpr.end(), 0);

    window = 0;
    for(int i=0; i<n; i++){
        if(i<y){
            window +=arr[i];
            dpl[i] = window;
        }else{
            dpl[i] = max(window + arr[i] - arr[i-y] ,dpl[i-1]);
        }
    }

    window = 0;
    for(int i=n-1; i>=0; i--){
        if(i+x >= n){
            window += arr[i];
            dpr[i] = window; 
        }else{
            dpr[i] = max(window + arr[i] - arr[i+x] ,dpr[i+1]);
        }
    }

    for(int i = y-1; i<n-x; i++){
        if(dpl[i]+dpr[i+1] > ans){
            ans = dpl[i]+dpr[i+1];
        }
    }

    cout<<ans;

    return 0;
}