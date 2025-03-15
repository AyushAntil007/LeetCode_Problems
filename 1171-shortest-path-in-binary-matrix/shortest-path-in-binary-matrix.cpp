class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1; // Start or End blocked

        queue<vector<int>> p;

        p.push({1,0,0});
       
       vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
       dist[0][0]=1;  // src step count
       

        int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

       while(!p.empty()){
           vector<int>vec=p.front();  //dist of the parent node fron src
           int dis=vec[0];  //parent node
           int x=vec[1];
           int y=vec[2];
           p.pop();

           
           for(int i=0;i<8;i++){

               int nx=dx[i]+x;
               int ny=dy[i]+y;

               
               if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
              //grid cellshoul have value '0' for movement
                      if (dis + 1 < dist[nx][ny]) {  //add '1' step for each child
                        dist[nx][ny] = dis + 1;
                        p.push({dist[nx][ny], nx, ny});
                    }
                }

                if(nx==n-1&&ny==n-1)break;
               
           }
       }
       if(dist[n-1][n-1]!=INT_MAX)return dist[n-1][n-1];
        return -1;
    }
};