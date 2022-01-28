#include<iostream>
#include<unordered_map>

using namespace std;

void solution(int cur, int tf, int odd, char oddC, unordered_map<char, int> &mp, string asf){

    for(unordered_map<char,int>::iterator it = mp.begin(); it != mp.end(); ++it){

        if(cur > tf){ //IMP
            string rev;

            for(int i=asf.size()-1; i>=0; i--){
                rev += asf[i];
            }

            if(odd==1){
                cout<<asf<<oddC<<rev<<"\n";
            }else{
                cout<<asf<<rev<<"\n";
            }

            return;
        }

        if(it->second>0){
            it->second --;
            solution(cur+1, tf, odd, oddC, mp, asf + it->first);
            it->second++;
        }
    }

}

int main(){

    int n;
    cin>>n;

    char ch;
    unordered_map<char,int> mp;
    for(int i=0; i<n; i++){
        cin>>ch;
        if(mp.find(ch) == mp.end()){
            mp[ch] = 1;
        }else{
            mp[ch]++;
        }
    }

    int tf = 0;

    int odd = 0;
    char oddC;

    int tempFreq;
    for(unordered_map<char,int>::iterator it = mp.begin(); it != mp.end(); ++it){
        tempFreq = (it->second)/2;
        if( ((it->second)%2) != 0){
            odd++;
            oddC = it->first;
        }
        tf+= tempFreq;
        it->second = tempFreq;
    }

    if(odd>1){
        cout<<"NA\n";
        return 0;
    }

    solution(1, tf, odd, oddC, mp, "");

    return 0;
}