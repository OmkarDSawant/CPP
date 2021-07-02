#include<iostream>

using namespace std;

int minSize(int arr[], int start, int end, int n, int x){
    int sum = 0;
    int minLength = n+1;
    while(end<n){
        while(sum<=x && end<n){
            sum+=arr[end++];
        }

        while(sum>x && start<n){
            if( (end-start) < minLength ){
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;
    //initially start and end at 0.
    cout<<minSize(arr, 0, 0, n, x);
    return 0;
}