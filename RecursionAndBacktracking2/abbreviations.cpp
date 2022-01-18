#include<iostream>

using namespace std;

void solve(string str, string asf, int count, int pos){

    if(pos==str.length()){
        if(count>0)
            cout<<asf+to_string(count)+"\n";
        else
            cout<<asf+"\n";
        return;
    }

    if(count==0)
        solve(str, asf+str[pos], 0, pos+1);
    else
        solve(str, asf+to_string(count)+str[pos], 0, pos+1);
        
    solve(str,asf,count+1,pos+1);

}

int main(){

    solve("pep","",0,0);

    return 0;
}