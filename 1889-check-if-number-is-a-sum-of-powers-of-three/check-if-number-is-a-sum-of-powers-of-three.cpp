class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i=0;
        int a;
        set<int>st;
        while(n>=0){
                
                a=pow(3,i);
                i++;
                if(a==n){
                    if(st.find(a)!=st.end())return false;
                    st.insert(a);
                    n=n-a;
                    i=0;
                }
               else if(a>n){
                    if(st.find(a/3)!=st.end())return false;
                    st.insert(a/3);
                    n=n-(a/3);
                    i=0;
                }
                if(n==0)return true;
                if(n==2||n<0)return false;
        }
        return false;
    }
};