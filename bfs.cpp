#include<bits/stdc++.h>
using namespace std;
vector<int> g[100];
int visited[100];
int level[100];
void bfs(int v){
    visited[v]=1;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        cout<<top<<" ";
        for( int child:g[top]){
            if(!visited[child]){
                q.push(child);
                visited[child]=1;
                level[child]=level[top]+1;
            }
        }
    }
    cout<<"\n";
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
    bfs(1);
    for(int i=0;i<=n;i++){
        cout<<i<<" "<<level[i]<<"\n";
    }
}