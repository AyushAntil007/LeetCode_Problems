class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();

        if(s.empty())return s;
        string ans="";

        int start,end;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(cnt==0)start=i;
            if(s[i]=='(')cnt++;
            else{
                cnt--;
                if(cnt==0){
                    end=i;
                    ans+=s.substr(start+1,end - start - 1);
                }
            }
        }
        return ans;
    }
};