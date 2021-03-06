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
    n->next = head;
    head = n;
}

void deletion(node* &head, int val){
    node* temp=head;

    if(temp==NULL){ //No elements present.
        return;
    }
    if(temp->data==val && temp->next==NULL){ //First element is to be deleted.
        delete temp;
        head=NULL;
        return;
    }
    if(temp->data==val && temp->next!=NULL){ //First element is to be deleted.
        head=head->next;
        delete temp;
        return;
    }

    while(temp->next->data!=val){// This also checks whether element is not present.
        temp=temp->next;
    }
    if(temp->data!=val){
        return;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

//iterative method
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nexptr;
    while(currptr!=NULL){
        nexptr=currptr->next;

        currptr->next=prevptr;
        prevptr = currptr;
        currptr = nexptr;
    }
    return prevptr;
}

//recursive method
node* reverseRecur(node* head){

    if(head==NULL||head->next==NULL){
        return head;
    }

    node* newhead = reverseRecur(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

//Reverse K nodes
node* reverseK(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next = prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++; //very important
    }

    if(nextptr!=NULL){
        head->next = reverseK(nextptr,k);
    }

    return prevptr;
}

void makeCycle(node* head,int pos){
    node* temp = head;
    node* cycleN;
    int count = 1;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
        if(count==pos){
            cycleN = temp;
        }
    }
    temp->next = cycleN;
}

bool detectCycle(node* head){
    node* fast = head;
    node* slow = head;

    while(fast!=NULL && fast->next!=NULL){

        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

void removeCycle(node* head){
    node* fast = head;
    node* slow = head;

    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (slow!=fast);

    fast = head;
    while (fast->next!=slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
    
}

int length(node* head){
    node* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

node* appendKN(node* &head,int k){
    int l = length(head);
    k = k%l;
    node* newhead;
    node* newtail;
    node* tail = head;
    int count=1;

    while(tail->next!=NULL){
        if(count==(l-k)){
            newtail = tail;
        }
        if(count==(l-k+1)){
            newhead = tail;
        }
        count++;
        tail = tail->next;
    }
    tail->next = head;
    newtail->next = NULL;
    return newhead;
}

void intersectTwo(node* head1, node* head2, int pos){
    node* temp1=head1;
    node* temp2=head2;
    int count = 1;

    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    while(temp1->next!=NULL && count<pos){
        temp1 = temp1->next;
        count++;
    }
    temp2->next = temp1->next;
}

int intersectionOfTwo(node* head1, node* head2){
    int l = length(head1);
    int m = length(head2);
    node* temp1=head1;
    node* temp2=head2;
    int count=1;
    if(l>m){
        while(count<=(l-m)){
            temp1=temp1->next;
            count++;
        }

        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1->data;
    }else{
        while(count<=(m-l)){
            temp2=temp2->next;
            count++;
        }

        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1->data;
    }
}
void EvenOdd(node* head){

    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    if(odd->next==NULL){
        even->next=NULL;
    }

    odd->next=evenStart;

}
int main(){

    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    cout<<"\n";

    EvenOdd(head);
    display(head);

    // node* head=NULL;
    // node* head2=NULL;

    // insertAtTail(head,1);
    // insertAtTail(head,2);
    // insertAtTail(head,3);
    // insertAtTail(head,4);
    // insertAtTail(head,7);
    // insertAtTail(head,8);

    // display(head);
    // cout<<"\n";

    // insertAtTail(head2,5);
    // insertAtTail(head2,6);

    // display(head2);
    // cout<<"\n";

    // intersectTwo(head,head2,4);
    
    // display(head2);
    // cout<<"\n";

    // cout<<intersectionOfTwo(head,head2);



    // cout<<"\n";
    // cout<<"\n"<<search(head,4);

    // deletion(head,5); //Error: If element to be deleted is not present then nothing after that gets exectued.
    // display(head);

    // cout<<"\n";
    // node* headptr = reverseRecur(head);
    // display(headptr);

    // node* newhead = reverseK(head,2);
    // display(newhead);

    // makeCycle(head,3);
    // cout<<detectCycle(head)<<"\n";
    // removeCycle(head);
    // display(head);

    // cout<<length(head)<<"\n";
    // node* newH = appendKN(head,3);
    // display(newH);


    return 0;
}