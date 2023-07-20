/*给定二叉树的根节点 root ，返回所有左叶子之和。*/
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
    int ans=0;
    int add(TreeNode* root){
        if(!root){
            return 0;
        }
        if((!root->left)&&(!root->right)){
            return root->val;
        }
        ans+=add(root->left);
        add(root->right);
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root->left&&!root->right){
            return 0;
        }
        add(root);
        return ans;
    }
};