//Either one can remain single or pair up with someone

#include<iostream>
#include<vector>

using namespace std;

void solution(int i, vector<bool> &used, string asf){

    if(i==used.size()){
        cout<<asf<<"\n";
        return;
    }

    if(used[i]){
        solution(i+1, used, asf); //If i is already used
    }else{
        used[i] = true;
        solution(i+1, used, asf +"(" + to_string(i) +")"); //single call
        for(int j=i+1; j<used.size(); j++){
            if(!used[j]){
                used[j]=true;
                solution(i+1, used, asf + "(" + to_string(i) +"," + to_string(j) +")"); //pair call
                used[j]=false;
            }
        }
        used[i] = false;
    }
}

int main(){

    int n;
    cin>>n;

    vector<bool> used(n+1, false);

    solution(1,used,"");

    return 0;
}