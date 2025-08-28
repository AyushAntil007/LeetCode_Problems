class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0;
        unordered_map<char,int>freq;
       int len = 0;

        int maxfreq = 0; // add this before the while loop


        while(right<s.length()){
            freq[s[right]]++;

           maxfreq=max(maxfreq,freq[s[right]]);

           while(right-left+1 - maxfreq >k){
                freq[s[left]]--;
               
                left++;
            }
            len=max(right-left+1, len);
            right++;

        }

        return len;
    }
};