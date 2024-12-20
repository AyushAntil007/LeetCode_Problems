class Solution {
public:
    bool isSorted(vector<int>& arr) {
        for (int k = 1; k < arr.size(); k++) {
            if (arr[k] >= arr[k - 1])
                continue;
            else
                return false;
        }
        return true;
    }
    bool check(vector<int>& arr) {
        // int k;
        int n = arr.size();

        // brute force

        // for (int i = 1; i < n; i++) {
        //     if (arr[i] >= arr[i - 1])
        //         continue;
        //     else {
        //         k = i;
        //         if (arr[n - 1] > arr[0])
        //             return false;
        //         break;
        //     }
        // }
        // for (int i = k + 1; i < n; i++) {
        //     if (arr[i] >= arr[i - 1])
        //         continue;
        //     else {
        //         return false;
        //     }
        // }
        // return true;

        // better solution

        for (int i = 0; i < n; i++) {
            if (isSorted(arr))
                return true;
            else {
                int first = arr[0];
                for (int j = 0; j < n - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                arr[n - 1] = first;
            }
        }
        return false;
    }
};