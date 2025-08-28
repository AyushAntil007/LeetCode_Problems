class Solution {
public:

int solve(string s, int k){

    int n=s.length();
    int cnt=0;
    unordered_map<char,int>freq;

        int right=0,left=0;

        while(right<n){
            freq[s[right]]++;

            while(freq.size()>k){
                freq[s[left]]--;
                if(freq[s[left]]==0)freq.erase(s[left]);
                left++;
            }
            if(freq.size()<=k)cnt+=right-left+1;
            right++;
        }
        return cnt;
}
    int numberOfSubstrings(string s) {
        

        // int n=s.length();
        // int cnt=0;

        

        // for(int i=0; i<n; i++){
        //     unordered_map<char,int>freq;
        //     for(int j=i; j<n; j++){

        //         freq[s[j]]++;
        //         if(freq.size()==3){
        //             cnt++;
        //         }

        //     }
            
        // }
        int k=3;
        return solve(s,k)-solve(s,k-1);

       
    }
};