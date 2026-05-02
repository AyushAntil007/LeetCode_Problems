class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char , int> freq;

        int maxLen = 0;

        int i=0 , j=0;

        while(j < n){
            freq[s[j]]++;

           
                while(freq[s[j]] > 1 && i < j) {
                    freq[s[i]]--;
                    i++;
                }
            

            maxLen = max(maxLen, j - i + 1);

            j++;

        }
        return maxLen;
    }
};