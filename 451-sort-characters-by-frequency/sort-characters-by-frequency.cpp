class Solution {
public:
static bool st(pair<char,int>& a,pair<char,int>& b){
        if (a.second == b.second)  return a.first < b.first;
        return a.second > b.second;
    }

    string frequencySort(string s) {
        string ans="";
       unordered_map<char,int>freq;

        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        vector<pair<char,int>> arr(freq.begin(),freq.end());
        sort(arr.begin(),arr.end(),st);  //  sort acc. to frequency then acc. to their ascii

        for( auto i : arr){
            int f=i.second;
            char ch=i.first;

            for(int j=0;j<f;j++){
                ans+=ch;
            }
        }
        return ans;
    }
};