class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxLen=0;
        vector<int>idx(256,-1);

        int l=0, r=0;

        while(r<n){
            if(idx[s[r]]>=l){
                l=idx[s[r]]+1;
                
            }
            
            maxLen=max(maxLen,r-l+1);
            idx[s[r]]=r;
            r++;
        }

        return maxLen;
    }
};