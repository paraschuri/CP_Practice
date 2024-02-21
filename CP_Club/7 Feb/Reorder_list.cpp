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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        int sz = st.size()/2;
        while(sz--){
            ListNode* temp = head->next;
            head->next = st.top();
            head->next->next = temp;
            head = temp;
            st.pop();
        }
        head->next = NULL;
    }
};  