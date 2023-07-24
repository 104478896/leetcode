/*给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 */
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
    bool helper(TreeNode* root,long min,long max){
        if(!root){
            return true;
        }
        if(root->val>=max||root->val<=min){
            return false;
        }
        return helper(root->left,min,root->val)&&helper(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        return helper(root,LONG_MIN,LONG_MAX);
    }
};