/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void func(TreeNode* node,TreeNode* target,set<TreeNode*>&target_set){
        if(node==NULL) return;
        target_set.insert(node);
        if(node==target){
            return;
        }
        if(node->val<target->val)
            func(node->right,target,target_set);
        else
            func(node->left,target,target_set);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        set<TreeNode*>p_set;
        set<TreeNode*>q_set;
        func(root,p,p_set);
        func(root,q,q_set);
        int LCA=INT_MAX;
        TreeNode* ans=NULL;
        for (auto it = p_set.rbegin(); it != p_set.rend(); it++) {
            TreeNode* temp=*it;
            if(q_set.find(temp)!=q_set.end())
               return temp;
        }
        return NULL;
    }
};