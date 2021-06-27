#include<iostream>
#include<set> //For both set and multiset. Implemented using balanced BST.
#include<unordered_set> //Implemented using hashing.

using namespace std;

int main(){

    set<int> a;
    multiset<int> b;
    unordered_set<int> c;

    //Operations on set.
    a.insert(5);
    a.insert(3);
    a.insert(7);
    a.insert(1);
    a.insert(7);

    cout<<"Set: ";
    for(auto i : a){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Upper Bound of 3: "<<*a.upper_bound(3)<<"\n";


    //Operations on multiset
    b.insert(5);
    b.insert(3);
    b.insert(7);
    b.insert(1);
    b.insert(7);

    b.erase(7);
    // Note: erase in multiset erases all instances if not used with find().
    cout<<"Multiset: ";
    for(auto i : b){
        cout<<i<<" ";
    }
    cout<<"\n";
    

    //Operations on unordered_set
    c.insert(5);
    c.insert(3);
    c.insert(7);
    c.insert(1);
    c.insert(7);

    cout<<"Unordered set: ";
    for(auto i : c){
        cout<<i<<" ";
    }

    return 0;
}

