#include<iostream>
#include<vector>
#include <cstdlib>

using namespace std;

int minDiff = INT_MAX;
string ans = "";

void solution(vector<int> &arr, vector<int> &set1, vector<int> &set2, int vidx, int ss1, int ss2){

    if(vidx == arr.size()){
        if(abs(ss1 - ss2) < minDiff){
            minDiff = abs(ss1 - ss2);
            ans.clear();

            for(int el : set1){
                ans += to_string(el);
            }

            ans+= " | ";

            for(int el : set2){
                ans += to_string(el);
            }
        }
    }

    if( set1.size() < (arr.size() + 1)/2 ){
        set1.push_back(arr[vidx]);
        solution(arr, set1, set2, vidx+1, ss1 + arr[vidx], ss2);
        set1.erase(set1.end()-1);
    }
    
    if( set2.size() < (arr.size() + 1)/2 ){
        set2.push_back(arr[vidx]);
        solution(arr, set1, set2, vidx+1, ss1, ss2 + arr[vidx]);
        set2.erase(set2.end()-1);
    }

}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> set1, set2;

    solution(arr, set1, set2, 0, 0, 0);

    cout<<ans;

    return 0;
}