#include<iostream>

using namespace std;

int powerLin(int &x, int n){
    if(n==0){
        return 1;
    }
    
    return x * powerLin(x,n-1);
}

int main(){
    int x,n;
    cin>>x>>n;

    cout<<powerLin(x,n);
    return 0;
}