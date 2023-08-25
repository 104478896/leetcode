/*给你一棵根为 root 的二叉树，请你返回二叉树中好节点的数目。

「好节点」X 定义为：从根到该节点 X 所经过的节点中，没有任何节点的值大于 X 的值。*/
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
    int dfs(TreeNode*root,int mx){
        if(!root){
            return 0;
        }
        int left=dfs(root->left,max(root->val,mx));
        int right=dfs(root->right,max(root->val,mx));
        return left+right+(root->val>=mx);
        
    }   
    int goodNodes(TreeNode* root) {
        ans=dfs(root,INT_MIN);
        return ans;
    }
};