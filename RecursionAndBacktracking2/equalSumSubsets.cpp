#include<iostream>
#include<vector>

using namespace std;

bool isEqual(vector<int> &subsetSum){
    for(int i = 0; i<subsetSum.size()-1; i++){
        if(subsetSum[i]!=subsetSum[i+1]){
            return false;
        }
    }

    return true;
}

void solution(int cur, int n, int k, vector<vector<int>> &subsets, int fs, vector<int> &subsetSum){

    if(cur>n){
        if(fs==k){
            if(isEqual(subsetSum)){
                for(vector<int> arr : subsets){
                    cout<<"[";
                    for(int ele : arr){
                        cout<<ele;
                    }
                    cout<<"]";
                }
                cout<<"\n";
                }
        }
        return;
    }

    for(int i=0; i<subsets.size(); i++){
        if(subsets[i].size()!=0){
            subsets[i].push_back(cur);
            subsetSum[i] += cur;
            solution(cur+1, n, k, subsets, fs, subsetSum);
            subsetSum[i] -= cur;
            subsets[i].erase(subsets[i].end()-1);
        }else{
            subsets[i].push_back(cur);
            subsetSum[i] += cur;
            solution(cur+1, n, k, subsets, fs+1, subsetSum);
            subsetSum[i] -= cur;
            subsets[i].erase(subsets[i].end()-1);
            break;
        }
    }
}

int main(){

    int n,k;

    cin>>n>>k;

    vector<vector<int>> subsets(k);
    vector<int> subsetSum(k);

    //You can also add n numbers and check whether it leaves any remainder after dividing it with k. if yes then solution does not exist.

    solution(1, n, k, subsets, 0, subsetSum);

    return 0;
}