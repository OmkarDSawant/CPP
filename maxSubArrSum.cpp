#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int maxSum = INT32_MIN;
    int currentSum = 0;

    for(int i=0;i<n;i++){
        currentSum+=a[i];
        if(currentSum<0){
            currentSum=0;
        }
        maxSum = max(currentSum,maxSum);
    }
    cout<<maxSum;
    return 0;
}