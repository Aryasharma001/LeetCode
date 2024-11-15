class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int prefixSub=0;
        //prefix
        while(prefixSub+1<n && arr[prefixSub]<=arr[prefixSub+1]){
            prefixSub++;
        }
        if(prefixSub==n-1)
            return 0;
        int suffixSub=n-1;
        //suffix
        while(suffixSub>=0 && arr[suffixSub-1]<=arr[suffixSub])
            suffixSub--;
        int result=min(n-prefixSub-1,suffixSub);
        int i = 0, j = suffixSub;
        while (i <= prefixSub && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};