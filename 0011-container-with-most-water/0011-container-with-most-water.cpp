class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        int sum;
        while(i<j){
            sum=min(height[i],height[j])*(j-i);
            ans=max(sum,ans);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};