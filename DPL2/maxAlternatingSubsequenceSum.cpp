#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int endEven = arr[0];
    int endOdd = 0;

    for(int i=1; i<n; i++){
        endEven = max(endEven, endOdd + arr[i]);
        endOdd = max(endOdd, endEven - arr[i]);
    }

    cout<<endEven;

    return 0;
}