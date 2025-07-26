class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.length();
        int n2=t.length();

        unordered_map<char,int>mpps;
        unordered_map<char,int>mppt;

        for(int i=0;i<n1;i++){

            if(mpps.find(s[i])!=mpps.end()){
                if(mpps[s[i]]!=t[i])return false;
            }
            if(mppt.find(t[i])!=mppt.end()){
                if(mppt[t[i]]!=s[i])return false;
            }
            mpps[s[i]]=t[i];
            mppt[t[i]]=s[i];


        }
        return true;
    }
};