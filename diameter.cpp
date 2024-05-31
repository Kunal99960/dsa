#include<bits/stdc++.h>
using namespace std;
vector<int> g[100];
int d[100];
void dfs(int v,int p=0){
    for(int child:g[v]){
        if(child==p) continue;
        d[child]=d[v]+1;
        dfs(child,v);
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
    int max_v=-1,max_node;
    for(int i=1;i<=n;i++){
        if(d[i]>max_v){
            max_v=d[i];
            max_node=i;
        }
        d[i]=0;
    }
    dfs(max_node);
    for(int i=1;i<=n;i++){
        if(d[i]>max_v){
            max_v=d[i];
        }
    }
    cout<<max_v<<endl;
}