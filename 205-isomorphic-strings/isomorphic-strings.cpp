class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length())
            return false;

        unordered_map<char, char> mpps, mppt;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            
            //. No two characters may map to the same character, but a character may map to itself.
            if (mpps.count(c1) && mpps[c1] != c2)
                return false;
            if (mppt.count(c2) && mppt[c2] != c1)
                return false;
            mpps[c1] = c2;
            mppt[c2] = c1;
        }

        return true;
    }
};