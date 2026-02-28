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
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
   
   
//         // Create a dummy node to handle edge cases like removing the head
//         ListNode dummy(0);
//         dummy.next = head;
//         ListNode* first = &dummy;
//         ListNode* second = &dummy;

//         // Move `first` pointer so that it is `n+1` nodes ahead of `second`
//         for (int i = 0; i <= n; ++i) {
//             first = first->next;
//         }

//         // Move both `first` and `second` pointers until `first` reaches the end
//         while (first != nullptr) {
//             first = first->next;
//             second = second->next;
//         }

//         // `second->next` is the node to be removed
//         ListNode* nodeToDelete = second->next;
//         second->next = second->next->next;

//         // Clean up the node
//         delete nodeToDelete;

//         return dummy.next;
//     }
    


// };

// Write more efficient

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;

        while (n--) fast = fast->next;

        // If fast becomes NULL → delete head
        if (!fast) return head->next;

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};