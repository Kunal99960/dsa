#include<bits/stdc++.h>
using namespace std;
vector<int> g[100];
int h[100],d[100];
int vsum[20];
void dfs(int v,int p=0){
    vsum[v]=v;
    for(int child:g[v]){
        if(child==p) continue;
        d[child]=d[v]+1;

        dfs(child,v);
        h[v]=max(h[v],h[child]+1);
        vsum[v]+=vsum[child];
    }
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
    // for (int i = 1; i <= 13; i++)
    // {
    //     cout<<d[i]<<" ";
    // }
    // cout<<"\n";
    for (int i = 1; i <= 13; i++)
    {
        cout<<vsum[i]<<" ";
    }
    
    
}