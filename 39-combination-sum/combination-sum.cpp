class Solution {
public:
    void comb(int i, int t, vector<int>& cand, vector<int>& store,
              vector<vector<int>>& ans) {

        if (i >= cand.size() || t < 0) // boundary conditions
            return;
        if (t == 0) { // when target becomes zero
            ans.push_back(store);
            return;
        }

        store.push_back(cand[i]);
        t -= cand[i];
        comb(i, t, cand, store,
             ans); // taking same element  and ....reduce the target
        store.pop_back();
        t += cand[i];

        comb(i + 1, t, cand, store, ans); // not taking the same element
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> store;

        comb(0, target, cand, store, ans);
        return ans;
    }
};