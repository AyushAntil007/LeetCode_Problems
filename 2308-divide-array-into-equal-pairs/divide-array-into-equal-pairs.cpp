class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;

        for(int i=0;i<n;i++){
            freq[nums[i]]++;

        }
        int count=0;
        for(auto it: freq){
            if(it.second % 2 != 0) return false; 
        }
        return true;
   
    }
}; 
// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         unordered_map<int, int> counter;
//         for (int num : nums) {
//             counter[num]++;
//         }
        
//         for (const auto& [_, count] : counter) {
//             if (count % 2 != 0) {
//                 return false;
//             }
//         }
        
//         return true;
//     }
// }; 