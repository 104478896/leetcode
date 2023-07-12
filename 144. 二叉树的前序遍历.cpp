/*给你二叉树的根节点 root ，返回它节点值的 前序 遍历。*/
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
    void front(TreeNode* cur,vector<int>&ans){
        if(!cur){
            return ;
        }
        ans.push_back(cur->val);
        front(cur->left,ans);
        front(cur->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        front(root,ans);
        return ans;
    }
};