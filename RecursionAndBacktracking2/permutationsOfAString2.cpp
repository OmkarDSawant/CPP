#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

void generatePermutations(int ci, string str, vector<char> &spots, unordered_map<char, int> &mp){

    if(ci==str.size()){
        for(auto i : spots){
            cout<<i;
        }
        cout<<"\n";
    
        return;
    }

    int lo = mp[str[ci]];

    for(int i = lo+1; i< spots.size(); i++){
        if(spots[i]=='*'){
            spots[i] = str[ci];
            mp[str[ci]] = i;
            generatePermutations(ci+1, str, spots, mp);
            mp[str[ci]] = lo;
            spots[i] = '*';
        }
    }
}

int main(){

    string str;
    cin>>str;

    unordered_map<char, int> mp;

    for(int i=0; i<str.size(); i++){
        if( mp.find(str[i]) == mp.end() ){
            mp[str[i]] = -1;
        }
    }

    vector<char> spots(str.length(), '*');

    cout<<"\n";
    generatePermutations(0, str, spots, mp);

    return 0;
}