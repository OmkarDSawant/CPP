#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    
    short int amount;
    float finalAmount;

    cin>>amount;
    cin>>finalAmount;
    if((amount%5==0) && (amount!=0) && (finalAmount>(amount+0.50))){
        finalAmount -= amount + 0.50;
    }

    cout<<fixed<<setprecision(2)<<finalAmount;
    return 0;
}