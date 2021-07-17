#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a,a+n);

    long long min=0, max=0;
    for(int i=0; i<(n/2); i++){
        max += (a[i+(n/2)] - a[i]);
        min += (a[2*i+1] - a[2*i]);
    }

    cout<<"Max: "<<max<<"\n";
    cout<<"Min: "<<min<<"\n";
    
    return 0;
}