#include<iostream>

using namespace std;

void printDecrease(int n){
    if(n==0){
        return;
    }
    cout<<n<<"\n";
    printDecrease(n-1);
}

int main(){
    int n;
    cin>>n;

    printDecrease(n);
    return 0;
}