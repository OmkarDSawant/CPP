//Paint N fences with K colors such that no more than two consecutive fences should be painted with the same color.

#include<iostream>

using namespace std;

int main(){

    int n; cin>>n;
    int k; cin>>k;

    //For 2 fences
    int same = k * 1;
    int diff = k * (k-1);

    int total = same + diff;

    for(int i=3; i<=n; i++){
        same = diff * 1;
        diff = total * (k-1);
        total = same + diff;
    }

    cout<<total;
    return 0;
}