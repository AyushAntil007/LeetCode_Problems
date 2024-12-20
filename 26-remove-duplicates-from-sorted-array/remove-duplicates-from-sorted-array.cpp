class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        // brute force

        //     set<int>s;
        //     for(int i=0;i<n;i++){
        //         s.insert(nums[i]);
        //     }
        //     nums.assign(s.begin(),s.end());
        //    return s.size();


        //two pointer approach
        
        int i=0;
        for(int j=1;j<n;j++){
            if(nums[j]!=nums[i]){
                 nums[i+1]=nums[j];
                 i++;
            }
           
        }
        return i+1;
    }
};