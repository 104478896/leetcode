/*给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。*/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans=new ListNode(0,head);
        ListNode* temp=ans;
        while(temp&&temp->next){
            if(temp->next->val==val){
                temp->next=temp->next->next;
            }else{
                temp=temp->next;
            }
            
        }
        return ans->next;
    }
};