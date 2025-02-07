class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // brute force......put nums2 in nums1 and sort
        //  for(int i=m;i<m+n;i++){
        //      nums1[i]=nums2[i-m];
        //  }
        //  sort(nums1.begin(),nums1.end());

        // beter solution....using extra array

        //     vector<int>dup(m+n);
        //     int i=0,j=0;
        //     int idx=0;
        //     while(i<n&&j<m){
        //         if(nums1[i]<nums2[j]){
        //             dup[idx]=(nums1[i]);
        //             i++,idx++;
        //         }
        //         else{
        //             dup[idx]=(nums2[j]);
        //             j++,idx++;
        //         }
        //     }
        //     while(i<m){
        //         dup[idx]=(nums1[i]);
        //         i++,idx++;
        //     }
        //     while(j<n){
        //          dup[idx]=(nums2[j]);
        //         j++,idx++;
        //     }

        //    for(int i=0;i<m+n;i++){
        //     nums1[i]=dup[i];
        //    }

        // better sol

        int i = m-1, j = 0;
        while (i>=0 && j < n) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[i],nums2[j]);
                i--,j++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(), nums1.begin() + m); // Sort the valid part of nums1
        sort(nums2.begin(), nums2.end());

        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
         }

        // gap method or   shell sort


        


    }
};