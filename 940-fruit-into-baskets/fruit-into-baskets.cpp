class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        

        int n = fruits.size();

        unordered_map<int,int> freq;

        int left =0, right = 0;

        int maxFruits = INT_MIN;

        while(right < n) {
            freq[fruits[right]]++;

            while( freq.size() > 2) {

                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0) freq.erase(fruits[left]);

                left++;

            }
            
            int sum = 0;

            for (auto &it : freq) {
               sum += it.second;
            }

            maxFruits = max(maxFruits, sum);

            right++;
        }

        return maxFruits;
    }
};