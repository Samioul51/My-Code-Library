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
            this->prev=NULL;
        }
};

class Stack{
    public:
        Node* head=NULL;
        Node* tail=NULL;
        int s=0;

        void push(int value){
            s++;
            Node* newnode=new Node(value);
            if(head==NULL){
                head=newnode;
                tail=head;
                return;
            }
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
            
        }

        void pop(){
            s--;
            Node* del=tail;
            tail=tail->prev;
            delete del;
            if(tail==NULL){
                head=NULL;
                return;
            }
            tail->next=NULL;
            
        }

        int top(){
            return tail->val;
        }

        int size(){
            return s;
        }

        bool empty(){
            return head==NULL;
        }
};

int main(){
    Stack st;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        st.push(x);
    }
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}