#include<bits/stdc++.h>

using namespace std;

class Stack{

    int N;
    queue<int> q1;
    queue<int> q2;

    public:

    Stack(){
        N=0;
    }

    void push(int x){
        q1.push(x);
        N++;
    }

    void pop(){

        if(q1.empty()){
            cout<<"Stack Underflow\n";
            return;
        }

        while(!q1.empty() && q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        N--;

        queue<int> temp = q1;
        q1=q2;
        q2=temp;
    }

    int peek(){

        if(q1.empty()){
            cout<<"No elements are present\n";
            return -1;
        }

        while(!q1.empty() && q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }

        int val = q1.front();
        q2.push(q1.front());
        q1.pop();

        queue<int> temp = q1;
        q1=q2;
        q2=temp;

        return val;
    }

    int size(){
        return N;
    }
    
};

int main(){

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.peek()<<"\n";
    st.pop();

    cout<<st.peek()<<"\n";
    st.pop();

    cout<<st.peek()<<"\n";
    st.pop();

    cout<<st.peek()<<"\n";
    st.pop();

    st.pop();

    return 0;
}