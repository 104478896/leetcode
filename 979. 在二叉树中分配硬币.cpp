/*给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。

在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。

返回使每个结点上只有一枚硬币所需的移动次数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/distribute-coins-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
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
    int sum=0;
public:
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int sumLeft=0;
        int sumRight=0;
        if(root->left){
            sumLeft+=dfs(root->left);
        }
        if(root->right){
            sumRight+=dfs(root->right);
        }
        
        sum+=abs(sumLeft)+abs(sumRight);
        return sumLeft+sumRight+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return sum;
    }
};