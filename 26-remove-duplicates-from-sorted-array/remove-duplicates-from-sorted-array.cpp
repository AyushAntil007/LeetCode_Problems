class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        nums.assign(s.begin(),s.end());
       return s.size();
    }
};