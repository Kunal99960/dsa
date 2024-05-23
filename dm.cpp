#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int lp[N];
int cr[N];
int hsh[N];
vector<int> dpf(int x){
    vector<int> ans;
    while (x>1)
    {
        int pf=lp[x];
        while (x%pf==0)
        {
            x/=pf;
        }
        ans.push_back(pf);
        
    }
    return ans;
    
}
int main(){
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j+=i)
        {
            if(!lp[j]){
                lp[j]=i;
            }
        }
    }
    int n,q;
    cin>>n>>q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        hsh[x]=1;
    }
    for (int i = 2; i < N; i++)
    {
        if(hsh[i]){
            for (long long  j = i; j < N; j=j*i)
            {
                cr[j]=1;
            }
            
        }
    }
    
    while (q--)
    {
        int x;
        cin>>x;
        vector<int> pf =dpf(x);
        bool ans=0;
        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = i; j < pf.size(); j++)
            {
                int product=pf[i]*pf[j];
                if(i==j && x%product!=0) continue;
                int remove=x/product;
                if(cr[remove] || remove==1){
                    ans=1;
                    break;
                }
            }
            if(ans) break;
            
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    
    
}