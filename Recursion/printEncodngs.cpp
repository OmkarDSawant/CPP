#include<bits/stdc++.h>

using namespace std;

void printEncodings(string n, string ans){
    if(n.length()==0){
        cout<<ans<<"\n";
        return;
    }else if(n.length()==1){
        char ch1 = n[0];
        string ros1 = n.substr(1);

        if(ch1-'0' > 0){
            char ch = (char) (ch1-'0' + 96);
            printEncodings(ros1,ans+ch);
        }else{
            return;
        }

    }else{
        char ch1 = n[0];
        string ros1 = n.substr(1);

        string ch2 = n.substr(0,2);
        string ros2 = n.substr(2);

        if(ch1-'0' > 0){
            char ch = (char) (ch1-'0' + 96);
            printEncodings(ros1,ans+ch);
        }else{
            return;
        }

        if(stoi(ch2)>=1 && stoi(ch2)<=26){
            char ch = (char) (stoi(ch2) + 96);
            printEncodings(ros2,ans+ch);
        }else{
            return;
        }
    }  
}

int main(){
    string n;
    cin>>n;

    printEncodings(n,"");

    return 0;
}