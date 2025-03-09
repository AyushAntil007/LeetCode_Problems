class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<vector<int>>cord;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    cord.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        
        int dx[4]={0,+1,0,-1};
        int dy[4]={+1,0,-1,0};

        while(!cord.empty()){
            int x=cord.front()[0];
            int y=cord.front()[1];
            int step=cord.front()[2];
            cord.pop();

            dist[x][y]=step;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<n&&nx>=0&&ny<m&&ny>=0&&vis[nx][ny]==0){
                    cord.push({nx,ny,step+1});
                    vis[nx][ny]=1;
                }
            }
        }
        return dist;
    }
};