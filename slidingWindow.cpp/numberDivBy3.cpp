#include<iostream>
#include<vector>

using namespace std;

void numberDivByThree(vector<int> arr, int k){
    pair<int,int> ans;
    int sum = 0;
    for(int i=0; i<k; i++){
        sum+=arr[i];
    }
    bool found = false;
    if(sum%3==0){
        ans = make_pair(0,k-1);
        found = true;
    }

    for(int j=k; j<arr.size(); j++){
        if(found){
            break;
        }
        sum += arr[j] - arr[j-k];
        if(sum%3==0){
            ans = make_pair(j-k+1,j);
            found = true;
        }
    }

    if(!found){
        cout<<"No such subarray exist.\n";
    }else{
        cout<<ans.first<<" "<<ans.second<<"\n";
    }
}

int main(){
    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k = 3;
    numberDivByThree(arr, k);
    return 0;
}