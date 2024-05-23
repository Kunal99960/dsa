#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ct=0;
        for (int i = 1; i < n; i++)
        {
            if(s[i]!=s[i-1]) ct++;
        }
        if(ct<k) cout<<-1<<"\n";
        else{
            if(k%2==0){
                for (int i = n-1; i >= 0; i--)
                {
                    /* code */
                    if(s[i]==s[0]){
                        cout<<i+1<<"\n";
                        break;
                    }
                }
                
            }
            else{
                for (int i = n-1; i >=0; i--)
                {
                    /* code */
                    if(s[i]!=s[0]){
                        cout<<i+1<<"\n";
                        break;
                    }
                }
            }
        }
        
    }
    
}