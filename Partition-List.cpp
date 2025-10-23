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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeLL =new ListNode(-1);
        ListNode* afterLL=new ListNode(-1);
        ListNode* temp1=beforeLL;
        ListNode* temp2=afterLL;
        while(head!=NULL){
            if(head->val<x){
                temp1->next=head;
                temp1=head;
            }
            else{
                temp2->next=head;
                temp2=head;
            }
            head=head->next;
        }
        temp2->next=NULL;
        temp1->next=afterLL->next;
        return beforeLL->next;

        
    }
};