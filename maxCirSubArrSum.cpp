#include<iostream>

using namespace std;

int kdane(int a[],int n){
    int currSum=0;
    int maxSum = INT32_MIN;

    for(int i=0;i<n;i++){
        currSum+=a[i];
        if(currSum<0){
            currSum=0;
        }
        maxSum = max(currSum,maxSum);
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int wrapSum;
    int nonWrapSum;

    wrapSum = kdane(a,n);

    int totSum=0;
    for(int i=0;i<n;i++){
        totSum+=a[i];
        a[i]=-a[i];
    }

    nonWrapSum = totSum + kdane(a,n);

    int maxxy = max(wrapSum,nonWrapSum);
    cout<<maxxy;

    return 0;
}