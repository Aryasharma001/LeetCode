class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        vector<int>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                st.push(nums[i]);
            }
            else{
               
                while (!st.empty() && st.top() > 0 && st.top() < abs(nums[i])) {
                   
                    st.pop();
                }
                
                if (!st.empty() && st.top() == abs(nums[i])) {
                    
                    st.pop();
                } else if (st.empty() || st.top() < 0) {
                    
                    st.push(nums[i]);
                }
                
            }
          
            
        }
         while(!st.empty()){
               v.push_back(st.top());
               st.pop();
           }
        reverse(v.begin(),v.end());

        return v;
        
    }

};