class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();

        int len=0;

        

        // for(int i=0;i<n;i++){
        //     unordered_map<int,int>freq;
        //     for( int j = i; j<n; j++){
        //         freq[fruits[j]]++;
        //         if(freq.size()>2)break;
        //         else{
                    
        //             len=max(len,j-i+1);
        //         }
        //     }
        // }


        // 2 pointer

        int l=0,r=0;
        unordered_map<int,int>freq;

        while(r < n){
            freq[fruits[r]]++;
            if(freq.size()>2){
                  freq[fruits[l]]--;
                  if(freq[fruits[l]]==0){
                    freq.erase(fruits[l]);

                  }
                  l++;
            }
            if(freq.size()<=2){
                len=max(len,r-l+1);
            }
            r++;
        }
        return len;
    }
};