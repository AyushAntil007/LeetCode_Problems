class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int m=nums1.size();
        stack<int>st;

        vector<int>ans;

       unordered_map<int,int>mpp;

        for(int i=n-1; i>=0; i--){
            

            while(!st.empty()  && nums2[i]>=st.top())st.pop();
            if(st.empty())mpp[nums2[i]]=-1;
            else{
               mpp[nums2[i]]=st.top();
            }
            

            st.push(nums2[i]);
        }

        for(auto it: nums1)ans.push_back(mpp[it]);

        return ans;
    }
};