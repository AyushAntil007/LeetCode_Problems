class Solution {
public:
    void solve(int idx, string &digits, vector<string> &ans, string &layer, unordered_map<char, string> &mpp) {
        if (idx == digits.size()) {
            ans.push_back(layer);
            return;
        }

        string letters = mpp[digits[idx]];
        for (char c : letters) {
            layer.push_back(c);
            solve(idx + 1, digits, ans, layer, mpp);
            layer.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        unordered_map<char, string> mpp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        string layer;
        solve(0, digits, ans, layer, mpp);
        return ans;
    }
};
