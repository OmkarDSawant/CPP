#include<iostream>

using namespace std;

int fact(int n){
    if(n==1 || n==0){ //End condition
        return 1;
    }
    return n* fact(n-1); //Logic
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}