#include<iostream>

using namespace std;

int knapsack(int wt[],int val[],int n,int W){

    if(n==0 || W==0)
        return 0;

    if(wt[n-1]>W){
        return knapsack(wt,val,n-1,W);
    }

    return max(knapsack(wt,val,n-1,W-wt[n-1])+val[n-1],knapsack(wt,val,n-1,W));
}

int main(){
    int wt[]={10,20,30};
    int val[]={100,50,150};
    int size = 3;
    int W=50;
    cout<<knapsack(wt,val,size,W);
    return 0;
}