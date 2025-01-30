class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        int start=0;
        int end=0;

        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){

            if(s[i]=='('){
                count++;
                if(count==1){
                    start=i;
                }
            }
            else{
                count--;
                if(count==0){
                    end=i;
                }
            }
            if(count==0){
               ans+= s.substr(start + 1, end - start - 1);
            }
        }
        return ans;
    }
};