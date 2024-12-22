class Solution {
public:
    int singleNumber(vector<int>& arr) {
        

        int n = arr.size();

   //brute force

    // for (int i = 0; i < n; i++) {
    //     int num = arr[i]; //select elt
    //     int cnt = 0;

    //     for (int j = 0; j < n; j++) {
    //         if (arr[j] == num)
    //             cnt++;   //frequency of elt
    //     }
    //     if (cnt == 1) return num;  //elt occur at once
    // }
    // return -1;


    //better solution-1......hashing

    // int maxi = arr[0];
    // for (int i = 0; i < n; i++) {
    //     maxi = max(maxi, arr[i]);
    // }

    // vector<int> freq(maxi + 1, 0);
    // for (int i = 0; i < n; i++) {
    //    freq[arr[i]]++;
    // }

    // for (int i = 0; i < n; i++) {
    //     if (freq[arr[i]] == 1)  //if frequency is one
    //         return arr[i];
    // }
    // return -1;


    //better solution-.....map

    // map<int, int> mpp;
    // for (int i = 0; i < n; i++) {
    //     mpp[arr[i]]++;
    // }

    // for (auto it : mpp) {
    //     if (it.second == 1)
    //         return it.first;
    // }
    // return -1;


    //optimal solution

    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];   //ek elt bach jayga sabhi elt katne k baad
    }
    return xorr;

    }
};