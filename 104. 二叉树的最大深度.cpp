/*给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。*/
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
    int dp(TreeNode* root){
        if(!root){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        int left=dp(root->left);
        int right=dp(root->right);
        return max(left,right)+1;
    }
    int maxDepth(TreeNode* root) {
        
        int ans=dp(root);
        return ans;
    }
};