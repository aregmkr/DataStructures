#include "forwardList.h"

int main() {
    ForwardList<int> list;
    
    // Test empty()
    std::cout << "List empty: " << (list.empty() ? "Yes" : "No") << std::endl;

    // Push elements at front
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    
    std::cout << "After push_front: ";
    list.print();  // Expected: 30 20 10
    std::cout << std::endl;

    // Check size and front
    std::cout << "Size: " << list.size() << std::endl;   // Expected: 3
    std::cout << "Front: " << list.front() << std::endl; // Expected: 30

    // Insert after first element
    auto it = list.begin();
    list.insert_after(it, 25);
    
    std::cout << "After insert_after(30, 25): ";
    list.print();  // Expected: 30 25 20 10
    std::cout << std::endl;

    // Erase after first element
    list.erase_after(it);
    std::cout << "After erase_after(30): ";
    list.print();  // Expected: 30 20 10
    std::cout << std::endl;

    // Find element at index 2

    // Pop front
    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();  // Expected: 20 10
    std::cout << std::endl;

    // Clear list
    list.clear();
    std::cout << "After clear, list empty: " << (list.empty() ? "Yes" : "No") << std::endl; // Expected: Yes

    return 0;
}
