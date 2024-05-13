//Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*Brute-force solution took 1hr 3 minutes

Time complexity : O(n) & Space : O(n)

It can be optimized to T.C : O(N) & S.C : O(1)
*/

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
        if(head->next == NULL){
            delete head;
            return nullptr;
        }

        ListNode* curr = head;

        vector<int> temp; // Space : O(n)
        int i = 1;

        while(curr!=NULL){ // Time : O(n)
            temp.push_back(i);
            curr = curr->next;
            i++;
        }

        int removeNode = temp.size() - n + 1; // O(n)
        ListNode* prev = NULL;curr = head;i = 1;
        
        if(i==removeNode){ // If first node is to be removed
            prev =curr;
            curr = curr->next;
            prev->next = NULL;
            delete prev;head = curr;
            return head;
        }

        while(i<removeNode){ // Time: O(n)
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    
    return head;
    }
};
