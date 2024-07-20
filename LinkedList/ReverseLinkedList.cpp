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
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode=NULL;
        while(head){
            nextNode=head->next;
            head->next=prevNode;
            prevNode=head;
            head=nextNode;
        }
        return prevNode;
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

    std::cout << "Original List: ";
    displayList(head);

    Solution sol;
  
    head = sol.reverseList(head);

    std::cout << "List after reversing " << ": ";
    displayList(head);

    return 0;
}
