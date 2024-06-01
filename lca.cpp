#include<bits/stdc++.h>
using namespace std;
vector<int> g[100];
int par[100];
void dfs(int v,int p=-1){
    par[v]=p;
    for(int child:g[v]){
        if(child==p) continue;
        dfs(child,v);
    }
}
vector<int> path(int v){
    vector<int> ans ;
    while(v!=-1){
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    int x,y;
    cin>>x>>y;
    vector<int> path_n=path(x);
    vector<int> path_m=path(y);
    int m=min(path_n.size(),path_m.size());
    int lca=-1;
    for(int i=0;i<m;i++){
        if(path_n[i]==path_m[i]){
            lca=path_n[i];
        }
        else break;
    }
    cout<<lca<<endl;
}