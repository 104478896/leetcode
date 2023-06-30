/*链表中的 临界点 定义为一个 局部极大值点 或 局部极小值点 。

如果当前节点的值 严格大于 前一个节点和后一个节点，那么这个节点就是一个  局部极大值点 。

如果当前节点的值 严格小于 前一个节点和后一个节点，那么这个节点就是一个  局部极小值点 。

注意：节点只有在同时存在前一个节点和后一个节点的情况下，才能成为一个 局部极大值点 / 极小值点 。

给你一个链表 head ，返回一个长度为 2 的数组 [minDistance, maxDistance] ，其中 minDistance 是任意两个不同临界点之间的最小距离，maxDistance 是任意两个不同临界点之间的最大距离。如果临界点少于两个，则返回 [-1，-1] 。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>Dis;
        ListNode* node=head;
        int val=head->val;
        int count=2;
        while(node->next->next){
            ListNode* temp=node->next;
            if((temp->val > val && temp->val > temp->next->val) || (temp->val < val && temp->val < temp->next->val)){
                Dis.push_back(count);
            }
            val=temp->val;
            node=node->next;
            count++;
        }
        vector<int>ans;
        int minDis=-1;
        int maxDis=-1;
        
        int len=Dis.size();
        if(len<2){
            ans.push_back(minDis);
            ans.push_back(maxDis);
            return ans;
        }
        maxDis=Dis[len-1]-Dis[0];
        minDis=maxDis;
        for(int i=1;i<len;++i){
            cout<<Dis[i]<<endl;
            minDis=min(minDis,Dis[i]-Dis[i-1]);
        }
        
        ans.push_back(minDis);
        ans.push_back(maxDis);

        return ans;
    }
};