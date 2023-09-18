class Solution {
public:
   void f(int i, std::vector<int>& arr, std::vector<int>& count, std::vector<std::vector<int>>& ans, int target) {
    if (target == 0) {
        ans.push_back(count);
        return;
    }

    for (int j = i; j < arr.size(); j++) {
        if (j > i && arr[j] == arr[j - 1]) {
            continue;
        }
        if (arr[j] > target) {
            break; // Optimization: Stop if the current element is greater than the remaining target.
        }
        count.push_back(arr[j]);
        f(j + 1, arr, count, ans, target - arr[j]);
        count.pop_back();
    }
}




    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>count;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        f(0,candidates,count,ans,target);
        return ans;
    }
};