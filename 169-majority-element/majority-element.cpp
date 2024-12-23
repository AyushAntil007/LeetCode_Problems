class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();

        // brute force

        // for (int i = 0; i < n; i++) {
        //     int cnt = 0;
        //     for (int j = 0; j < n; j++) {
        //         if (v[j] == v[i]) {
        //             cnt++;     // counting the frequency of v[i]
        //         }
        //     }
        //     if (cnt > (n / 2))    // check if frquency is greater than n/2:
        //         return v[i];
        // }
        // return -1;

        // better solution

        // map<int, int> mpp;

        // for (int i = 0; i < n; i++) {
        //     mpp[v[i]]++;
        // }
        // for (auto it : mpp) {
        //     if (it.second > (n / 2)) {
        //         return it.first;
        //     }
        // }
        // return -1;

        // optimal solution

        // Moore’s Voting Algorithm:

        int elt = v[0];
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] == elt)
                cnt++;   //frequency of elt
            else
                cnt--;   //cancelling the non mazority elts with mazority elt

            if (cnt == 0) {
                elt = v[i + 1];
            }
        }
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == elt)   
                cnt++;
        }
        if (cnt > n / 2)   //checking valid mazor elt or not
            return elt;
        return -1;
    }
};