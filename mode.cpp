#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int ct0[N];
int ct1[N];
int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            ct0[i]=0;
            ct1[i]=0;
        }
        for(int i=0;i<n;i++){
            int x=s[i]-'0';
            if(x) ct1[i]=1;
            else ct0[i]=1;
        }
        for(int i=1;i<n;i++){
            ct0[i]+=ct0[i-1];
            ct1[i]+=ct1[i-1];
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j) ans++;
                else{
                    if(i==0){
                        if(ct0[j]==ct1[j]) ans+=2;
                        else ans++;
                    }
                    else{
                        if((ct0[j]-ct0[i-1])==(ct1[j]-ct1[i-1])) ans+=2;
                        else ans++;
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
}