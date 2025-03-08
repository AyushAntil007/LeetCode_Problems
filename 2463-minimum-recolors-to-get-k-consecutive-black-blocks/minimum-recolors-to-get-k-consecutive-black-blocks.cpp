class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        string wind="";

        if(k>n)return -1;

        int count=0;
        int ans=INT_MAX;

        for(int i=0;i<k;i++){
            wind+=blocks[i];
            if(blocks[i]=='B'){
                    continue;
                }
                else{
                    count++;
                }
        }
        ans=min(count,ans);

        for(int j=k;j<n;j++){
            count=0;
            wind.erase(0,1);
            wind.push_back(blocks[j]);
            for(int i=0;i<k;i++){
                if(wind[i]=='B'){
                    continue;
                }
                else{
                    count++;
                }
            }
            ans=min(count,ans);
           
        }
        return ans;
    }
};