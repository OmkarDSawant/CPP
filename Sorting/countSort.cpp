#include<iostream>
#include<vector>

using namespace std;

void countS(int *arr, int mini, int maxi, int n){

    int range = maxi-mini+1;
    vector<int> farr(range,0);

    for(int i=0; i<n; i++){
        farr[arr[i]-mini]++;
    }

    //Prefix sum array
    for(int i=1; i<range; i++){
        farr[i] += farr[i-1];
    }


    int res[n];

    //Step to ensure stable sorting
    for(int i=n-1; i>=0; i--){
        int val = arr[i];
        int idx = farr[val-mini];
        res[idx-1] = val;
        farr[val-mini]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = res[i];
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int maxi = INT_MIN;
    int mini = INT_MAX;

    for(int i=0; i<n; i++){
        if(mini>arr[i]){
            mini = arr[i];
        }

        if(maxi<arr[i]){
            maxi = arr[i];
        }
    }

    countS(arr, mini, maxi, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}