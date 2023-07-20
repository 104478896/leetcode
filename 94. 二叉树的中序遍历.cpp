/*给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。*/
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
    void mid(TreeNode* root,vector<int>&ans){
        if(!root){
            return ;
        }
        mid(root->left,ans);
        ans.push_back(root->val);
        mid(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        mid(root,ans);
        return ans;
    }
};