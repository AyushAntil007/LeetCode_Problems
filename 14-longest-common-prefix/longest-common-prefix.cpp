class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";

        int i = 0;
        string ans = "";
        while (true) {

            if(i>=strs[0].length())return ans;

            char prev = strs[0][i]; // pehli string k chars se saare compare karva rahe hai
            for (string s : strs) {
                if (i>=s.length()||s[i] != prev) {
                    return ans;
                }
            }
                ans += prev;
                i++;
            
        }
        return "";
    }
};