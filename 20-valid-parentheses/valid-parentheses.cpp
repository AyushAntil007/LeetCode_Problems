#include<stack>
class Solution {
public:
stack<int>st;
    bool isValid(string s) {
        
        int n=s.length();
        if(n==1){
            return false;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                int close=st.top();
                if((close=='('&&s[i]==')')||(close=='['&&s[i]==']')||(close=='{'&&s[i]=='}')){
                    st.pop();
                }
                else {
                    return false;
                }
                }
                else {
                   return false;
                }
            }
        }
        return st.empty();
    }
};