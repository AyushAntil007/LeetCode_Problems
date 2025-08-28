class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int tmax=0;
        int sum=0;

        int n=card.size();
        if(k>n)return 0;

        for(int i=0; i<k; i++)sum+=card[i];

        tmax=max(tmax,sum);
        

        int right=n-1;
        for(int i=k-1; i>=0; i--){
            sum-=card[i];
            sum+=card[right];
            right--;
            

            tmax=max(sum,tmax);
        }

        return tmax;
    }
};