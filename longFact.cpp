#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n; //Input from user
    cin>>n;
    
    int q=2; // e.g 5! = 2*3*4*5 thus 2 is the starting number.
    
    int arr[100000] = {0};
    
    arr[0]=1; // any number multiplied with 1 is that number.
    
    int len = 1; // to keep track of length
    
    int index = 0;
    
    int num = 0; // for the next place to the left.
    
    while(q<=n){
        
        index=0; // For every value of q multiply with all indexes.
        while(index<len){
            arr[index] = arr[index]*q;
            arr[index] += num; 
            num = arr[index]/10;
            arr[index]=arr[index]%10;
            index++;
        }
        
        while(num!=0){
            arr[len] = num%10;
            num = num/10;
            len++;
        }
        
        q++;
    }
    while(len--){
        cout<<arr[len];
    }
    
    return 0;
}