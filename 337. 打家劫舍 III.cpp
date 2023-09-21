/*小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。*/
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
    pair<int,int> dfs(TreeNode*root){
        if(!root){
            return {0,0};
        }
        pair<int,int> l_rob=dfs(root->left);
        pair<int,int> r_rob=dfs(root->right);
        int is_rob=l_rob.second+r_rob.second+root->val;
        int not_rob=max(l_rob.first,l_rob.second)+max(r_rob.first,r_rob.second);
        return {is_rob,not_rob};
    }
    int rob(TreeNode* root) {
        pair<int,int>res=dfs(root);
        int ans=max(res.first,res.second);
        return ans;
    }
};