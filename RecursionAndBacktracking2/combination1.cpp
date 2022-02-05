#include<iostream>

using namespace std;

void combination(int cb, int tb, int esf, int te, string asf){

    if(cb>tb){
        if(esf == te){
            cout<<asf<<"\n";
        }

        return;
    }

    combination(cb+1, tb, esf, te, asf + "-");
    combination(cb+1, tb, esf+1, te, asf + "i");
}

int main(){

    int n,r;
    cin>>n>>r;

    combination(1, n, 0, r, "");

    return 0;
}