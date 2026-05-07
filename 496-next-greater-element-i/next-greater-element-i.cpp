class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();

        stack<int>st;

        unordered_map<int,int> mpp;

        for(int i= n2-1; i>=0; i--) {

            

            while(! st.empty() && st.top()< nums2[i]) st.pop();

            if(st.empty())mpp[nums2[i]] = -1;

            else if(nums2[i] < st.top())mpp[nums2[i]]=st.top();

            st.push(nums2[i]);

        }

        vector<int>ans;

        for(int i=0; i<nums1.size(); i++) {
            if(mpp.count(nums1[i])) ans.push_back(mpp[nums1[i]]);

            else ans.push_back(-1);
    }

    return ans;
            
    }
};