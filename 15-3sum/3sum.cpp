class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        int n = nums.size();

        // brute force..............3 for loop
        //     for(int i=0;i<n;i++){
        //         for(int j=i+1;j<n;j++){
        //             for(int k=j+1;k<n;k++){
        //                  if(nums[i]+nums[j]+nums[k]==0){
        //                       vector<int>subAns={nums[i],nums[j],nums[k]};
        //                       sort(subAns.begin(),subAns.end());   //sort the
        //                       pairs st.insert(subAns);
        //                  }
        //             }
        //         }
        //     }

        // better sol......check in set

        // for (int i = 0; i < n - 2; i++) {
        //      set<int> thirdElt;
        //     for (int j = i + 1; j < n ; j++) {
        //         int third = 0 - nums[i] - nums[j];

        //         if (thirdElt.find(third) != thirdElt.end()) {
        //             vector<int> subAns = {nums[i], nums[j], third};
        //             sort(subAns.begin(), subAns.end());
        //             st.insert(subAns);
        //         }

        //          thirdElt.insert(nums[j]);
        //     }
        // }

        // optimal solution........sorting and 2 pointer

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;

            if (i > 0 && nums[i] == nums[i - 1])   // to skip duplkicates
                continue;

            while (left < right) {   // two pointer approach
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left -1]) {   //skip duplicates
                        left++;
                    }
                    while (right > left && nums[right] == nums[right + 1]) {   //skip duplivcates
                        right--;
                    }
                }
            }
        }

        // for (auto it : st) { // store set elts in ans
        //     ans.push_back(it);
        // }
        return ans;
    }
};