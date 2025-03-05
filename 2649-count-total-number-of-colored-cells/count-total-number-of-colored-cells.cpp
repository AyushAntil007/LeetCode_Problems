class Solution {
public:
    long long coloredCells(int n) {
        if(n==1)return 1;
        long long ans;
        ans=(long long)n*(2*(n-1))+1;
        return ans;
    }
};