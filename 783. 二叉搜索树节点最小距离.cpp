/*给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

差值是一个正数，其数值等于两值之差的绝对值。*/
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
    void find(TreeNode* root,int& pre,int&ans){
        if(!root){
            return ;
        }
        find(root->left,pre,ans);
        if(pre==-1){
            pre=root->val;
        }else{
            ans=min(ans,root->val-pre);
            pre=root->val;
        }
        find(root->right,pre,ans);
    }
    int minDiffInBST(TreeNode* root) {
        int pre=-1;
        int ans=INT_MAX;
        find(root,pre,ans);
        return ans;
    }
};