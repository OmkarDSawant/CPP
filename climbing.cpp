#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);

    for(auto &i : a){
        cin>>i.first;
    }
    
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    
    int count=1;
    for(int i=0;i<n-1;i++){
        a[i].second=count;
        if((a[i].first)!=a[i+1].first){  
            count++;
        }
    }
    a[n-1].second=count;
    
    int flag;
    for(int i=0;i<m;i++){
        flag=0;
        for(int j=0;j<a.size();j++){
            if(flag==1){
                a[j].second++;
            }else if( (b[i]>=a[j].first) && (flag==0) ){
                a.insert (a.begin()+j,make_pair(b[i],a[j].second));
                cout<<a[j].second<<"\n";
                flag=1;
            }else{
                if( j==(a.size()-1) && (flag==0) ){
                    a.insert (a.begin()+j+1,make_pair(b[i],a[j].second));
                    cout<<a[j].second+1<<"\n";
                    flag=1;
                }
            }
        }
    }
    return 0;
}