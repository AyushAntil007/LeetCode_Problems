class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        int m=numCourses;
        vector<vector<int>>adj(m);  //dont forget to initialise

        for(int i=0;i<n;i++){
            vector<int>vec=prerequisites[i];
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
        }
      
        vector<int>indeg(m,0);

        for(int i=0;i<m;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;

        for(int i=0;i<m;i++){
            if(indeg[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }
        if(count==m)return true;   //to find that all courses are done after the rquired ones...just detct cycle
        return false;
    }
};