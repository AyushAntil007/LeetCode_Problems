class Solution {
public:
    void reverse(vector<int>&nums, int start, int end) {
        while (start <= end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // to ignore the full array rotation

        if (n == 0 || k == 0)
            return;

        // brute force

        // for (int i = 0; i < k; i++) {
        //     int temp = nums[n - 1]; // last elt store
        //     for (int j = n - 1; j >= 1; j--) {
        //         nums[j] = nums[j - 1]; // rotate right
        //     }
        //     nums[0] = temp; //store last at first
        // }

        // better solution

        // int temp[k];
        // for (int i = n - k; i < n; i++) {
        //     temp[i - n + k] = nums[i]; // copy rotated elts
        // }
        // for (int i = n - k - 1; i >= 0; i--) {
        //     nums[i + k] = nums[i]; // shifting
        // }
        // for (int i = 0; i < k; i++) {
        //     nums[i] = temp[i]; // paste elts
        // }

        // optimal solution
        reverse(nums, 0, n - k-1);
        reverse(nums, n - k , n-1);
        reverse(nums, 0, n-1);
    }
};