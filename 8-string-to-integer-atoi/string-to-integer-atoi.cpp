class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();

        bool neg=false;

        int i=0;

        while(i<n && s[i]==' ')i++;

        if(i<n&& s[i]=='-'){
            neg=true;
            i++;
        }
        if(i<n && !neg && s[i]=='+')i++;

        while(i<n && s[i]=='0')i++;

       long long nums=0;

        for(int j=i; j<n; j++){
            if(s[j]<='9'  && s[j]>='0'){
                 nums=nums*10+s[j]-'0';
                if(nums > INT_MAX )
                   return neg ? INT_MIN : INT_MAX;
               
                
            }
            else break;
        }

        return neg?-nums:nums;




    }
};