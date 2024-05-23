#include<bits/stdc++.h>
using namespace std;
const int N=sqrt(2147483647);
vector<int> prime(N,1);
int main(){
    for (int i = 2; i < N; i++)
    {
        /* code */
        if(prime[i]){
            for (int j = 2*i; j < N; j+=i)
                {
                    prime[j]=0;
                }
        }
    }
    long long  l,r;
    cin>>l>>r;
    vector<int> pr;
    for (int i = 2; i <= sqrt(r); i++)
    {
        /* code */
        if(prime[i]){
            pr.push_back(i);
        }
    }
    int a=r-l+1;
    vector<int> isprime(a,1);
    for (long long i = 0; i <pr.size(); i++)
    {
        int crprime=pr[i];
        long long  base =(l/crprime)*crprime;
        if(base<l) base+=crprime;
        for (long long j = base; j <=r; j+=crprime)
        {
            /* code */
            isprime[j-l]=0;
        }
        if(l<=crprime){
            isprime[base-l]=1;
        }
        
    }
    for (int i = 0; i < a; i++)
    {
        /* code */
        if(isprime[i]){
            cout<<i+l<<endl;
        }
    }
    
    
    
}