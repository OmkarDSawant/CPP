#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n,k,num;
    short int count = 0;
    cin>>n>>k;
    while (n>0)
    {
        cin>>num;
        if(num%k==0)
            count++;
        
        n--;
    }
    cout<<count;
    return 0;
}