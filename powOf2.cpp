#include<iostream>

using namespace std;

int powOf2(int a){
    return ((a & (a-1)) == 0);
}

int main(){
    cout<<powOf2(15);
    return 0;
}