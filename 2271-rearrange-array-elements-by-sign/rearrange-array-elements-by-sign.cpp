class Solution {
public:
    vector<int> rearrangeArray(vector<int>& A) {
        int n = A.size();

        // brute force
        // vector<int> pos;
        // vector<int> neg;

        // for (int i = 0; i < n; i++) { // Segregate the array into positives
        // and negatives.
        //     if (A[i] > 0)
        //         pos.push_back(A[i]);
        //     else
        //         neg.push_back(A[i]);
        // }

        // for (int i = 0; i < n / 2; i++) { // Positives on even indices,
        // negatives on odd.
        //     A[2 * i] = pos[i];
        //     A[2 * i + 1] = neg[i];
        // }
        // return A;

        // optimal sol
        vector<int> ans(n, 0); //**********jab hame vector ke index k sath
                               //*********khelna hai toh in itialise size of vector
        int posidx = 0;
        int negidx = 1;

        for (int i = 0; i < n; i++) {
            if (A[i] >= 0) {
                ans[posidx] = A[i];
                posidx += 2;
            } else {
                ans[negidx] = A[i];
                negidx += 2;
            }
        }
        return ans;
    }
};