class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // buillt in fn
        // next_permutation(nums.begin(),nums.end());

        // optimaL SOL
        int bpoint = -1;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) { // finding elt where number can be
                                         // change to get next permn
                bpoint = i;
                break;
            }
        }
        if (bpoint == -1) { // if the last permn is already given then return
                            // sorted order of permn
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > bpoint; i--) {
            if (nums[i] > nums[bpoint]) {  //******graeter hi hona chaiye
                swap(nums[i], nums[bpoint]);
                break;
            }
        }
        reverse(nums.begin() + bpoint + 1,
                nums.end()); // make the number short by reversing the last
                             // sorted(desc)digits after break point
    }
};