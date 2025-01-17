class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();

        // brute force
        //  vector<int> ls;

        // for (int i = 0; i < n; i++) {
        //     int cnt = 0;
        //     if (ls.size() == 0 ||
        //         ls[0] != v[i]) { // as max two elts that can be > n/3
        //         for (int j = 0; j < n; j++) {
        //             if (v[j] == v[i]) {
        //                 cnt++;
        //             }
        //         }
        //         if (cnt > (n / 3))
        //             ls.push_back(v[i]);
        //     }
        // }

        // return ls;

        // better sol
        //  vector<int>ls;
        //  unordered_map<int ,int>freq;
        //  for(int i=0;i<n;i++){
        //      freq[v[i]]++;
        //  }
        //  // for(int i=0;i<n;i++){      //***it will count duplicate also
        //  //     if(freq[v[i]]>n/3){
        //  //        ls.push_back(v[i]);
        //  //     }
        //  // }

        // for(auto it:freq){          //*****avoid duplicates
        //     if(it.second>n/3){
        //         ls.push_back(it.first);
        //     }
        // }
        // return ls;

        // Optimal Approach (Extended Boyer Moore’s Voting Algorithm):

        int elt1, elt2, cnt1 = 0, cnt2 = 0;

        vector<int> ls;
        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && v[i] != elt2) {  // when elt is fully cancelled
                cnt1 = 1;
                elt1 = v[i];
            } else if (cnt2 == 0 && v[i] != elt1) {
                cnt2 = 1;
                elt2 = v[i];
            } else if (v[i] == elt1) {  //frequency
                cnt1++;
            } else if (v[i] == elt2) {  //frequency
                cnt2++;
            } else {     //cancelling
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == elt1) {
                cnt1++;
            }
            if (v[i] == elt2) {
                cnt2++;
            }
        }
         if (cnt1 > n / 3) ls.push_back(elt1);
        if (cnt2 > n / 3 && elt1 != elt2) ls.push_back(elt2);   //  check for duplicate

        return ls;
    }
};