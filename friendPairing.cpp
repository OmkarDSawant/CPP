#include<iostream>

using namespace std;
int friendPair(int n){

    if(n==0 || n==1 || n==2)
        return n;

    return friendPair(n-1) + friendPair(n-2)*(n-1);
}
int main(){
    cout<<friendPair(4);
    return 0;
}