/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head->next) {
            return head;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Using a slow and fast pointer approach, when the fast pointer
        // reaches the end of the LL, the slow pointer would be at the middle position.
        while(fast->next && fast->next->next) {
            // Move slow pointer by 1 position.
            slow = slow->next;
            
            // Move fast pointer by 2 positions.
            fast = fast->next->next;
        }
        
        // To return the second middle node in case of an even number of nodes.
        if(fast->next) {
            slow = slow->next;
        }
        
        return slow;
    }
};
