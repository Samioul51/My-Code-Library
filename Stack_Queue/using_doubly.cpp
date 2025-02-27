#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;

        Node(int val){
            this->val=val;
            this->next=NULL;
            this->prev=NULL;
        }
};

class Queue{
    public:
        Node* head=NULL;
        Node* tail=NULL;
        int s=0;
        void push(int val){
            s++;
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

        void pop(){
            s--;
            Node* del=head;
            head=head->next;
            
            delete del;
            if(head==NULL){
                tail=NULL;
                return;
            }
            head->prev=NULL;
        }

        int front(){
            return head->val;
        }

        int back(){
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
    Queue q;
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}