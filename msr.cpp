#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        int c=1;
        for (int i = sqrt(n);i<m/2+1; i++)
        {
            if((i*i)%m==n){
                cout<<i<<endl;
                c=0;
                break;
            }
        }
        if(c){
            cout<<-1<<endl;
        }
        

    }
    
}