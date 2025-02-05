#include <iostream>
#include <vector>

using vector = std::vector<int>;

int produceSuccessiveSum(const vector& v, int current_index = 0) {
    if (current_index >= v.size()) {
        return 0; // Base case: prevent out-of-bounds access
    }
    
    return v[current_index] + produceSuccessiveSum(v, current_index + 1);
}

int main() {
    vector v = {1, 2, 3, 4, 5}; // Example with multiple elements
    std::cout << "Sum is: " << produceSuccessiveSum(v) << std::endl;
    return 0;
}
