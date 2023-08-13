/*给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。*/
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
    ListNode* helper(ListNode*a,ListNode*b){
        if((!a)||(!b)){
            return a?a:b;
        }
        ListNode*head=new ListNode(-1);
        ListNode*tail=head;
        ListNode*aList=a;
        ListNode*bList=b;
        while(aList&&bList){
            if(aList->val<bList->val){
                tail->next=aList;
                aList=aList->next;
            }else{
                tail->next=bList;
                bList=bList->next;
            }
            tail=tail->next;
        }
        tail->next=(aList?aList:bList);
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode*ans=NULL;
        int len=lists.size();
        for(int i=0;i<len;++i){
            ans=helper(ans,lists[i]);
        }
        return ans;
    }
};