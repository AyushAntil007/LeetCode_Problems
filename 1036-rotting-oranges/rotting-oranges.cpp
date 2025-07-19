class Solution {
public:
void bfs(queue<pair<int,int>>&q,vector<vector<int>>&grid,vector<vector<int>>&vis,int &t,int n,int m){
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    while(!q.empty()){


        int k=q.size();

        while(k--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<n&&nx>=0&& ny<m&& ny>=0&& !vis[nx][ny]&& grid[nx][ny]==1){
                    vis[nx][ny]=1;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }

        }
        if(!q.empty()){
            t++;
        }
       


    }

}
    int orangesRotting(vector<vector<int>>& grid) {

        int t=0;
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
            }
        }

        bfs(q,grid,vis,t,n,m);

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return t;
    }
};