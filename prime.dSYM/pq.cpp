#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int zeroes[N];
int ones[N];
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin>>x;
            if(x==0){
                zeroes[x]++;
            }
            if(x==1){
                ones[x]++;
            }
        }
        for (int i = 2; i <= N; i++)
        {
            zeroes[i]+=zeroes[i-1];
            ones[i]+=ones[i-1];
        }
        int q;
        cin>>q;
        while (q--)
        {
            int l,r;
            cin>>l>>r;
            int d=r-l+1;
            int ct0=zeroes[r]-zeroes[l-1];
            int ct1=ones[r]-ones[l-1];
            long long f =ct0*1LL*ct1;
            long long ans=d*1LL*(d-1)/2;
            ans-=f;
            cout<<ans<<endl;
        }
        
    }
    
}