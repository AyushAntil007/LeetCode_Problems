class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        //  brute force
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         for (int k = j + 1; k < n; k++) {
        //             for (int l = k + 1; l < n; l++) {
        //                 // taking bigger data type
        //                 // to avoid integer overflow:
        //                 long long sum = nums[i] + nums[j];
        //                 sum += nums[k];
        //                 sum += nums[l];

        //                 if (sum == target) {
        //                     vector<int> temp = {nums[i], nums[j], nums[k],
        //                                         nums[l]};
        //                     sort(temp.begin(), temp.end());
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }

        // better sol....4th element in set
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         set<int> fourElt;
        //         for (int k = j + 1; k < n; k++) {
        //             int forth = target - (nums[i] + nums[j] + nums[k]);

        //             if (fourElt.find(forth) != fourElt.end()) {
        //                 vector<int> temp = {nums[i], nums[j], nums[k],
        //                 forth}; sort(temp.begin(), temp.end());
        //                 st.insert(temp);
        //             }
        //             fourElt.insert(
        //                 nums[k]); // put the kth element into the hashset:
        //         }
        //     }
        // }

        // optimal sol......two pointer

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int left = j + 1, right = n - 1;

                while (left < right) {
                      long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                      //sum while k ander calculate hoga

                    if (sum==target) {
                        vector<int> temp = {nums[i], nums[j], nums[left],
                                            nums[right]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                        left++,right--;
                    } else if (sum< target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};