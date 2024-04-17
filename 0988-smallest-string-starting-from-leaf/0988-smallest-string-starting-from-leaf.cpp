/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void findAllStrings(TreeNode* node,string &curr,set<string>&paths){
        if(node->left==NULL && node->right==NULL){
            curr+=char(node->val+'a');
            paths.insert(curr);
            curr.pop_back();
            return;
        }
        char c=char(node->val+'a');
        curr+=c;
        if(node->left)findAllStrings(node->left,curr,paths);
        if(node->right)findAllStrings(node->right,curr,paths);
        curr.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string curr="";
        set<string>paths;
        vector<string>ans;
        findAllStrings(root,curr,paths);
        for(auto it:paths){
            reverse(it.begin(),it.end());
            ans.push_back(it);
            cout<<it<<" ";
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};