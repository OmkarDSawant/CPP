//Permutation using combination

#include<iostream>
#include<vector>

using namespace std;

void permutation(int cb, int tb, vector<bool> &items, string asf, int ssf, int ts){

    if(cb>tb){
        if(ssf == ts){
            cout<<asf<<"\n";
        }
        return;
    }

    for(int i=0; i<items.size(); i++){
        if(!items[i]){
            items[i] = true;
            permutation(cb+1, tb, items, asf+to_string(i+1), ssf+1, ts);
            items[i] = false;
        }
    }

    permutation(cb+1, tb, items, asf+to_string(0), ssf, ts);
}

int main(){

    int n,r;
    cin>>n>>r;

    vector<bool> items(r,false);

    permutation(1, n, items, "", 0, r);

    return 0;
}