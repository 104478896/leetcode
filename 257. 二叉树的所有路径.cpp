/*给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

叶子节点 是指没有子节点的节点。*/
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
    void findPath(TreeNode* root,string path,vector<string>&ans){
        if(root){
            path+=to_string(root->val);
            if(!root->left&&!root->right){
                ans.push_back(path);
            }else{
                path+="->";
                findPath(root->left,path,ans);
                findPath(root->right,path,ans);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        if(!root){
            return ans;
        }
        findPath(root,"",ans);
        return ans;
    }
};