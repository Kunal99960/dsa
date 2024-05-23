#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int zeroes[N];
int ones[N];
int twos[N];
int threes[N];
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
                zeroes[i]++;
            }
            if(x==1){
                ones[i]++;
            }
            if(x==2){
                twos[i]++;
            }
            if(x==3){
                threes[i]++;
            }
        }
        for (int i = 2; i < N; i++)
        {
            zeroes[i]+=zeroes[i-1];
            ones[i]+=ones[i-1];
            twos[i]+=twos[i-1];
            threes[i]+=threes[i-1];
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
            int ct2=twos[r]-twos[l-1];
            int ct3=threes[r]-threes[l-1];
            cout<<ct0<<" "<<ct1<<" "<<ct2<<" "<<ct3<<endl;
            long long ans=d*1LL*(d-1)/2;
            long long z=ct0*ct1,x=ct0*ct2,c=ct0*ct3,v=ct1*ct2,b=ct0*(ct0-1)/2,n=ct1*(ct1-1)/2;
            cout<<z<<" "<<x<<" "<<v<<" "<<b<<" "<<n<<endl;

            ans=ans-(z+x+c+v+b+n);
            cout<<ans<<endl;
            

        }
        
    }
    
}