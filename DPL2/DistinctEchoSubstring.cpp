#include<iostream>
#include<unordered_set>

using namespace std;

//overall time complexity O(n^3)
int solution1(string text){
    int n = text.length();
    unordered_set<string> st;

    for(int len=1; len<n/2; len++){ //O(n/2)
        int count = 0;
        for(int l=0, r=len; r<n; l++, r++){ //O(n/2)
            if(text[l] == text[r]){
                count++;
            }else{
                count = 0;
            }

            if(count == len){
                string str = text.substr(l+1,len); //O(n/2)
                st.insert(str);
                count--;
            }
        }
    }

    return st.size();
}

int main(){

    string text;
    cin>>text;

    cout<<solution1(text);

    return 0;
}