//Combination using permutation

#include<iostream>
#include<vector>

using namespace std;

void combination(int li, int ti, int cb, int tb, string asf, int ssf){

    if(cb>tb){
        if(ssf == ti){
            cout<<asf<<"\n";
        }
        return;
    }

    for(int i = li+1; i<ti; i++){
        combination(i, ti, cb+1, tb, asf+"i", ssf+1);
    }
    combination(li, ti, cb+1, tb, asf+"-", ssf);
}

int main(){

    int n,r;
    cin>>n>>r;

    combination(-1, r, 1, n, "", 0);

    return 0;
}