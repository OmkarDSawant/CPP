#include<iostream>
#include<unordered_map>

using namespace std;

void generatePermutations(int cs, string str, unordered_map<char,int> &mp, string asf){

    if( cs == str.length() ){
        cout<<asf<<"\n";
        return;
    }

    for(auto i : mp){
        if(i.second > 0){
           mp[i.first]--;
           generatePermutations(cs+1, str, mp, asf + i.first);
           mp[i.first]++;
        }
    }

}

int main(){

    string str;
    cin>>str;

    unordered_map<char, int> mp;

    for(int i=0; i<str.size(); i++){

        if( mp.find(str[i]) == mp.end() ){
            mp[str[i]] = 1;
        }else{
            mp[str[i]]++;
        }
    }

    cout<<"\n";
    generatePermutations(0, str, mp, "");

    return 0;
}