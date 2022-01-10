#include<iostream>
#include<vector>

using namespace std;

vector<int> merge2SortedArrays(vector<int> &a, vector<int> &b){

    vector<int> res;
    int fa = 0;
    int sa = 0;

    while(fa<a.size() && sa<b.size()){
        if(a[fa]<b[sa]){
            res.push_back(a[fa]);
            fa++;
        }else{
            res.push_back(b[sa]);
            sa++;
        }
    }

    while(fa<a.size()){
        res.push_back(a[fa]);
        fa++;
    }

    while(sa<b.size()){
        res.push_back(b[sa]);
        sa++;
    }

    return res;
}

vector<int> merge(vector<int> arr, int start, int end){

    if(start==end){
        vector<int> res;
        res.push_back(arr[start]);
        return res;
    }

    while(start<end){
        vector<int> fh = merge(arr, start, (start+end)/2);
        vector<int> sh = merge( arr, ((start+end)/2)+1 , end);

        vector<int> ca = merge2SortedArrays(fh,sh);
        return ca;
    }
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int lo = 0;
    int high = n-1;
    int mid = (lo+high)/2;

    vector<int> a = merge(arr, lo, mid);
    vector<int> b = merge(arr, mid+1, high);

    vector<int> res = merge2SortedArrays(a,b);

    for(int i=0; i<n; i++){
        cout<<res[i]<<" ";
    }

    return 0;
}