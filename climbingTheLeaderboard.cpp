//This problem is a variation of climbing the leader problem. Here all players are inserted and then their rank is checked.
#include<iostream>
#include<bits/stdc++.h>
#include<vector>


using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int m;
    cin>>m;
    int b[m];
    
    int q=m;
    
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    
    vector<int> ans;

    int i=m-1;
    int j=0;
    int temp;

    while(i>=0 && j<n){
        if(b[i]>=a[j]){
            temp=b[i];
            ans.push_back(temp);
            i--;
        }else{
            temp=a[j];
            ans.push_back(temp);
            j++;
        }
    }
    
    while(i>=0){
        temp=b[i];
        ans.push_back(temp);
        i--;
    }
    while(j<n){
        temp=a[j];
        ans.push_back(temp);
        j++;
    }
    
    int fans[q];
    int lol=q;
    int count=1;
    for(int i=0;i<(m+n);i++){
        if(q>=0){
            if(ans[i]==b[q-1]){
                fans[q-1]=count;
                q--;
            }
            if(ans[i]!=ans[i+1]){
                count++;
            }
        }
    }
    for(int i=0;i<lol;i++){
        cout<<fans[i]<<"\n";
    }

    
    return 0;
}
