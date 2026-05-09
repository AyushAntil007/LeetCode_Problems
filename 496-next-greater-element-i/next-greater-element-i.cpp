class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int  n2 = nums2.size();

        stack<int>st;

        unordered_map<int,int>mpp;

        for(int i=n2-1; i>=0; i--) {

            while(!st.empty() && nums2[i] > st.top())st.pop();
            
            

            if(!st.empty() && nums2[i]< st.top())mpp[nums2[i]] = st.top();

            if(st.empty())mpp[nums2[i]]=-1;

            st.push(nums2[i]);
        }

        for(auto &it : mpp) {
            cout<<it.first <<" "<<it.second<<endl;
        }

      vector<int>ans;
        

        for(int i=0; i<nums1.size(); i++) {
            if(mpp[nums1[i]])ans.push_back(mpp[nums1[i]]);
            

        }

        return ans;
    }
};