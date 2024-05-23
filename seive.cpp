#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
vector<int> isprime(N,1);
vector<int> lp(N),hp(N);
vector<int> divisors[100];
int main(){
    isprime[0]=isprime[1]=0;
    for (int i = 2; i < N; i++)
    {
        if(isprime[i]){
            lp[i]=hp[i]=i;
            for (int j = 2*i; j < N; j+=i)
            {
                isprime[j]=0;
                hp[j]=i;
                if(!lp[j]){
                    lp[j]=i;
                }
            }
            
        }
    }
    int a;
    cout<<"enter number to prime factorised : ";
    cin>>a;
    int s=lp[a];
    map<int,int> ans;
    while (a>1)
    {
        ans[s]++;
        a=a/s;
        s=lp[a];
    }
    for (auto p:ans)
    {
        cout<<p.first<<" "<<p.second<<endl;;
    }
    // for (int i = 1; i < 100; i++)
    // {
    //     for (int j = i; j < 100; j+=i)
    //     {
    //         divisors[j].push_back(i);
    //     }
        
    // }
    // for(auto a:divisors){
    //     for(auto b:a){
    //         cout<<b<<" ";
    //     }
    //     cout<<endl;
    // }
    
// }
// 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
// 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
// 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