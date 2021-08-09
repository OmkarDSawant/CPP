//There are n spaces on one side of the road and n spaces on the other side of the road. Find Number of arrangements
//such that no two buildings on one side be adjacent to each other.

//Similar to count of binary strings that can be formed of length N with no consecutive zeroes.

#include<iostream>

using namespace std;

int main(){
    int n; cin>>n;

    int odpb = 1; //Binary string that end with 0 of length 1;
    int odps = 1; ////Binary string that end with 1 of length 1; 

    for(int i=2; i<=n; i++){
        int ndpb = odps;
        int ndps = odpb + odps;

        odpb = ndpb;
        odps = ndps; 
    }

    int oneSideCount = odpb + odps;
    cout<<"Total count of arrangements : "<<oneSideCount*oneSideCount;

    return 0;
}