#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int psa[n];
    psa[0] = arr[0];
    for(int i=1; i<n; i++){
        psa[i] = psa[i-1] + arr[i];
    }

    int dpl[n];
    int window = 0;
    for(int i=0; i<n; i++){
        if(i<k){
            window += arr[i];
            dpl[i] = window;
        }else{
            window += arr[i] - arr[i-k];
            dpl[i] = max(dpl[i-1], window);
        }
    }

    window = 0;
    int dpr[n];

    for(int i=n-1; i>=0; i--){
        if(i+k >= n){
            window += arr[i];
            dpr[i] = window;
        }else{
            window += arr[i] - arr[i+k];
            dpr[i] = max(dpr[i+1], window);
        }
    }

    //indexes
    int msai = -1;
    int lsai = -1;
    int rsai = -1;

    

    //max left, right and middle values
    int lvalue;
    int rvalue;
    int middle = 0;
    
    int maxSum = 0;

    for(int i=2*k-1; i<n-k; i++){
        middle = psa[i] - psa[i-k];

        if(dpl[i-k] + middle + dpr[i+1] > maxSum){
            maxSum = dpl[i-k] + middle + dpr[i+1];

            msai = i-(k-1);
            lvalue = dpl[i-k];
            rvalue = dpr[i+1];
        }
    }

    cout<< maxSum<<"\n";
   

    int temp = 0;
    for(int i=k-1; i<msai; i++){
        temp = psa[i] - (i-k<0? 0: psa[i-k]);

        if(temp == lvalue){
            lsai = i-(k-1);
            break;
        }
    }
    cout<<lsai<<" ";
    cout<<msai<<" ";

    for(int i = (msai+(2*k)-1); i<n; i++){
        if(psa[i] - psa[i-k] == rvalue){
            rsai = i;
            break;
        }
    }

    cout<<rsai;


    return 0;
}