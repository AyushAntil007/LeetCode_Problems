class Solution {
public:

void bfs(int sr,int sc,vector<vector<int>>&image,vector<vector<int>>&vis,queue<pair<int,int>>&q,int color,int n,int m){
    
   int initColor=image[sr][sc];

    vis[sr][sc]=1;
    image[sr][sc]=color;
    q.push({sr,sc});

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};

    while(!q.empty()){


        int r=q.front().first;
        int c=q.front().second;

        q.pop();

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<m && nc>=0&&nc<n  && image[nr][nc]==initColor&& !vis[nr][nc]){
                    vis[nr][nc]=1;
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
         }

    }
        
}
    


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m=image.size();
        int n=image[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;

        bfs(sr,sc,image,vis,q,color,n,m);
        
        return image;
        
    }
};