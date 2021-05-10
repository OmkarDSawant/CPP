#include<iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned long int nextPowerOf2(unsigned long int n)
{
    unsigned long int count = 0;
     
    // First n in the below condition
    // is for the case where n is 0
    if (n == 0)
        return 1;
     
    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }
     
    return 1 << count;
}

int main(){
    
    int n;
    cin>>n;
    
    unsigned long int a[n],b[n],result[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    
    
    for(int i=0; i<n; i++){
        result[i] = a[i] & ~(nextPowerOf2(a[i]^b[i])-1);
    }
    
    
       
    for(int i=0;i<n;i++){
        cout<<result[i]<<"\n";
    }
    return 0;
}
