#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<vector<int>> arr(2);

    for(vector<int> a : arr){
        int ele;
        cin>>ele;
        a.push_back(ele);
    }

    for(auto ik : arr){
        for(auto i : ik){
            cout<<i;
        }
    }

    return 0;
}