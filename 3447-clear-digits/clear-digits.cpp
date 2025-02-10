class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        stack<char>st;

        for(int i=0;i<n;i++){
            if(s[i]>='a'&& s[i]<='z'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        s="";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};