class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        // brute force
        //  for (int i = 0; i < n; i++) {
        //      for (int j = i; j < n; j++) {
        //          int sum = 0;
        //          for (int K = i; K <= j;
        //               K++) // calculate the sum of subarray [i...j]
        //              sum += arr[K];
        //          if (sum == k)
        //              cnt++;
        //      }
        //  }
        //  return cnt;

        // better sol
        //        for (int i = 0 ; i < n; i++) {
        //      int sum = 0;
        //      for (int j = i; j < n; j++) {
        //          sum += arr[j];
        //          if (sum == k)
        //              cnt++;
        //      }
        //  }
        //  return cnt;

        // optimal sol

        map<int, int> mpp;
        mpp[0] = 1; //*****important if we directly get sum==k
        int sum = 0;

        for (int i = 0; i < n; i++) { // concept of the prefix sum
            sum += arr[i];        //x
            int remove = sum - k; //  x-k
            cnt += mpp[remove];    //****many possible solns
            mpp[sum]++;            //store sum
        }
        return cnt;
    }
};