class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>>efforts(n,vector<int>(m,INT_MAX));
        efforts[0][0]=0;

        pq.push({0,0,0});

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        while(!pq.empty()){
            vector<int>vec=pq.top();
            int dis=vec[0];
            int x=vec[1];
            int y=vec[2];
            pq.pop();

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                
                if(nx>=0&&nx<n&&ny>=0&&ny<m){
                    int newEffort=max(abs(heights[nx][ny]-heights[x][y]),dis);
               
                    if(newEffort<efforts[nx][ny]){
                        efforts[nx][ny]=newEffort;
                        pq.push({efforts[nx][ny],nx,ny});

                    }
                    
                }
                if(nx==n-1&&ny==m-1)break;
            }
        }

        return efforts[n-1][m-1];
    }
};