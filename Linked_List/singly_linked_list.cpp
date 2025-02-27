#include<bits/stdc++.h>
using namespace std;

//class for linked list
class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};


void insert_at_head(Node* &head, int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        return;
    }
    newnode->next = head;
    head=newnode;
}

void insert_at_tail(Node* &head, Node* &tail,int val){
  Node* newnode=new Node(val);
  if(head==NULL){
    head=newnode;
    tail=newnode;
    return;
  }

  //O(N) single insertion
  /*Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=newnode;
  */
  //O(1) single insertion
  tail->next=newnode; 
  tail=newnode;
}


//index wise
void insert_at_specific_pos(Node* &head, int val, int pos){
    Node* newnode=new Node(val);
    int i;
    if(head==NULL){
        head=newnode;
        return;
    }
    Node* temp=head;
    for(i=1;i<pos;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
//printing linked list
void print_list(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<< temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void print_reverse(Node* temp){
    if(temp==NULL){
        return;
    }
    print_reverse(temp->next);
    cout<<temp->val<<" ";
}

void delete_at_head(Node* &head){
    Node* temp = head;
    head = head->next;
    delete temp;
}

void delete_at_any_pos(Node* &head, int pos){
    Node* temp = head;
    if(pos==0){
        delete_at_head(head);
    }
    for(int i=1;i<pos;i++){
        temp = temp->next;
    }
    Node* deletenode=temp->next;
    temp->next=temp->next->next;
    delete deletenode;

}

void delete_at_any_tail(Node* &head, Node* &tail, int pos){
    Node* temp = head;
    if(pos==0){
        delete_at_head(head);
    }
    for(int i=1;i<pos;i++){
        temp = temp->next;
    }
    Node* deletenode=temp->next;
    temp->next=temp->next->next;
    delete deletenode;
    tail=temp;
}

void sort_linked_list(Node* head){
    for(Node* i=head;i->next!=NULL;i=i->next ){
        for(Node* j=i->next;j!=NULL;j=j->next ){
            if(i->val>j->val)
                swap(i->val ,j->val);
        }
    }
}

void reverse_list(Node* &head,Node* &tail,Node* temp){
    if(temp->next==NULL){
        head=temp;
        return;
    }
    reverse_list(head,tail,temp->next);
    temp->next->next=temp;
    temp->next=NULL;
    tail=temp;
}

//input niye cycle ber kora jabe na, manually list create korbo
void cycle_detection(Node* slow,Node* fast){ //argument hisebe 2 ta head
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"Cycle detected"<<endl;
            return;
        } 
        
    }
    cout<<"No Cycle"<<endl;
}
int main(){
    //Input
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    while(true){
        cin>>val;
        if(val==-1)
            break;
        insert_at_tail(head,tail,val);
    }
    reverse_list(head,tail,head);
    print_list(head);
    cout<<endl;
}
