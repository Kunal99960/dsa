class Solution {
public:
    // int hsh[100][100];
    int ans=-1;
    void dfs(vector<vector<int>>& grid,int i,int j,int pari,int parj){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return;
        if(grid[i][j]==0) return;
        if(i==pari && (j+1)==parj) return;
        if(i==pari && (j-1)==parj) return;
        if(j==parj && (i+1)==pari) return;
        if(j==parj && (i-1)==pari) return;
        // hsh[i][j]=1;
        ans++;
        dfs(grid,i,j+1,i,j);
        dfs(grid,i,j-1,i,j);
        dfs(grid,i+1,j,i,j);
        dfs(grid,i-1,j,i,j);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int result=0;
        int a,k;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    a=i;
                    k=j;
                    result++;
                }
            }
        }
        dfs(grid,a,k,-1,-1);
        return 4*result - 2*ans ;
    }
};