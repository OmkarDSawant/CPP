#include<iostream>
#include<vector>

using namespace std;

void solution(int cur, int n, int k, vector<vector<int>> &subsets, int fs){

    if(cur>n){
        if(fs==k){
            for(vector<int> arr : subsets){
                cout<<"[";
                for(int ele : arr){
                    cout<<ele;
                }
                cout<<"]";
            }
            cout<<"\n";
        }
        return;
    }

    for(int i=0; i<subsets.size(); i++){
        if(subsets[i].size()!=0){
            subsets[i].push_back(cur);
            solution(cur+1, n, k, subsets, fs);
            subsets[i].erase(subsets[i].end()-1);
        }else{
            subsets[i].push_back(cur);
            solution(cur+1, n, k, subsets, fs+1);
            subsets[i].erase(subsets[i].end()-1);
            break;
        }
    }
}

int main(){

    int n,k;

    cin>>n>>k;

    vector<vector<int>> subsets(k);

    solution(1,n,k,subsets,0);

    return 0;
}