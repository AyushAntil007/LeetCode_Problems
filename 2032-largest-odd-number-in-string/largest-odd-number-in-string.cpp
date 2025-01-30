class Solution {
public:
    string largestOddNumber(string num) {
        
        int n=num.length();

        int start=0;
        int end=n-1;
        
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(num[i]%2==0){
                end--;
            }
            else{
                if(start<=end){
                    ans+=num.substr(start,end+1);
                    return ans;
                }
            }
        }
        return "";
    }
};