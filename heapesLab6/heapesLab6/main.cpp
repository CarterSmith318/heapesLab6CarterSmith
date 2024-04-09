#include <iostream>
#include <vector>

#include <climits> // Included for INT_MAX

// v1
//v2
//v3

class MaxHeap {
private:
    std::vector<int> data;

    // Heapify function to maintain the heap property, single parameter version
    void heapify(size_t i) {
        size_t largest = i;
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left < data.size() && data[left] > data[largest])
            largest = left;

        if (right < data.size() && data[right] > data[largest])
            largest = right;

        if (largest != i) {
            std::swap(data[i], data[largest]);
            heapify(largest);
        }
    }

    // Heapify function, two parameter version for heap sort
    void heapify(int i, int heapSize) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && data[left] > data[largest])
            largest = left;

        if (right < heapSize && data[right] > data[largest])
            largest = right;

        if (largest != i) {
            std::swap(data[i], data[largest]);
            heapify(largest, heapSize);
        }
    }

public:
    // Constructor to convert an array into a max heap
    MaxHeap(const std::vector<int>& input) {
        data = input;
        for (int i = static_cast<int>(data.size()) / 2 - 1; i >= 0; i--) {
            heapify(static_cast<size_t>(i));
        }
    }

    // Inserts a new element to the heap
    void insert(int element) {
        data.push_back(element); // Add at the end
        int i = data.size() - 1; // Index of new element

        // Fix the max heap property if it's violated
        while (i != 0 && data[(i - 1) / 2] < data[i]) {
            std::swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Removes and returns the maximum element from the heap
    int deleteMax() {
        if (data.size() <= 0)
            return INT_MAX;
        if (data.size() == 1) {
            int max = data[0];
            data.pop_back();
            return max;
        }

        // Store the maximum value, and remove it from heap
        int root = data[0];
        data[0] = data.back();
        data.pop_back();
        heapify(0);

        return root;
    }

    // Heap sort function
    void heapSort() {
        // Create a heap from the array
        for (int i = data.size() / 2 - 1; i >= 0; i--)
            heapify(i);

        // Extract elements from heap one by one
        for (int i = data.size() - 1; i >= 0; i--) {
            std::swap(data[0], data[i]);
            heapify(0, i);
        }
    }

    // Displays the heap
    void display() const {
        for (int i = 0; i < data.size(); i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }
};

int main() {
    std::vector<int> elements = { 3, 2, 15, 5, 4, 45 };
    MaxHeap heap(elements); // Create a max heap

    heap.insert(20); // Insert a new element
    std::cout << "Max Heap: ";
    heap.display(); // Display heap

    std::cout << "Sorted order: ";
    heap.heapSort(); // Perform heap sort
    heap.display(); // Display sorted data

    return 0;
}
