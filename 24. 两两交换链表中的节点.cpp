/*给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。*/
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
    ListNode* swapPairs(ListNode* head) {
        // //递归
        // //时间复杂度:O(n)
        // //空间复杂度:O(n)
        // if(!head||!head->next){
        //     return head;
        // }
        // ListNode*tail=head->next;
        // head->next=swapPairs(tail->next);
        // tail->next=head;
        
        // return tail;

        //迭代
        //时间复杂度:O(n)
        //空间复杂度:O(1)
        ListNode*ans=new ListNode(-1);
        ans->next=head;
        ListNode*temp=ans;
        ListNode*node1;
        ListNode*node2;
        while(temp->next&&temp->next->next){
            node1=temp->next;
            node2=node1->next;
            temp->next=node2;
            node1->next=node2->next;
            node2->next=node1;
            temp=node1;
        }
        return ans->next;
    }
};