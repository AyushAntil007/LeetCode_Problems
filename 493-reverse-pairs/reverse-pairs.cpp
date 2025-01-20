class Solution {
public:
    void merge(vector<int>& nums, int& cnt, int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        vector<int> temp;

       while (i <= mid) {
            while (j <= high && (long long)nums[i] > 2 * (long long)nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1)); // Add the count of reverse pairs
            i++;
        }

        i = low;
        j = mid + 1;
        while (i <= mid && j <= high) {
            if (nums[i] > nums[j]) {
                temp.push_back(nums[j]);
                j++;
            } else {
                temp.push_back(nums[i]);
                i++;
            }
        }
        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& nums, int& cnt, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(nums, cnt, low, mid);
            mergeSort(nums, cnt, mid + 1, high);

            merge(nums, cnt, low, mid,
                  high); // jab do array ik dusre k sath compare honge vahi ik
                         // extra cond lagani hai
        }
    }

    int reversePairs(vector<int>& nums) {

        int n = nums.size();
        int cnt = 0;
        // brute force
        //  for(int i=0;i<n;i++){
        //      for(int j=i+1;j<n;j++){
        //          if(nums[i]>nums[j]*2)cnt++;
        //      }
        //  }
        //  return cnt;

        // better sol......merge sort

        mergeSort(nums, cnt, 0, n - 1);
        return cnt;
    }
};