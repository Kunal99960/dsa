#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int inf=1e9+10;
int g[N][N];
int visited[N][N];
int level[N][N];
int n,m;
void reset(){
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j]=0;
                level[i][j]=inf;
            }
        }
}
vector<pair<int,int> > movements={
    {0,1},{1,0},{0,-1},{-1,0},
    {1,1},{1,-1},{-1,1},{-1,-1}
};
bool isvalid(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}
int bfs(){
    int mx=-1;
    int ans=-1;
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mx=max(mx,g[i][j]);
            }
        }
    queue<pair<int,int> > q;
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==mx){
                    q.push(make_pair(i,j));
                    visited[i][j]=1;
                    level[i][j]=0;
                }
            }
        }
      while(!q.empty()){
        auto cur=q.front();
        int x=cur.first;
        int y=cur.second;
        q.pop();
        for(auto m:movements){
            int cx=m.first+x;
            int cy=m.second+y;
            if(!isvalid(cx,cy)) continue;
            if(visited[cx][cy]) continue;
            q.push(make_pair(cx,cy));
            level[cx][cy]=level[x][y]+1;
            visited[cx][cy]=1;
            ans=max(ans,level[cx][cy]);
        }
    }
    return ans;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        reset();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
            }
        }
        cout<<bfs()<<"\n";
    }
}