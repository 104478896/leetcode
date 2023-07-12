/*给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。*/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int count=0;
        // ListNode* temp=head;

        // while(temp){
        //     count++;
        //     temp=temp->next;
        // }
        // ListNode* list=new ListNode(-1);
        // ListNode* cur=list;
        // cur->next=head;
        // for(int i=1;i<count-n+1;++i){
        //     cur=cur->next;
        // }
        // cur->next=cur->next->next;
        // return list->next;

        //双指针|快慢指针
        ListNode* ans=new ListNode(0,head);
        ListNode* slow=ans;
        ListNode* fast=head;
        for(int i=0;i<n;++i){
            fast=fast->next;
        }
        while(fast){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return ans->next;
    }
};