#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        vector<int> v;

        void push(int value){
            v.push_back(value);
        }

        void pop(){
            v.pop_back();
        }

        int top(){
            return v.back();
        }

        int size(){
            return v.size();
        }

        bool empty(){
            return v.empty();
        }

};
int main(){
    Stack st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // cout<<st.top()<<endl;
    // st.pop();
    // if(!st.empty())
    //     cout<<st.top()<<endl;

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