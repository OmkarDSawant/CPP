#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main(){
    int n;cin>>n;
    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    unordered_map<int,int> prefFreq;

    prefFreq[0] = 1;

    int sum = 0;
    int cnt = 0;

    for(int i=0; i<n; i++){
        sum+=a[i];

        if(prefFreq.find(sum)!=prefFreq.end()){
            unordered_map<int,int> :: iterator it;
            it=prefFreq.find(sum);
            cnt += (it->second); //we add prev frequency
            (it->second)++; // udpate the frequency
        }else{
            prefFreq[sum] = 1;
        }
    }

    cout<<"Number of subarrays : "<<cnt;

    return 0;
}