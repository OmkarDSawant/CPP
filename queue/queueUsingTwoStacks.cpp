#include<bits/stdc++.h>

using namespace std;

class que{

    stack<int> s1;
    stack<int> s2;

    public:

    void enqueue(int x){
        s1.push(x);
    }

    void dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue Underflow.\n";
            return;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    int peek(){
        if(s1.empty() && s2.empty()){
            cout<<"No elements present.\n";
            return -1;
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
        
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

int main(){

    que q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<q.peek()<<"\n";
    q.dequeue();

    q.enqueue(5);

    cout<<q.peek()<<"\n";
    q.dequeue();
    cout<<q.peek()<<"\n";
    q.dequeue();
    cout<<q.peek()<<"\n";
    q.dequeue();
    cout<<q.peek()<<"\n";
    q.dequeue();

    cout<<q.empty();

    return 0;
}