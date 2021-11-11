#include<iostream>
#include<vector>

using namespace std;

int main(){

    string str;
    cin>>str;

    vector<int> hmap(26,0);

    int dpl[str.length()];
    dpl[0] = 1;
    hmap[str[0]-'a'] = 1;

    for(int i=1; i<str.length(); i++){
        if(hmap[str[i] - 'a'] == 0){
            dpl[i] = dpl[i-1] + 1;
        }else{
            dpl[i] = dpl[i-1];
        }
        hmap[str[i] - 'a']++;
    }

    fill(hmap.begin(), hmap.end(), 0);

    int dpr[str.length()];
    dpr[str.length()-1] = 1;
    hmap[str[str.length()-1]-'a'] = 1;

    for(int i=str.length()-2; i>=0; i--){
        if(hmap[str[i] - 'a'] == 0){
            dpr[i] = dpr[i+1] + 1;
        }else{
            dpr[i] = dpr[i+1];
        }
        hmap[str[i] - 'a']++;
    }

    int count = 0;
    for(int i=0; i<str.length()-2; i++){
        if(dpl[i] == dpr[i+1]){
            count++;
        }
    }

    cout<<count;

    return 0;
}