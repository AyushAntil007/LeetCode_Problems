class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
    
        while(!q.empty()){
            string word=q.front().first;
            int step=q.front().second;
            q.pop();

            if(word==endWord)return step;   //last word mil gya hai

            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;            //make changes in each char one by one
                    if(st.find(word)!=st.end()){
                        q.push({word,step+1});     //if present in set then pus and erse from set
                        st.erase(word);             //erase ..visited ki trah kaam karega
                    }
                }
                word[i]=original;   //isko waapis original word bna do....undo changes
            }
        }
        return 0;
    }
};