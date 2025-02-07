class Solution {
public:
    int romanToInt(string s) {

        
        unordered_map<char,int>prior;

        prior['I']=1;
        prior['V']=5;
        prior['X']=10;
        prior['L']=50;
        prior['C']=100;
        prior['D']=500;
        prior['M']=1000;

        int n=s.size();
        int digit=prior[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(prior[s[i]]<prior[s[i+1]]){
                 digit-=prior[s[i]];
            }
            else{
                digit+=prior[s[i]];
            }
        }
        return digit;
    }
};