class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig_col=image[sr][sc];
        
        if (image[sr][sc] == color) return image;
        
        int m=image.size();
        int n=image[0].size();

        queue<pair<int,int>>fill;
        fill.push({sr,sc});

        int dx[4]={0,+1,0,-1};
        int dy[4]={+1,0,-1,0};

        while(!fill.empty()){
            int x=fill.front().first;
            int y=fill.front().second;
            
            fill.pop();
            image[x][y]=color;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||ny<0||nx>=m||ny>=n||image[nx][ny]!=orig_col)continue;
                if(image[nx][ny]==orig_col){
                     fill.push({nx,ny});
                }
                
            }
        }
        return image;
    }
};