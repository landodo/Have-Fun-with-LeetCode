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
    // Time complexity: O(n)
    // Space complexity: O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
      ListNode* dummy_head = new ListNode(-1);
      ListNode* prev = dummy_head;
      while (l1 && l2)
      {
        if (l1->val < l2->val)
        {
          prev->next = l1;
          prev = l1;
          l1 = l1->next;
        }
        else
        {
          prev->next = l2;
          prev = l2;
          l2 = l2->next;
        }
      }

      if (l1 == NULL)
        prev->next = l2;
      else
        prev->next = l1;  

      ListNode* r = dummy_head->next;
      delete dummy_head;
      dummy_head = NULL;

      return r;
    }
};