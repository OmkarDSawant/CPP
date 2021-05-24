#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){

    if(head==NULL){//If no elements are present.
        insertAtHead(head,val);
        return;
    }

    node* n = new node(val);

    node* temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = n;
    n->prev = temp;


}

void deletion(node* &head, int pos){
    node* temp = head;
    int count = 1;

    if(pos==1 && temp->next==NULL){
        head = NULL;
        delete temp;
        return;
    }

    if(pos==1 && temp->next!=NULL){
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }

    while(temp!=NULL && count<pos){
        temp = temp->next;
        count++;
    }

    if(temp->next != NULL){ //If element to be deleted is last element.
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    cout<<"\n";

    deletion(head,1);
    display(head);
    return 0;
}