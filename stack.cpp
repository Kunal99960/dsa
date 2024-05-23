#include<bits/stdc++.h>
using namespace std;
struct mystack{
    int *arr;
    int cap;
    int top;
    mystack(int c){
        cap =c;
        arr=new int [cap];
        top=-1;
    }
    void push(int x){
        top++;
        arr[top]=x;
    }
    int pop(){
        int ans=arr[top];
        top--;
        return ans;
    }
    int peek(){
        return arr[top];
    }
    int size(){
        return top+1;
    }
    bool isempty(){
        return top==-1;
    }
};
int main(){
    mystack s(5);
    cout<<s.size();
    s.push(45);
    cout<<s.peek();
    cout<<s.isempty();
}