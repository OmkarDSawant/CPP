#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    int n;cin>>n;
    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    unordered_map<int,int> initialPrefSumIndex;
    initialPrefSumIndex[0] = -1;

    int sum = 0;
    int len = -1;

    for(int i=0; i<n; i++){
        sum+=a[i];
        if(initialPrefSumIndex.find(sum) != initialPrefSumIndex.end()){
           unordered_map<int,int> :: iterator it;
           it = initialPrefSumIndex.find(sum);
           int temp = i - (it->second);

           len = max(len,temp);
        }else{
           initialPrefSumIndex[sum] = i;
        }
    }

    cout<<len;
    return 0;
}