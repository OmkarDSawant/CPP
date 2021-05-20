#include<iostream>

using namespace std;

//Class definition
class student{
    //By default all data members and member functions are private.
    
    int age;
    int std;
    string name;

    public://Access modifier

    student(){
        cout<<"Default Constructor called..\n";
    }

    student(string n, int a, int s){
        //Parameterized constructor
        cout<<"Parameterized Constuctor called..\n";
        name=n;
        age=a;
        std=s;
    }

    student(student &a){
        //Copy Constructor. Shallow copy (default copy constructor) and Deep copy(user defined copy constructor) are two concepts in copy constructors.
        cout<<"Copy Constuctor called..\n";
        name=a.name;
        age=a.age;
        std=a.std;
    }

    bool operator == (student &a){
        cout<<a.name<<"\n";
        if(name==a.name && age==a.age && std==a.std){
            return true;
        }else{
            return false;
        }
    }

    ~student(){//Destructor is automatically called.
        cout<<"Destructor called\n";
    }

    void setName(string n){
        name = n;
    }

    void getName(){
        cout<<name;
    }
};

int main(){

    student a("Yash",22,16);
    student b("Omkar", 20,15);
    student c=b;
    if(c==a){
        cout<<"Same\n";
    }else{
        cout<<"Different\n";
    }
    return 0;
}