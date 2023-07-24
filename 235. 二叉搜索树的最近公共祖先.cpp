/*给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]*/
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
    vector<TreeNode*> findPath(TreeNode* root,TreeNode* target){
        vector<TreeNode*>path;//统计到达目标节点的路径
        TreeNode* node=root;//指针节点
        while(node!=target){
            //当指针节点的值不等于目标节点的值时，代表还未找到
            //当指针节点的值大于目标节点的值时，代表目标节点在指针节点的左子树上
            //当指针节点的值小于目标节点的值时，代表目标节点在指针节点的右子树上
            path.push_back(node);
            if(node->val>target->val){
                
                node=node->left;
            }else{
                
                node=node->right;
            }
        }
        //循环结束代表找到了目标节点，将目标节点存入路径
        path.push_back(node);
        return path;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>pathP=findPath(root,p);//p的路径
        vector<TreeNode*>pathQ=findPath(root,q);//q的路径
        TreeNode* ans;//结果节点
        for(int i=0;i<pathP.size()&&i<pathQ.size();++i){
            if(pathP[i]==pathQ[i]){
                //当两个路径的节点相同时，代表当前节点是p和q的祖先节点，但不一定是最近的
                ans=pathP[i];
            }else{//当两个路径不同时，代表上一个相同节点是p和q的最近祖先节点
                break;
            }
        }
        return ans;
    }
};