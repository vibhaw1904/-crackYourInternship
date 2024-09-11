#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
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
        if(lists.size() == 0) return NULL;

        // Dummy head to simplify the merging process
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyTail = dummyHead;

        // Min-heap priority queue to store the smallest nodes of the lists
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // Push the first node of each list into the priority queue
        for(auto it : lists) {
            if(it != NULL) pq.push({it->val, it});
        }

        // Process the nodes in the priority queue
        while(!pq.empty()) {
            ListNode* temp = pq.top().second; // Get the node with the smallest value
            pq.pop();

            if(temp->next != NULL) {
                pq.push({temp->next->val, temp->next});
            }
            
            // Add the current smallest node to the result list
            dummyTail->next = temp;
            dummyTail = dummyTail->next;
        }

        return dummyHead->next;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a few sample sorted linked lists
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    // Adding these lists to a vector
    vector<ListNode*> lists = {l1, l2, l3};

    // Solution instance
    Solution solution;

    // Merging the k sorted linked lists
    ListNode* mergedList = solution.mergeKLists(lists);

    // Print the merged list
    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}
