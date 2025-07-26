class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0||n==1)return strs[0];

        
        string first=strs[0];
        
        for(int j=0;j<first.length();j++){
            
            for(int i=1;i<n;i++){
                string next=strs[i];
                if(j>=next.length()||first[j]!=next[j]){
                    return first.substr(0,j);
                }
            }
            
        }

        return first;
        
    }
};