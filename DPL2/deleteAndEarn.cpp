//Sum boils down to maxSumOfNonAdjacentElements
#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> count((int)1e4+1, 0);

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int val:arr){
        count[val]++;
    }

    int inc = 0;
    int exc = 0;

    for(int i=0; i<count.size(); i++){
        int ni = exc + count[i] * i;
        int ne = max(inc,exc);

        inc = ni;
        exc = ne;
    }

    cout<<max(inc,exc);
    return 0;
}