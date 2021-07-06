#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int k; //Number of arrays.
    cin>>k;

    vector<vector<int>> a(k); //2D vector

    for(int i=0; i<k; i++){
        int size;
        cin>>size;

        a[i] = vector<int>(size);

        for(int j=0;j<size;j++){
            cin>>a[i][j];
        }
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    for(int i=0; i<k; i++){
        minHeap.push({a[i][0],i}); //Push first element of each array along with array number.
    }

    vector<int> idx(k,0); //Indicates the max index value currently present of each array in minHeap
    vector<int> ans; //Stores merged sorted array.
    while(!minHeap.empty()){
        pair<int,int> temp = minHeap.top();
        minHeap.pop();

        ans.push_back(temp.first);

        if(idx[temp.second]+1 < a[temp.second].size()){
            minHeap.push({a[temp.second][idx[temp.second]+1],temp.second});
        }
        idx[temp.second] +=1;
    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}