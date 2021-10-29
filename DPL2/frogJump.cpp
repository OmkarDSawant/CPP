#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool solution(int *stones, int n){

    unordered_map<int, unordered_set<int>> mp;

    for(int i=0; i<n; i++){
        mp[stones[i]]; //Inserting keys
    }

    mp[stones[0]].insert(1); //Default

    for(int i=0; i<n; i++){

        int currentStone = stones[i];
        unordered_set<int> jumps = mp[currentStone];

        for(int jump : jumps){
            int pos = currentStone + jump;

            if(mp.find(pos) != mp.end()){

                if(pos == stones[n-1]){
                    return true;
                }

                if(jump>1){
                    mp[pos].insert(jump-1);
                }
                mp[pos].insert(jump);
                mp[pos].insert(jump+1);
            }
        }
    }

    return false;
}

int main(){
    int n;
    cin>>n;

    int stones[n];

    for(int i=0; i<n; i++){
        cin>>stones[i];
    }

    cout<<solution(stones,n);

    return 0;
}