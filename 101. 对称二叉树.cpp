/*给你一个二叉树的根节点 root ， 检查它是否轴对称。*/
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
    bool helper(TreeNode*node1,TreeNode*node2){
        if(!node1&&!node2){
            return true;
        }
        if(node1==NULL||node2==NULL||node1->val!=node2->val){
            return false;
        }
        return helper(node1->left,node2->right)&&helper(node1->right,node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        if(!root->left&&!root->right){
            return true;
        }
        return helper(root->left,root->right);
    }
};