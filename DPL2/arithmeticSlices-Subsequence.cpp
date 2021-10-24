#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    unordered_map<int,int> mp[n];
    int ans = 0;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int cd = arr[i]-arr[j]; //Key
            int apsEndingJ;
            int apsEndingI;

            if(mp[j].find(cd) == mp[j].end()){
                apsEndingJ = 0;
            }else{
                apsEndingJ = mp[j][cd];
            }

            if(mp[i].find(cd) == mp[i].end()){
                apsEndingI = 0;
            }else{
                apsEndingI = mp[i][cd];
            }

            ans += apsEndingJ;

            mp[i][cd] = apsEndingJ + apsEndingI + 1;
        }
    }


    cout<<ans;
    return 0;
}