class Solution {
public:
    void comb(int i, int t, vector<int>& cand, vector<int>& store,
              vector<vector<int>>& ans) {

        if (t == 0) { // when target becomes zero
            ans.push_back(store);
            return;
        }
        for (int j = i; j < cand.size(); j++) {
            if (j > i && cand[j] == cand[j - 1])        //skipping the same elts
                continue;
            if (cand[j] > t)                            //when elt greater than the target
                break;
            store.push_back(cand[j]);
            comb(j+1, t - cand[j], cand, store, ans);   //pass index i as j+1....
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());       //sort the elemnts for easy handling of duplicates
        vector<vector<int>> ans;
        vector<int> store;

        comb(0, target, cand, store, ans);
        return ans;
    }
};