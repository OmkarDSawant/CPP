#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

int getNum(string s, unordered_map<char,int> &mp){
    string temp = "";
    for(int i=0; i<s.size(); i++){
        temp+= to_string(mp[s[i]]);
    }

    int num = stoi(temp);
    return num;
}

void display(unordered_map<char,int> &mp){
    for(int i=0; i<26; i++){
        if( mp.find(char('a'+i)) != mp.end() ){
            cout<<char('a'+i)<<"-"<<mp[char('a'+i)]<<" ";
        }
    }
}

void solution(unordered_map<char,int> &mp, string unique, vector<bool> &digit, int idx, string s1, string s2, string s3){

    if(idx == unique.size()){
        int num1 = getNum(s1, mp);
        int num2 = getNum(s2, mp);
        int num3 = getNum(s3, mp);

        if(num1+num2 == num3){
            display(mp);
            cout<<"\n";
            return;
        }
    }

    char ch = unique[idx]; //Levels
    
    for(int po=0; po<=9; po++){
        if(!digit[po]){
            digit[po] = true;
            mp[ch] = po;
            solution(mp, unique, digit, idx+1, s1, s2, s3);
            digit[po] = false;
            mp[ch] = -1;
        }
    }
}

int main(){

    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    unordered_map<char,int> mp;
    string unique = "";

    for(int i=0; i<s1.size(); i++){
        if(mp.find(s1[i]) == mp.end()){
            unique += s1[i];
            mp[s1[i]] = -1;
        }
    }

    for(int i=0; i<s2.size(); i++){
        if(mp.find(s2[i]) == mp.end()){
            unique += s2[i];
            mp[s2[i]] = -1;
        }
    }

    for(int i=0; i<s3.size(); i++){
        if(mp.find(s3[i]) == mp.end()){
            unique += s3[i];
            mp[s3[i]] = -1;
        }
    }

    cout<<unique<<"\n";

    vector<bool> digit(10,false);

    solution(mp, unique, digit, 0, s1, s2, s3);


    return 0;
}