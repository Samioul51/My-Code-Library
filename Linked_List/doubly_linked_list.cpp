#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;
    
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(Node* &head,Node* &tail,int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head=newnode;
        tail=head;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;

}

void insert_at_tail(Node* &head,Node* &tail,int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        tail=head;
        return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}

void insert_at_any_pos(Node* &head, Node* &tail, int val, int pos){
    Node* newnode = new Node(val);
    if(pos==0){
        insert_at_head(head,tail,val);
    }
    Node* temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}

void delete_at_head(Node* &head,Node* &tail){
    Node* deletednode=head;
    head=head->next;
    delete deletednode;
    if(head==NULL){
        tail=NULL;
        return;
    }
    head->prev=NULL;
    
}

void delete_at_tail(Node* &head,Node* &tail){
    Node* deletednode=tail;
    tail=tail->prev;
    delete deletednode;
    if(tail==NULL){
        head=NULL;
        return;
    }
    tail->next=NULL;
    

}

void delete_at_any_pos(Node* &head, Node* &tail, int pos){
    Node* temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    Node* deletednode=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete deletednode;
}

void print_forward(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void print_backward(Node* tail){
    Node* temp=tail;
     while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}

void reverse_list(Node* head, Node* tail){
    Node* temp=head;
    Node* temp2=tail;
    while(temp!=temp2 && temp2!=temp->prev){
        swap(temp->val,temp2->val);
        temp=temp->next;
        temp2=temp2->prev;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;

    int val;
    while(true){
        cin>>val;
        if(val==-1)
            break;
        insert_at_tail(head,tail,val);
    }

    reverse_list(head,tail);    
    print_forward(head);

   
    return 0;
}