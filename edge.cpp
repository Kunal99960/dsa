#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
vector<int> g[100];
int vsum[100];
int val[100];
void dfs(int v,int p=0){
    vsum[v]=val[v];
    for(int child:g[v]){
        if(child==p) continue;
        dfs(child,v);
        vsum[v]+=vsum[child];
}
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    long long ans=0;
    for (int i = 2; i <= n; i++)
    {
        ans=max(ans,vsum[i]*1LL*(vsum[1]-vsum[i])%M);
    }
    
}