class Solution {
public:
void bfs(int sr,int sc,vector<vector<int>>&image,int color,vector<vector<int>>&vis,queue<pair<int,int>>&q,int n,int m){
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    int initColor=image[sr][sc];
    image[sr][sc]=color;
    q.push({sr,sc});

    while(!q.empty()){

            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<m&&nx>=0&& ny<n&& ny>=0&& !vis[nx][ny]&& image[nx][ny]==initColor){
                    vis[nx][ny]=1;
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
            }

        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int m=image.size();
        int n=image[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        bfs(sr,sc,image,color,vis,q,n,m);
        return image;
    }
};