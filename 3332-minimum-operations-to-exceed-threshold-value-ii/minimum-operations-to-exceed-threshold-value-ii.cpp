class Solution {
public:
    // bool greatK(vector<int>& nums, int n, int k) {
    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] < k) return false;
    //     }
    //     return true;
    // }

    int minOperations(vector<int>& nums, int k) {
        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // int count = 0;
        
        // while (nums.size() >= 2) {
        //     if (greatK(nums, nums.size(), k)) return count;

        //     long long elt = (long long)min(nums[0], nums[1]) * 2;
        //     elt =(long long)(elt+ max(nums[0], nums[1]));

        //     nums.push_back(elt);
        //     nums.erase(nums.begin(), nums.begin() + 2);

        //     sort(nums.begin(), nums.end());

        //     count++;
        // }
        // return count;



        //min-priority_queue

        priority_queue<long long,vector<long long>,greater<long long>>pq;
        int n=nums.size();

        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }

        int count=0;
        while(pq.size()>=2&&pq.top()<k){
            long long elt1=pq.top();
            pq.pop();
            long long elt2=pq.top();
            pq.pop();

            long long fHalf=(long long)min(elt1,elt2) * 2 ;
            long long sHalf= max(elt1,elt2);

            long long calElt=fHalf+sHalf;
            pq.push(calElt);

            count++;
        }
        return count;
        
    }
};