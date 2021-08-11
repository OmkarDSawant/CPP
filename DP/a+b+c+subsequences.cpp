//Total count of subsequences of a+b+c type.

#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cin>>str;

    int a=0; //Count of subsequences of type a+
    int ab=0; //Count of subsequences of type a+b+
    int abc=0; ////Count of subsequences of type a+b+c+

    for(int i=0; i<str.length(); i++){
        if(str[i]=='a'){
            a = 2*a + 1;
        }else if(str[i]=='b'){
            ab = 2*ab + a;
        }else if(str[i]=='c'){
            abc = 2*abc + ab;
        }
    }

    cout<<abc;
    return 0;
}