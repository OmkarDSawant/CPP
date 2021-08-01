#include<bits/stdc++.h>

using namespace std;

int main(){
    int ladders, snakes;
    cin>>ladders; //Number of ladders and snakes

    map<int,int> lad; //Hashing

    int u,v;
    for(int i=0; i<ladders; i++){
        cin>>u>>v;
        lad[u] = v;
    }

    cin>>snakes;

    map<int,int> snak;
    for(int i=0; i<snakes; i++){
        cin>>u>>v;
        snak[u] = v;
    }

    //We are implementing BFS
    queue<int> q;
    q.push(1); //Starting pos

    bool found = false;
    int moves = 0;

    vector<int> vis(101, 0);
    vis[1] = 1;

    while(!q.empty() && !found){
        int sz = q.size(); //To update value for the entire level.
        while(sz--){
            int t = q.front();
            q.pop();

            for(int die=1; die<=6; die++){
                if(t+die == 100){
                    found = true;
                }
                if(t+die <= 100 && lad[t+die] && !vis[lad[t+die]]){
                    vis[lad[t+die]] = true;
                    if(lad[t+die] == 100){
                        found = true;
                    }
                    q.push(lad[t+die]);
                }
                else if(t+die <= 100 && snak[t+die] && !vis[snak[t+die]]){
                    vis[snak[t+die]] = true;
                    if(snak[t+die] == 100){
                        found = true;
                    }
                    q.push(snak[t+die]);
                }
                else if(t+die <= 100 && !lad[t+die] && !snak[t+die] && !vis[t+die]){
                    vis[t+die] = true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }

    if(found)
        cout<<"Moves: "<<moves;
    else
        cout<<"Not found";

    return 0;
}