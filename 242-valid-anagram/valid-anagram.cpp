class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;

// brute force......using hashing
        unordered_map<char,int>freq;
    
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        for(int j=0;j<t.length();j++){
            if(freq[t[j]]==0)return false;
           freq[t[j]]--;

        }
        return true;

// better sol.....using sort

        // sort(t.begin(),t.end());
        // sort(s.begin(),s.end());
        // if(t==s)return true;
        // return false;
    }
};