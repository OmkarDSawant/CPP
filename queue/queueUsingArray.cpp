#include<bits/stdc++.h>

using namespace std;

#define n 20

class que{
    int *arr;
    int front;
    int back;

    public:
    que(){
        arr = new int[n];
        front=-1;
        back=-1;
    }

    void enqueue(int x){
        if(back==n-1){
            cout<<"Queue overflow\n";
            return;
        }
        back++;
        arr[back]=x;

        if(front==-1){
            front++;
        }
    }

    void dequeue(){
        if(front==-1 || front>back){
            cout<<"No elements present.\n";
            return;
        }

        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            cout<<"No elements present.\n";
            return -1; //As return type is int thus we can't just return.
        }

        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
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

    cout<<q.peek()<<"\n";
    q.dequeue();

    cout<<q.peek()<<"\n";
    q.dequeue();

    cout<<q.empty();

    return 0;
}