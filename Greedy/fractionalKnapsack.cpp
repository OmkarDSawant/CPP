#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;
    }

    int weight;
    cin>>weight;

    sort(a.begin(),a.end(), [&](pair<int,int> &it1, pair<int,int> &it2){
        double vw1 = (double) it1.first/it1.second;
        double vw2 = (double) it2.first/it2.second;

        return vw1>vw2;
    });

    int ans = 0;

    for(int i=0; i<n; i++){
        if(weight>=a[i].second){
            ans += a[i].first;
            weight -= a[i].second;
            continue;
        }

        double vw = (double)a[i].first/a[i].second;
        ans += vw * weight;
        weight = 0;
        break;
    }

    cout<<ans;

    return 0;
}