#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val){// Head passed by reference as we change head val.
    node* n = new node(val); //n is pointer to newly created node.

    node* temp = head;
    if(temp==NULL){//No elements present
        head = n;
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;
}

void display(node* head){// Head Passed by Value
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

bool search(node* head, int key){
    node* temp = head;
    while(temp!=NULL){
        if (temp->data == key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    node *temp = n;
    temp->next = head;
    head = n;
}

void deletion(node* &head, int val){
    node* temp=head;

    if(temp==NULL){ //No elements present.
        return;
    }
    if(temp->next==NULL){ //Only one element is present.
        delete head;
        head=NULL;
        return;
    }

    while(temp->next->data!=val){// This also checks whether element is not present.
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtHead(head,0);
    display(head);
    //cout<<"\n"<<search(head,4);
    deletion(head,5);
    cout<<"\n";
    display(head);
    return 0;
}