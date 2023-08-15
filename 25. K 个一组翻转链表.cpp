/*给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。*/
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
    pair<ListNode*,ListNode*> reverseListNode(ListNode*start,ListNode*end){
        ListNode*pre=end->next;
        ListNode*tail=start;
        while(pre!=end){
            ListNode*temp=tail->next;
            tail->next=pre;
            pre=tail;
            tail=temp;
        }
        return {end,start};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*ans=new ListNode(-1,head);
        ListNode*pre=ans;
        while(head){
            ListNode*tail=pre;
            for(int i=0;i<k;++i){
                tail=tail->next;
                if(!tail){
                    return ans->next;
                }
            }
            ListNode*nex=tail->next;
            pair<ListNode*,ListNode*>res=reverseListNode(head,tail);
            head=res.first;
            tail=res.second;
            pre->next=head;
            tail->next=nex;
            pre=tail;
            head=tail->next;

        }
        return ans->next;
    }
};