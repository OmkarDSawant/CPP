#include<iostream>

using namespace std;

int solution(int n, int k){
    //Only one element is present.
    if(n==0){
        return 0;
    }

    int x = solution(n-1,k);
    return (x+k)%n; //IMP
}

int main(){

    int n,k;
    cin>>n>>k;

    cout<<solution(n,k);

    return 0;
}