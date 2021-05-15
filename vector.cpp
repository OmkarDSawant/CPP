#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> v; //dynamic size

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    //Ways to print vector

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //Another way

    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //Another way

    for(auto element:v){ // here auto = int 
        cout<<element<<" ";
    }
    cout<<endl;

    v.pop_back(); //pops the last element
    vector<int> v2 (3,50); //size and element. So v2 contains 50 50 50


    //pair : It is an stl container. It allows us to store pair of values.

    pair<int,int> p;
    p.first = 10;
    p.second = 20;

    return 0;
}