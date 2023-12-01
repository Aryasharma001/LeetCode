class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word_1="";
        string word_2="";
        for(auto it:word1){
            word_1+=it;
        }
        for(auto it:word2){
            word_2+=it;
        }
        return (word_1==word_2);
    }
};