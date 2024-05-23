#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int ct[N];
int hsh[N];
int gcd(int a, int b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        hsh[x]++;
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j+=i)
        {
            ct[i]+=hsh[j];
        }
        
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     /* code */
    //     cout<<i<<" "<<ct[i]<<endl;
    // }
    
    int t;
    cin>>t;
    while (t--)
    {
        int p,q;
        cin>>p>>q;
        long ans=ct[p]+ct[q];
        long long  lcm=p*1LL*q/gcd(p,q);
        if(lcm<N) {ans-=ct[lcm];}
        cout<<ans<<endl;
    }
}