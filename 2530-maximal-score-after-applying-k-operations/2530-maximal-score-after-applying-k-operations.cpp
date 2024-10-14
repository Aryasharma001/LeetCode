class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq;
        long long score=0;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++){
            int topScore=pq.top();
            //cout<<topScore<<endl;
            pq.pop();
            score+=topScore;
            if(topScore%3!=0){
                pq.push((topScore/3)+1);
            }
            else
                pq.push((topScore/3));
        }
        return score;
    }
};