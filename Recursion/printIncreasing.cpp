#include<iostream>

using namespace std;

void printIncrease(int n){
    if(n==0){
        return;
    }

    printIncrease(n-1);
    cout<<n<<"\n";
}

int main(){
    int n;
    cin>>n;

    printIncrease(n);

    return 0;
}