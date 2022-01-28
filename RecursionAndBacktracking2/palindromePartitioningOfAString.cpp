#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string str){
    int l = 0;
    int r = str.size()-1;

    while(l<r){
        if(str[l] != str[r]){
            return false;
        }
        l++;
        r--;
    }

    return true;
}

void solution(string rs, string asf){

    if(rs.size()==0){
        cout<<asf<<"\n";
        return;
    }

    for(int i=0; i<rs.size(); i++){
        if( isPalindrome( rs.substr(0,i+1) ) ){
            solution(rs.substr(i+1),  asf + " (" + rs.substr(0,i+1) + ")");
        }
    }

}

int main(){

    string str;
    cin>>str;


    solution(str,"");

    return 0;
}