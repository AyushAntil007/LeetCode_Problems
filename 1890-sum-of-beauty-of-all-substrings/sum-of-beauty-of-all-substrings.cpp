class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int beauty = 0;
        for (int i = 0; i < n; i++) {   //cfreate substring by nested for loops
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;   // frequency count
                int maxi = *max_element(freq.begin(), freq.end());   //find max
                int mini = INT_MAX;
                for (auto it : freq) {
                    if (it > 0)    //ignore 0's char
                        mini = min(it, mini);
                }
                beauty += maxi - mini;
            }
        }
        return beauty;
    }
};