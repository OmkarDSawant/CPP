#include<iostream>

using namespace std;

void PIP(int n){
    if(n==0){
        return;
    }
    
    cout<<"Pre "<<n<<"\n";
    PIP(n-1);
    cout<<"In "<<n<<"\n";
    PIP(n-1);
    cout<<"Post "<<n<<"\n";
}

int main(){
    int n;
    cin>>n;

    PIP(n);

    return 0;
}