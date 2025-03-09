class Solution {
public:
void dfs(vector<bool>&visited,vector<vector<int>>&adj,int node){
    visited[node]=true;
    for(auto neigh:adj[node]){
        if(!visited[neigh]){
            visited[neigh]=true;
            dfs(visited,adj,neigh);
        }
    }
}
void bfs(vector<bool>&visited,vector<vector<int>>adj,int start){
    visited[start]=1;
    queue<int>q;
    q.push(start);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                //dfs(visited,adj,i);
                bfs(visited,adj,i);
               count++;
            }
            
        }
        return count;
    }
};