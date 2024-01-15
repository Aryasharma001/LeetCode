class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>hash(1000001,0);
        set<int>winners;
        vector<int>losers;
        for(auto it:matches){
            winners.insert(it[0]);
            losers.push_back(it[1]);
        }
        set<int>loser;
        vector<vector<int>>ans;
        vector<int>answer0;
        vector<int>answer1;
        for(int i=0;i<losers.size();i++){
            loser.insert(losers[i]);
            hash[losers[i]]++;
        }
        for(int i=0;i<hash.size();i++){
            if(hash[i]==1)
                answer1.push_back(i);
        }
        for(auto it:winners){
            if(loser.find(it)==loser.end())
                answer0.push_back(it);
        }
        
        ans.push_back(answer0);
        ans.push_back(answer1);
        return ans;
    }
};