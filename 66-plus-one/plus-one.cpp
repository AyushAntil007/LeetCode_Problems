class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int n=digits.size();
        vector<int>ans;

        for(int i=n-1;i>=0;i--){
            int elt=carry+digits[i];
            carry=elt/10;
            ans.push_back(elt%10);
        }
        if(carry){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};