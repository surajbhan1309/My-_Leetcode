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
// class Solution {
// public:
//     ListNode *solve(ListNode *first, ListNode *second)
// {
//     //if only one element in first list
//     if(first->next==NULL){
//         first->next=second;
//         return first;
//     }
//     ListNode *curr1 = first;
//     ListNode *next1 = curr1->next;
//     ListNode *curr2 = second;
//     ListNode *next2 = curr2->next;

//     while (next1 != NULL && curr2 != NULL)
//     {
//         if ((curr2->val >= curr1->val) && (curr2->val <= next1->val))
//         {

//             // add node in between the first list
//             curr1->next = curr2;
//             next2 = curr2->next; // For not losing the second LL element
//             curr2->next = next1;
//             // updata pointers
//             curr1 = curr2;
//             curr2 = next2;
//         }
//         else
//         {
//             // curr1 and next1 ko aage badhana padega
//             curr1 = next1;
//             next1 = next1->next;

//             if (next1 == NULL)
//             {
//                 curr1->next = curr2;
//                 return first;
//             }
            
//         }

//     }
//     return first;
// }


//     ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        
//     if (first == NULL)
//         return second;
//     if (second == NULL)
//         return first;
//     if (first->val <= second->val)
//     {
//          return solve(first, second);
//     }
//     else
//     {
//          return solve(second, first);
//     }
        
//     }
// };

class Solution {
public://using dummy LL
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy,*temp;
        dummy=new ListNode();
        temp=dummy;

        //when both list1 and list2 is not empty
        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        //we reached at the end of one the list
        if(list1) temp->next=list1;
        if(list2) temp->next=list2;


        return dummy->next;
    }
};