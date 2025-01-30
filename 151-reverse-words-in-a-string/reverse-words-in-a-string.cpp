class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        int start = 0;
        int end = 0;
        int i = 0;

        stack<string> st;

        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            start = i;
            while (i < n && s[i] != ' ') {
                i++;
            }
            end = i;
            if (start < end) { // Ensure a word was found
                st.push(s.substr(start, i - start));
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty())
                ans += " "; // Add space between words
        }

        return ans;
    }
};