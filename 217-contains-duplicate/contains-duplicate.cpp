class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int n = nums.size();

        // unordered_map<int,int> freq;

        // for(int i=0 ; i < n; i++) {
        //     freq[nums[i]]++;
        //     if(freq[nums[i]] > 1)return true;  
        // }


        //using set

        unordered_set<int> st;

        for(int i=0; i<n; i++){
            if(st.find(nums[i]) != st.end()){
                return true;
            }
            st.insert(nums[i]);
        }

        return false;


        
    }
};