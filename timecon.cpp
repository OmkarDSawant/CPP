#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;
    
    string ap = s.substr(8,1);
    int hour = stoi(s.substr(0,2));
    
    
    if( (hour<=11 && (!ap.compare("A"))) || (hour==12 && (!ap.compare("P"))) ){
        cout<<s.substr(0,8);
    } else{
        if(((hour+12)%24)==0){
            cout<<"0"<<to_string((hour+12)%24)<<s.substr(2,6);
        }else{
            cout<<to_string((hour+12)%24)<<s.substr(2,6); 
        }
    }
    
    return 0;
}
