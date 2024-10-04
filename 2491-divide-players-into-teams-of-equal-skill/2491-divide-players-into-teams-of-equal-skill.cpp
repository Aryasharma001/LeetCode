class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int,int>hash;
        int n=skill.size();
        long long total_sum=0;
        if(n==2){
            return skill[0]*skill[1];
        }
        for(int i=0;i<n;i++){
            hash[skill[i]]++;
            total_sum+=skill[i];
        }
        long long product=0;
        long long sum_per_pair=(total_sum/(n/2));
        for(auto it:hash){
            while(hash[it.first]>0){
                if(hash[(sum_per_pair-it.first)]==hash[it.first]){
                    if(hash[it.first]>0 && hash[sum_per_pair-it.first]>0){
                        product+=(it.first)*(sum_per_pair-it.first);
                        hash[(sum_per_pair-it.first)]--;
                        hash[it.first]--;
                    }
                }
                else
                    return -1;

            }
        }
        return product;
    }
};