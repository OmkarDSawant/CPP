#include<iostream>

using namespace std;

void solution(int n, int val){

    if(val>n){
        return;
    }
    
    cout<<val<<"\n";

    for(int i=0; i<10; i++){
        solution(n, (val*10)+i );
    }
}

int main(){

    int n;
    cin>>n;

    for(int i=1; i<10; i++){
        solution(n, i);
    }

    return 0;
}