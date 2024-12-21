class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (maxIdx < i) {  // 0 jump par hi fas gya in all possible ways
                return false;
            }
            maxIdx = max(maxIdx, i + nums[i]);

            if (maxIdx >= n - 1) //last elt par ho gya
                return true;
        }
        return true;
    }
};