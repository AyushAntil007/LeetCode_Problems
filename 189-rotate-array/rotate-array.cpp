class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // to ignore the full array rotation

        // brute force

        // for (int i = 0; i < k; i++) {
        //     int temp = nums[n - 1]; // last elt store
        //     for (int j = n - 1; j >= 1; j--) {
        //         nums[j] = nums[j - 1]; // rotate right
        //     }
        //     nums[0] = temp; //store last at first
        // }

        // better solution

        if (n == 0||k==0)
            return;
        k = k % n;
       
        int temp[k];
        for (int i = n - k; i < n; i++) {
            temp[i - n + k] = nums[i]; // copy rotated elts
        }
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i]; // shifting
        }
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i]; // paste elts
        }

        // optimal solution
    }
};