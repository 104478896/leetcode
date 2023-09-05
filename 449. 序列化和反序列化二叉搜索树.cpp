/*序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

 */
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //后序遍历,遍历树将值放入全局数组arr
    void postOrder(TreeNode *root,vector<int>&arr){
        if(root==nullptr){
            return ;
        }
        postOrder(root->left,arr);
        postOrder(root->right,arr);
        arr.push_back(root->val);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        vector<int>arr;
        postOrder(root,arr);
        if(arr.size()==0){//如果数组为空，代表为空树，可以直接返回值
            return ans;
        }
        int len=arr.size();
        for(int i=0;i<len-1;++i){
            ans.append(to_string(arr[i])+',');
        }
        ans.append(to_string(arr.back()));
        return ans;
    }

    //反序列，将字符根据","分割
    vector<string> split(const string &str,char ch){
        int pos=0;
        int start=0;
        vector<string>res;
        int len=str.size();
        while(pos<len){
            
            while(pos<len&&str[pos]==ch){
                pos++;
            }
            start=pos;
            while(pos<len&&str[pos]!=ch){
                pos++;
            }
            if(start<len){
                res.push_back(str.substr(start,pos-start));
            }
        }
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        vector<string> arr=split(data,',');
        stack<int>stk;//存储树上的每一个数字
        for(auto &str:arr){
            stk.push(stoi(str));
        }
        return construct(INT_MIN,INT_MAX,stk);//恢复树形结构返回
    }
    TreeNode* construct(int lower,int upper,stack<int>&stk){
        //如果栈为空或者栈顶元素小于最小值或大于最大值返回NULL
        //即将栈中元素重构成一个二叉搜索树
        if(stk.size()==0 || stk.top()<lower || stk.top()>upper){
            return nullptr;
        }
        int val=stk.top();
        stk.pop();
        TreeNode *root=new TreeNode(val);
        root->right=construct(val,upper,stk);
        root->left=construct(lower,val,stk);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;