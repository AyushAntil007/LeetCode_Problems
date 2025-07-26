class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();

        int i=n-1;
        int start=0;
        int end=n-1;

        string ans="";

        while(i>=0){
            while(i>=0&& num[i]%2==0)i--;
            end=i;
            if(start<=end){
                ans+=num.substr(start,end-start+1);
                break;
            }
        }
        return ans;
        
    }
};