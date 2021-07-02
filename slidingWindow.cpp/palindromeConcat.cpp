#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
bool isPalindrome(int n){
    int temp = n, sum = 0;
    while(temp>0){
        sum = sum*10 + temp%10;
        temp = temp/10;
    }
    if(sum == n){
        return true;
    }else{
        return false;
    }
}
void subArray(vector<int> arr, int k){
    int num = 0;
    pair<int, int> ans;
    bool found = false;

    for(int i=0; i<k; i++){
        num = num*10 + arr[i];
    }

    if(isPalindrome(num)){
        ans = make_pair(0,k-1);
        found = true;
    }

    for(int i=k; i<arr.size(); i++){
        if(found){
            break;
        }
        num = ((num % (int)pow(10,k-1))*10) + arr[i];
        if(isPalindrome(num)){
            ans = make_pair(i-k+1,i);
            found = true;
        }
    }

    if(!found){
        cout<<"No such subarray exists.\n";
    }else{
        for(int i=ans.first; i<=ans.second; i++){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;
    subArray(arr,4);

    return 0;
}