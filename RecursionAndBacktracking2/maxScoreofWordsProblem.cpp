#include<iostream>
#include<vector>

using namespace std;

int solution(vector<string> &words, vector<int> &farr, int *score, int idx){

    if(idx == words.size()){
        return 0;
    }

    int ninc = solution(words, farr, score, idx+1);

    int curr = 0;
    bool flag = true;

    string word = words[idx];
    for(int i=0; i<word.size(); i++){
        char ch = word[i];

        if(farr[ch-'a'] == 0){
            flag = false;
        }

        farr[ch-'a']--;
        curr+=score[ch-'a'];
    }

    int inc = 0;
    if(flag){
        inc = curr + solution(words, farr, score, idx+1);
    }

    for(int i=0; i<word.size(); i++){

        char ch = word[i];
        farr[ch-'a']++;

    }

    return max(ninc,inc);
}

int main(){

    int n;
    cin>>n;

    vector<string> words(n);

    for(int i=0; i<n; i++){
        cin>>words[i];
    }

    vector<int> farr(26,0);

    cin>>n;
    char ch;

    for(int i=0; i<n; i++){
        cin>>ch;
        farr[ch-'a']++;
    }

    int score[26];

    for(int i=0; i<26; i++){
        cin>>score[i];
    } 

    cout<<solution(words, farr, score, 0);
    return 0;
}