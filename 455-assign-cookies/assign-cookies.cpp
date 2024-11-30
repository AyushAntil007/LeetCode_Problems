class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=0,m=0;
        int count=0;
        while(n<g.size()&&m<s.size()){
            if(g[n]<=s[m]){
                count++;
                n++;
                m++;
            }
            else{
                m++;
            }
        }
        return count;
    }
};