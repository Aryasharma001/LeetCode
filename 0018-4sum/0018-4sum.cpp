class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int>:: iterator i;
        vector<int>:: iterator j;
        vector<int>:: iterator start;
        vector<int>:: iterator end;

        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for( i = nums.begin() ; i!=nums.end() ; i++ ){
            for(j = i+1 ; j !=nums.end() ; j++ )
            {
                start = j+1;
                end = nums.end() -1; 
                
                long long target2 = target - *i;
                target2 = target2 - *j ;

                while(end>start)
                {
                    if(*start +*end== target2)
                    {
                        vector<int> v = {*i,*j,*start,*end};
                        ans.insert(v);
                        start++; end--;

                    }
                    else if(*start +*end > target2)
                    {
                        end --;
                    }
                    else 
                    {
                        start ++;
                    }
                }

                 

            }
        }
        vector<vector<int>> vans (ans.begin() , ans.end());
        return vans;

    }
};