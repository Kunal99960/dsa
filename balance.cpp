#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"enter paranthesis : ";
    string s;
    cin>>s;
    int n=s.size();
    stack<char> stk;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='(' || s[i]== '{' || s[i]=='['){
            stk.push(s[i]);
        }
        else{
            char a=stk.top();
            if(a=='(' && s[i]==')') stk.pop();
            else if(a=='[' && s[i]==']') stk.pop();
            else if(a=='{' && s[i]=='}') stk.pop();
            else{
                break;
            }

        }
    }
    if(stk.empty()) cout<<"Yes\n";
    else cout<<"NO\n";
    
}