#include <iostream>

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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast && fast->next) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
};

// Function to insert a new node at the end of the list
void insertAtEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    ListNode* head = nullptr;

    // Inserting elements to the linked list
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 6);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    // Creating a cycle in the list for testing
    head->next->next->next->next->next->next->next = head->next->next; // Cycle: 5->6->6 (looping back to the second 6)

    Solution sol;
    bool cycle = sol.hasCycle(head);
    if (cycle) {
        std::cout << "The list has a cycle." << std::endl;
    } else {
        std::cout << "The list does not have a cycle." << std::endl;
    }

    return 0;
}
