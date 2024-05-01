//Problem Link: https://leetcode.com/problems/reverse-linked-list/description/
// Difficulity : EASY

//Time taken: 40 minutes

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) // when Linkelist will be empty or only 1 node is present
            return head;
        
        ListNode* temp = head;
        stack<int> s1;

        while(temp!=nullptr){ // Pushing the node->val into stack to reverse the linkedlist
            s1.push(temp->val);
            temp = temp -> next;
        }

        temp = head;

        while(!s1.empty()){ // Popping the stack
            temp->val = s1.top();
            s1.pop();
            temp = temp->next;
        }
        return head;
    }
};

//Iterative Method
// Brute force approach
// Time complexity : O(n) and Space complexity : O(n) 

//---------------------------------------------------------------------------------------------------------------------
//Iterative method
//Optimized solution with T.C : O(n) and S.C : O(1)


// Time taken: 1 hr 34 min
ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        // Taking three-pointers to manipulate the address instead of taking val
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode;
    
        while(curr!=NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

    return prev;
    }
//------------------------------------------------------------------------------------------------------------
    // Recursive Method
