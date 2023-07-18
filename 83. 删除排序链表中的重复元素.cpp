/*给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。*/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans=new ListNode(0,head);
        ListNode* tail=head;
        while(tail&&tail->next){
            if(tail->val==tail->next->val){
                tail->next=tail->next->next;
            }else{
                tail=tail->next;
            }
        }
        return ans->next;
    }
};