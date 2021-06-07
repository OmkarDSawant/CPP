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
        if(s1.empty()){
            cout<<"Queue Underflow.\n";
            return;
        }

        int x = s1.top();
        s1.pop();

        if(s1.empty()){
            return;
        }

        dequeue();
        enqueue(x);
    }
    int peek(){
        if(s1.empty()){
            cout<<"Queue Underflow.\n";
            return -1;
        }

        int x = s1.top();
        s1.pop();

        if(s1.empty()){
            s1.push(x);
            return x;
        }

        int item = peek();
        enqueue(x);
        return item;
    }


    bool empty(){
        if(s1.empty()){
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

    cout<<q.peek()<<"\n";
    q.dequeue();

    q.enqueue(5);

    cout<<q.peek()<<"\n";
    q.dequeue();

    cout<<q.peek()<<"\n";
    q.dequeue();

    cout<<q.peek()<<"\n";
    q.dequeue();

    cout<<q.empty();

    return 0;
}