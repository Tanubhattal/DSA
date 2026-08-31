class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = INT_MAX;
        int firstCritical = -1;
        int prevCritical = -1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;
        int index = 1;
        
        while (nxt != nullptr) {
            if ((curr->val > prev->val && curr->val > nxt->val) || 
                (curr->val < prev->val && curr->val < nxt->val)) {
                
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDistance = min(minDistance, index - prevCritical);
                }
                prevCritical = index;
            }
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
            index++;
        }
        if (firstCritical == -1 || firstCritical == prevCritical) {
            return {-1, -1};
        }
        return {minDistance, prevCritical - firstCritical};
    }
};