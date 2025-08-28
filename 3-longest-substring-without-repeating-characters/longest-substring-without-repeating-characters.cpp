class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;
        

        int left=0,right=0;
        unordered_map<char,int>freq;

        int len=INT_MIN;

        while(right<s.size()){
            freq[s[right]]++;
            while(freq[s[right]]>1){
                freq[s[left]]--;
                if(freq[s[left]]==0)freq.erase(s[left]);
                left++;
            }
            len=max(right-left+1, len);
            right++;

        }

        return len;
    }
};