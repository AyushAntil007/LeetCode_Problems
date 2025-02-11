class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.length();
        int m=part.length();
        
        string st;
        
        for(int i=0;i<n;i++){
            st.push_back(s[i]);
            
            if(st.size()>=m && st.substr(st.size()-m)==part){
                st.erase(st.size()-m);
            }
            
        }
       return st;
    }
};