#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int lcm (int a, int b){
    if((__gcd(a,b))==1){
        return a*b;
    }else{
        return (a*b)/(__gcd(a,b));
    }
}
int main(){
    
    int n,m;
    cin>>n>>m;
    
    int a[n],b[m];
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    
    int alcm=a[0];
    if(n!=1){
        for(int i=0;i<n-1;i++){
            alcm=lcm(alcm,lcm(a[i],a[i+1]));
        }
    }
    
    int bgcd=b[0];
    if(m!=1){
        for(int i=0;i<m-1;i++){
            bgcd = __gcd(bgcd,__gcd(b[i],b[i+1]));
        }
    }
    
    int count = 0;
    int i=1;
    while((alcm*i)<=bgcd){
        if((bgcd%(alcm*i))==0){
           count++; 
        }
        i++;
    }
    
    cout<<count;
    
    return 0;
}
