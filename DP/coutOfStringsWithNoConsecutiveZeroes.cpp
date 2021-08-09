//Count of binary strings that can be formed of length N with no consecutive zeroes.

#include<iostream>

using namespace std;

int main(){
    int n; cin>>n;

    int odp0 = 1; //Binary string that end with 0 of length 1;
    int odp1 = 1; ////Binary string that end with 1 of length 1; 

    for(int i=2; i<=n; i++){
        int ndp0 = odp1;
        int ndp1 = odp0 + odp1;

        odp0 = ndp0;
        odp1 = ndp1; 
    }

    cout<<odp0+odp1;

    return 0;
}