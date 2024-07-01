class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2!=0 && i<arr.size()-1 && i>0){
                if(arr[i-1]%2!=0 && arr[i+1]%2!=0)
                    return true;
            }
        }
        return false;
    }
};