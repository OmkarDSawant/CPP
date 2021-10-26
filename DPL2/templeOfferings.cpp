#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int height[n];

    for(int i=0; i<n; i++){
        cin>>height[i];
    }

    int larr[n];
    larr[0] = 1;

    for(int i=1; i<n; i++){
        if(height[i]>height[i-1]){
            larr[i] = larr[i-1] + 1;
        }else{
            larr[i] = 1;
        }
    }

    int rarr[n];
    rarr[n-1] = 1;

    for(int i=n-2; i>=0; i--){
        if(height[i]>height[i+1]){
            rarr[i] = rarr[i+1] + 1;
        }else{
            rarr[i] = 1;
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        ans += max(larr[i], rarr[i]);
    }

    cout<<ans;

    return 0;
}