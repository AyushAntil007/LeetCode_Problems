class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return s;

        int n=s.length();
        string ans="";
        int start=n-1,end=n-1;
       int i=n-1;

        while(i>=0){
            while(i>=0&&s[i]==' ' )i--;

    


            end=i;
            while( i>=0&&s[i]!=' '){
                i--;
                
            }
            start=i+1;
            
           if(start<=end) {
            ans+=s.substr(start,end-start+1)+" ";
           }
        }
           
        
        if(!ans.empty())ans.pop_back();

        return ans;
        
    }
};