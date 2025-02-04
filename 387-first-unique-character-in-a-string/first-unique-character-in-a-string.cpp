class Solution {
public:

int solve(vector<int>ans,string s){
    for(int i=0;i<s.size();i++){
        ans[s[i]]++;
    }
    for(int i=0;i<s.size();i++){
        if(ans[s[i]]==1)return i;
    }
    return -1;
}
    int firstUniqChar(string s) {
        vector<int>ans(256,0);

        int idx=solve(ans,s);
        return idx;
    }
};