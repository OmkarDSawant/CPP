#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int perfectNumber(int n){
    int sum = 1;
    //V.IMP
    for(int i=2; i<sqrt(n); i++){
        if(n%i==0){
            if(i == n/i){
                sum+=i;
            }else{
                sum+= i + n/i;
            }
        }
    }

    if(n == sum){
        return 1;
    }
    return 0;
}

void maxSize(vector<int> arr, int k){
    for(int i=0; i<arr.size(); i++){
        arr[i] = perfectNumber(arr[i]);
    }

    int res = 0;

    for(int i=0; i<k; i++){
        res+=arr[i];
    }
    int sum = res;

    for(int i=k;i<arr.size();i++){
        sum+= arr[i] - arr[i-k];
        res = max(sum,res);
    }

    cout<<res;
}

int main(){
    vector<int> arr = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4;
    maxSize(arr,k);
    return 0;
}