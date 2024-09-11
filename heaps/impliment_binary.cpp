#include <iostream>
#include <vector>
using namespace std;

// Binary Heap class (min-heap or max-heap)
class BinaryHeap {
private:
    vector<int> heap;
    bool isMinHeap;

    // Helper function to maintain heap property (bottom-up approach)
    void heapifyUp(int idx) {
        if (idx == 0) return; // Base case: at the root
        int parentIdx = (idx - 1) / 2;

        // If MinHeap, check if parent is larger, if MaxHeap, check if parent is smaller
        if ((isMinHeap && heap[idx] < heap[parentIdx]) || (!isMinHeap && heap[idx] > heap[parentIdx])) {
            swap(heap[idx], heap[parentIdx]);
            heapifyUp(parentIdx);  // Recursively heapify up
        }
    }

    // Helper function to maintain heap property (top-down approach)
    void heapifyDown(int idx) {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        int smallestOrLargest = idx;

        // Check for MinHeap or MaxHeap and find the smallest/largest among parent and children
        if (leftChild < heap.size() && 
            ((isMinHeap && heap[leftChild] < heap[smallestOrLargest]) || (!isMinHeap && heap[leftChild] > heap[smallestOrLargest]))) {
            smallestOrLargest = leftChild;
        }

        if (rightChild < heap.size() && 
            ((isMinHeap && heap[rightChild] < heap[smallestOrLargest]) || (!isMinHeap && heap[rightChild] > heap[smallestOrLargest]))) {
            smallestOrLargest = rightChild;
        }

        if (smallestOrLargest != idx) {
            swap(heap[idx], heap[smallestOrLargest]);
            heapifyDown(smallestOrLargest);  // Recursively heapify down
        }
    }

public:
    // Constructor to initialize heap type
    BinaryHeap(bool minHeap = true) : isMinHeap(minHeap) {}

    // Insert an element into the heap
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);  // Maintain heap property after insertion
    }

    // Remove and return the root element (min for min-heap, max for max-heap)
    int extractRoot() {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        int rootValue = heap[0];
        heap[0] = heap.back();   // Move last element to the root
        heap.pop_back();         // Remove last element
        heapifyDown(0);          // Maintain heap property after removal
        return rootValue;
    }

    // Peek at the root element (min for min-heap, max for max-heap)
    int getRoot() const {
        if (heap.empty()) {
            throw out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // Check if the heap is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Print the heap (for debugging)
    void printHeap() const {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create a min-heap
    BinaryHeap minHeap(true);
    
    // Insert elements into the heap
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(30);
    minHeap.insert(2);

    cout << "Min-Heap elements: ";
    minHeap.printHeap();

    // Extract the root element (minimum element in min-heap)
    cout << "Extracted root: " << minHeap.extractRoot() << endl;

    cout << "Heap after extraction: ";
    minHeap.printHeap();

    return 0;
}
