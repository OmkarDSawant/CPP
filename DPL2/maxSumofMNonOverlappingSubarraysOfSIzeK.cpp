#include<iostream>
#include<vector>

using namespace std;

int solution(vector<int> &pSumK, int m, int k, int idx){

    if(idx >= pSumK.size() || m == 0){
        return 0;
    }


    int include = pSumK[idx] + solution(pSumK, m-1, k, idx+k);
    int exclude = 0 + solution(pSumK, m, k, idx+1);

    return max(include, exclude);
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int m;
    cin>>m;

    int k;
    cin>>k;

    vector<int> pSumK(n);
    int window = 0;

    for(int i=n-1; i>=0; i--){
        if(i+k>=n){
            window += arr[i];
            pSumK[i] = window;
        }else{
            window += arr[i] - arr[i+k];
            pSumK[i] = window;
        }
    }

    cout<<solution(pSumK, m, k, 0);

    return 0;
}