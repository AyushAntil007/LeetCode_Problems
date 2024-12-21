class Solution {
public:
bool isPal(int idx,int lidx,string &s){
    while(idx<=lidx){
        if(s[idx]!=s[lidx]){
            return false;
        }
        else{
            idx++;
            lidx--;
        }
        
    }
    return true;
}
    void solve(int idx,string &s,vector<string>&pali,vector<vector<string>>&ans,int n){
        if(idx==n){
            ans.push_back(pali);
            return;
        }
        for(int i=idx;i<n;i++){    //partition at every index
           if(isPal(idx,i,s)){
            pali.push_back(s.substr(idx,i-idx+1));  //s.substr(start, length)
            solve(i+1,s,pali,ans,n);
            pali.pop_back();
           }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<string>pali;
        vector<vector<string>>ans;
        solve(0,s,pali,ans,n);
        return ans;
    }
};