class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal )return true;
        int n=s.length();
        


        // for(int i=0;i<n;i++){
        //     char ch=s[0];
        //     for(int i=0;i<n-1;i++){
        //         s[i]=s[i+1];
        //     }
        //     s[n-1]=ch;
        //     if(s==goal)return true;
        // }
        // return false;



        ///optimal sol.......

       if (s.length() != goal.length()) return false;

        string doubled = s + s;

        // Check if goal is a substring of doubled using a sliding window
        for (int i = 0; i < s.length(); i++) {
            if (doubled.substr(i, s.length()) == goal) {
                return true;
            }
        }

        return false;

    }
};