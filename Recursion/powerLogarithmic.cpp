#include<iostream>

using namespace std;

int powerLog(int &x, int n){

    if(n==0){
        return 1;
    }

    int xb2 = powerLog(x,n/2);

    if(n%2 == 0){
        return xb2 * xb2;
    }else{
        return xb2 * xb2 * x;
    }

}

int main(){
    int x,n;
    cin>>x>>n;

    cout<<powerLog(x,n);
    return 0;
}