class Solution {
public:
    int myAtoi(string s) {
        
        long long digit=0;
        bool neg=false;
        bool pos=false;

        
        int n=s.size();
        
        int i=0;

        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='+'|| s[i]=='-')){
            if(s[i]=='+')pos=true;
            if(s[i]=='-')neg=true;
            i++;
        }

        while(i<n){
           if(s[i]>='0'&&s[i]<='9'){
                digit=digit*10+(s[i]-'0');
                if(digit>INT_MAX){
                    if(neg)return INT_MIN;
                    else return INT_MAX;
                }    
            }
            else {
              break;
            }
            i++;
        }
        

        if(neg)digit=-digit;
        return digit;
    }
};