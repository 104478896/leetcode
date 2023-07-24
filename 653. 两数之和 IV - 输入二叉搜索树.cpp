/*给定一个二叉搜索树 root 和一个目标结果 k，如果二叉搜索树中存在两个元素且它们的和等于给定的目标结果，则返回 true。*/
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
    map<int,int>cnt;
    vector<int>nums;
    bool findTarget(TreeNode* root, int k) {
        // //深度优先+哈希表
        // if(!root){
        //     return false;
        // }
        // if(cnt.count(k-root->val)){
        //     return true;
        // }
        // cnt[root->val]++;
        
        // return findTarget(root->left,k)||findTarget(root->right,k);


        //中序遍历+双指针
        mid(root);
        int left=0;
        int right=nums.size()-1;
        
        while(left<right){
            if(nums[left]+nums[right]==k){
                return true;
            }else if(nums[left]+nums[right]<k){
                left++;
            }else{
                right--;
            }
        }
        return false;
    }
    void mid(TreeNode* root){
        if(!root){
            return;
        }
        mid(root->left);
        nums.push_back(root->val);
        mid(root->right);
    }
};