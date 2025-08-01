class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        

        unordered_map<int,int>freq;
        int n=fruits.size();

        int ans=INT_MIN;


        int left=0;
        int right=0;

        while(right<n){
            freq[fruits[right]]++;
            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0){
                    freq.erase(fruits[left]);  // ✅ Correct: erase by key

                }

                left++;

            }

            int len=right-left+1;
            right++;

            ans=max(ans,len);
        }

        return ans;
    }
};