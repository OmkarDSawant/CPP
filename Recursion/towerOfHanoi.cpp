#include<iostream>

using namespace std;

void TOI(int n, int src, int dest, int helper){
    if(n==0){
        return;
    }
    
    TOI(n-1,src,helper,dest);
    cout<<n<<"["<<src<<"->"<<dest<<"]\n";
    TOI(n-1,helper,dest,src);
}

int main(){
    int n,t1,t2,t3;
    cin>>n>>t1>>t2>>t3;

    TOI(n,t1,t2,t3);

    return 0;
}