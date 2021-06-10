#include<iostream>

using namespace std;

int main(){

    int n; cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int next = 1, current = 0, temp = 0, count = 0;

    while(current!=n-1){

        if(a[current]<=a[next]){
            current=next;
            next=current+1;
            count+=temp;
            temp=0;
        }else{
            temp=temp+(a[current]-a[next]);
            next++;
        }

        if(next==n && current!=n-1){
            current++;
            next=current+1;
            temp=0;
        }
    }

    cout<<count;
    return 0;
}