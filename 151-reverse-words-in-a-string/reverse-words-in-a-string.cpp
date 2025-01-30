class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
       string ans="";
        stack<string> st;

        // my approach....using set
        //  int start = 0;
        //  int end = 0;
        //  int i = 0;

        // while (i < n) {
        //     while (i < n && s[i] == ' ') {
        //         i++;
        //     }
        //     start = i;
        //     while (i < n && s[i] != ' ') {
        //         i++;
        //     }
        //     end = i;
        //     if (start < end) { // Ensure a word was found
        //         st.push(s.substr(start, end - start));
        //     }
        // }

        //  while (!st.empty()) {
        //     ans += st.top();
        //     st.pop();
        //     if (!st.empty()) ans += " "; // Add space between words
        // }

//optimal sol.....traverse from back
         int start = n-1;
         int end = n-1;
         int i = n-1;

        while (i >=0) {
            while (i >=0 && s[i] == ' ') {
                i--;
            }
            end = i;
            while (i >=0 && s[i] != ' ') {
                i--;
            }
            start = i;
            if (start < end) { // Ensure a word was found
               ans+=s.substr(start+1,end-start)+' ';
            }
        }
        if (!ans.empty()) ans.pop_back(); // Remove trailing space
        return ans;
    }
};