/*给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。



来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/n-ary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void front(Node* root,vector<int>& ans){
        if(!root){
            return ;
        }
        ans.push_back(root->val);
        for(auto child:root->children){
            front(child,ans);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        front(root,ans);
        return ans;

    }
};