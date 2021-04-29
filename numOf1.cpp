#include<iostream>

using namespace std;

int numOf1(int a){
    int count=0;
    while(a!=0){
        a=(a&(a-1));
        count++;
    }
    return count;
}
int main(){

    cout<<numOf1(12);
    return 0;
}