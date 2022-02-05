#include<iostream>
#include<vector>

using namespace std;

//co - current option, to - total option
void permutation(vector<int> &boxes, int co, int to){

    if(co>to){
        for(int i=0; i<boxes.size(); i++){
            if(boxes[i] == 0){
                cout<<"-";
            }else{
                cout<<boxes[i];
            }
        }
        cout<<"\n";
        return;
    }

    for(int i=0; i<boxes.size(); i++){
        if(boxes[i] == 0){
            boxes[i] = co;
            permutation(boxes, co+1, to);
            boxes[i] = 0;
        }
    }
}

int main(){

    int n,r;
    cin>>n>>r;

    vector<int> boxes(n,0);

    permutation(boxes, 1, r);

    return 0;
}