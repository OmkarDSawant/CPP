#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

bool isPossible(int arr[], int n, int m, int mini){
    int student = 1, sum = 0;

    for(int i=0; i<n; i++){
        if(arr[i] > mini){
            return false;
        }
        else if(sum+arr[i] > mini){
            sum = arr[i];
            student++;

            if(student>m){
                return false;
            }
        }else{
            sum += arr[i];
        }
    }
    return true;
}

int minPages(int arr[], int n, int m){
    int first = 0; //minimum pages that can be allocated.
    int last = 0; //maximum pages that can be allocated.
    int ans = INT_MAX;

    for(int i=0; i<n; i++){
        last += arr[i];
    }

    while(first<=last){
        int mini = (first+last)/2;

        if(isPossible(arr,n,m,mini)){
            ans = min(ans,mini);
            last = mini-1;
        }else{
            first = mini+1;
        }
    }

    return ans;
}

int main(){
    int arr[] = {12,34,67,90};
    int m = 2;
    int n = 4;

    cout<<minPages(arr,n,m);
    return 0;
}