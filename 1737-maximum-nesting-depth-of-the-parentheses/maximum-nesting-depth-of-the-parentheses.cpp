class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
                ans=max(cnt,ans);
            }
            if(s[i]==')'){
                cnt--;
            }
        }
        return ans;
    }
};