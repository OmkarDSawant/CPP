#include<iostream>

using namespace std;

int ans = INT_MIN;

string swap(string &str, int i, int j){

    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;

    

    return str; 

}

void solution(string str, int start, int mra){

    int temp = stoi(str);
    if( temp > ans){
        ans = temp;
    }

    if(mra == 0 || start == str.size()-1){
        return;
    }

    for(int i=start; i<str.size()-1; i++){
        for(int j=i+1; j<str.size(); j++){
            swap(str, i, j);
            solution(str, start + 1, mra-1);
            swap(str, i , j);
        }
    }
}

int main(){

    string str;
    cin>>str;

    int k;
    cin>>k;

    solution(str, 0, k);

    cout<<ans;

    return 0;
}