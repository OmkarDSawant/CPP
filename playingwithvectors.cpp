#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> a(2,50);
    a.push_back(89);

    for(auto element : a){
        cout<<element<<"\n";
    }

    a.resize(2);
    for(auto element : a){
        cout<<element<<"\n";
    }

    
    return 0;
}