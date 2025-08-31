class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int>ans;

        priority_queue<pair<int,int>>pq;

        unordered_map<int,int>freq;

        for(auto it: nums){
            freq[it]++;
        }

    for(auto f :freq){
        pq.push({f.second,f.first});
    }

    for(int i=0; i<k; i++){
        if(pq.empty())break;
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
        
    }
};