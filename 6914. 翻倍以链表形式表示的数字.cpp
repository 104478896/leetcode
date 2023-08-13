/*给你一个 非空 链表的头节点 head ，表示一个不含前导零的非负数整数。

将链表 翻倍 后，返回头节点 head */
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
    ListNode* doubleIt(ListNode* head) {
        ListNode*ans;
        if(head->val>=5){
            head=new ListNode(0,head);
        }
        ans=head;
        
        while(ans){
            // cout<<ans->val<<endl;
            ans->val=(2*ans->val)%10;
            if(ans->next&&ans->next->val>=5){
                ans->val+=1;
            }
            ans=ans->next;
        }
        return head;

    }
};