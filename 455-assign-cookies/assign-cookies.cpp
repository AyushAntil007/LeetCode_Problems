class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int l1 =g.size();
        int l2= s.size();

        int i=0, j=0;

        int cnt=0;

        while(i<l1&& j<l2){
            if(g[i]<=s[j]){
                cnt++;
                i++,j++;
            }
            else j++;
        }

        return cnt;
    }
};