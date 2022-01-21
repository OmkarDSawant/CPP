#include<iostream>
#include<vector>

using namespace std;

void collectGold(vector<vector<int>> &arr, vector<vector<bool>> &visited, vector<int> &bag, int i, int j){

    if(i<0 || j<0 || i==arr.size() || j==arr[0].size() || arr[i][j] == 0 || visited[i][j] == true){
        return;
    }

    bag.push_back(arr[i][j]);
    visited[i][j] = true;

    //4 directions
    collectGold(arr, visited, bag, i-1, j); //n
    collectGold(arr, visited, bag, i, j+1); //e
    collectGold(arr, visited, bag, i, j-1); //w
    collectGold(arr, visited, bag, i+1, j); //s
}

int main(){

    int row,col;
    cin>>row>>col;

    vector<vector<int>> arr(row, vector<int>(col));
    vector<vector<bool>> visited(row, vector<bool>(col,false));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    int maxSum = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            vector<int> bag;
            collectGold(arr, visited, bag, i, j);

            int sum = 0;
            for(int val : bag){
                sum+=val;
            }

            if(sum>maxSum){
                maxSum = sum;
            }

        }
    }

    cout<<maxSum;
    return 0;
}