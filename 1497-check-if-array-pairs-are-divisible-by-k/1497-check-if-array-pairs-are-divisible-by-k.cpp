class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size()/2;
        unordered_map<int,int>hash;
        for(int i=0;i<arr.size();i++){
            int val=((arr[i]%k)+k)%k;
            hash[val]++;
        }
        for(int i=0;i<hash.size();i++){
            if(i==0){
                if(hash[i]%2!=0)
                    return false;
            }
            else{
                if(hash[i]!=hash[(k-i)])
                return false;
            }
            
        }
        return true;
        
    }
};