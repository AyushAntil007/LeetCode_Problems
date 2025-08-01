class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();

        if(n==0||n==1)return n;
        int len=0;
        

        for(int i=0;i<n;i++){
            set<int>st;
            for(int j=i;j<n;j++){
                if(st.find(s[j])!=st.end()){
                     len=max(len,j-i);
                    break;
                    
                }
                
                st.insert(s[j]);
                
            }
            len=max(len,(int)st.size());
        }
       
       return len;
    }
};