class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>revGraph(n);
        vector<int>indeg(n,0);

        for(int i=0;i<n;i++){       
            for(auto it : graph[i]){
                revGraph[it].push_back(i);     //reverse the graph edges
                indeg[i]++;
            }
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);    //indegree '0'.....terminal nodes
        }

        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);           
            for(auto it : revGraph[node]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);      //.......safe nodes
            }

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};