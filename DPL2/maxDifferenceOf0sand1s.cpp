#include<iostream>

using namespace std;

int main(){

    string str;
    cin>>str;

    int ans = 0;
    int csum = 0;

    int val;

    for(int i=0; i<str.length(); i++){

        if(str[i]=='0'){
            val = 1;
        }else{
            val = -1;
        }
        
        if(csum>0){
            csum += val;
        }else{
            csum = val;
        }

        if(csum>ans){
            ans = csum;
        }
    }

    if(ans == 0){
        cout<<-1;
    }else{
        cout<<ans;
    }

    return 0;
}