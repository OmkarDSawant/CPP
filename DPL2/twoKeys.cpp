#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    if(n==0 || n==1){
        cout<<0<<"\n";
    }

    int ans = 0;
    for(int i=2; i*i<=n;){
        if(n%i==0){
            ans+=i;
            n/=i;
        }else{
            i++;
        }
    }

    if(n!=1){
        ans+=n;
    }

    cout<<ans<<"\n";

    return 0;
}