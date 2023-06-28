/*给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.*/
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
    void all(TreeNode* node,vector<int>&ans){
        
        if(node==NULL){
            // ans.push_back(node->val);
            return;
        }
        ans.push_back(node->val);
        all(node->left,ans);
        all(node->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        all(root1,ans);
        all(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};