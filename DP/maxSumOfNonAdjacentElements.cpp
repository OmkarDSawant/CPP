//Give the maximum sum of non adjacent elements in an array.
//Works for both +ve and -ve numbers.
//IMP sum

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int inc = arr[0];
    int exc = 0;

    for(int i=1; i<n; i++){
        int ninc = exc + arr[i];
        int nexc = max(inc,exc); //Restricting to select only the max element as future branching is same for both.

        inc = ninc;
        exc = nexc;
    }

    cout<<max(inc,exc);

    return 0;
}