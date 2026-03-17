#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };

        // --- Core Data Structure: Min-Heap ---
        // `priority_queue` with a custom container `vector<ListNode*>` and our comparator.
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        // --- Initialization ---
        // Seed the priority queue with the head of each non-empty list.
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        // --- Sentinel/Dummy Node Pattern ---
        // Using a dummy node simplifies list construction. We don't need to handle
        // the "is the head null?" case separately in the loop.
        ListNode dummyHead(0);
        ListNode* tail = &dummyHead;

        // --- Main Loop ---
        // Process nodes until the heap is empty.
        while (!pq.empty()) {
            // 1. Get the node with the overall minimum value.
            ListNode* minNode = pq.top();
            pq.pop();

            // 2. Append this node to our result list.
            tail->next = minNode;
            tail = tail->next;

            // 3. Add the next node from the *same list* back into the heap.
            // This maintains the "one node from each active list" invariant.
            if (minNode->next != nullptr) {
                pq.push(minNode->next);
            }
        }
        
        // The merged list starts right after our dummy head.
        return dummyHead.next;
    }
};
int main {
    return 0;
}