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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points;
        ListNode* cur = head;
        while(cur != NULL){
            points.push_back(cur->val);
            cur = cur->next;
        }

        vector<int> critical;
        for(int i = 1; i + 1 < points.size(); i++){
            if(points[i] > points[i - 1] && points[i] > points[i + 1] ||
               points[i] < points[i - 1] && points[i] < points[i + 1])
               critical.push_back(i);
        }

        vector<int> ans(2, -1);
        if(critical.size() < 2) return ans;

        ans[0] = critical[1] - critical[0];
        for(int i = 1; i < critical.size(); i++){
            ans[0] = min(ans[0], critical[i] - critical[i - 1]);
        }
        ans[1] = critical[critical.size() - 1] - critical[0];

        return ans;
    }
};