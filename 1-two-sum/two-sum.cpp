class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();

        // brute force

        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (arr[i] + arr[j] == target) {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {-1, -1};

        // better solution

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};

        // optimal solution..............only provide yes or no*****

        // sort(arr.begin(), arr.end());
        // int left = 0, right = n - 1;
        // while (left < right) {
        //     int sum = arr[left] + arr[right];
        //     if (sum == target) {
        //         return "yes";
        //     }
        //     else if (sum < target)
        //         left++;
        //     else
        //         right--;
        // }
        // return "no";
    }
};