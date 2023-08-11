/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void front(TreeNode*root,set<int>&cnt){
        if(!root){
            return;
        }
        cnt.insert(root->val);
        front(root->left,cnt);
        front(root->right,cnt);
    }
    int numColor(TreeNode* root) {
        
        set<int>cnt;
        front(root,cnt);
        return cnt.size();
    }
};