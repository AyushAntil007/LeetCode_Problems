class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
         int n = questions.size();
        vector<long long> dp(n + 1, 0); // DP array to store the maximum points
        
        for (int i = n - 1; i >= 0; --i) {
            int next = i + questions[i][1] + 1; // Next available question index
            long long take = questions[i][0] + (next < n ? dp[next] : 0); // Taking the question
            long long skip = dp[i + 1]; // Skipping the question
            dp[i] = max(take, skip); // Store the best result
        }
        
        return dp[0]; // Max points starting from the first question
    }
};