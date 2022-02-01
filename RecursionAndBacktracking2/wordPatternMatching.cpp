#include<iostream>
#include<unordered_map>
#include<unordered_set>

using namespace std;

void solution(string pattern, string word, int ci, unordered_map<char,string> &mp){

    if(ci==word.size()){
        if(pattern.size() == 0){
            unordered_set<char> isPresent;

            for(int i=0; i<word.size(); i++){
                if(isPresent.find(word[i]) == isPresent.end()){
                    cout<<word[i]<<"->"<<mp[word[i]]<<", ";
                    isPresent.insert(word[i]);
                }
            }
            cout<<"\n";
        }

        return;
    }

    char ch = word[ci];

    if(mp.find(ch) != mp.end()){

        string ps = mp[ch];
        string tocompare = pattern.substr(0,ps.size());

        if(ps.compare(tocompare) == 0){
            string right = pattern.substr(ps.size());
            solution(right, word, ci+1, mp);
        }

    }else{
        for(int i=0; i<pattern.size(); i++){
            string left = pattern.substr(0,i+1);
            string right = pattern.substr(i+1);

            // cout<<left<<" "<<right;
            mp[ch] = left;
            solution(right, word, ci+1, mp);
            mp.erase(ch);
        }
    }
}

int main(){

    string pattern,word;
    cin>>pattern>>word;

    unordered_map<char,string> mp;

    solution(pattern, word, 0, mp);

    return 0;
}