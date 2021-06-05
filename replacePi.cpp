#include<iostream>

using namespace std;

void replacepi(char *s, int n){
    for(int i=0;i<n;i++){

        if(s[i]=='p' && s[i+1]=='i'){
            cout<<"3.14";
            i++;
        }else{
            cout<<s[i];
        }
    }
}

int main(){

    // string s="pippxxppiixipi";
    char s[] = "pippxxppiixipi";
    replacepi(s,sizeof(s));
    return 0;
}