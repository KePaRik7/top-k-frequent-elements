#include <iostream>
#include <vector>
#include <algorithm>
#include "../src/solution.h" // Подключаем реализацию



bool test(const std::vector<int>& nums, int k, const std::vector<int>& expected) {
    std::vector<int> nums_copy = nums;
    auto result = topKFrequent(nums_copy, k);
    std::sort(result.begin(), result.end());
    auto expected_sorted = expected;
    std::sort(expected_sorted.begin(), expected_sorted.end());
    
    if (result != expected_sorted) {
        std::cout << "Test FAILED\n";
        std::cout << "Input: [";
        for (size_t i = 0; i < nums.size(); ++i) {
            std::cout << nums[i];
            if (i != nums.size() - 1) std::cout << ", ";
        }
        std::cout << "], k = " << k << "\n";
        std::cout << "Expected: [";
        for (size_t i = 0; i < expected.size(); ++i) {
            std::cout << expected[i];
            if (i != expected.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n";
        std::cout << "Got: [";
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i];
            if (i != result.size() - 1) std::cout << ", ";
        }
        std::cout << "]\n\n";
        return false;
    }
    return true;
}

int main() {
    int passed = 0;
    int total = 0;
    
    auto run_test = [&](const std::vector<int>& nums, int k, 
                       const std::vector<int>& expected) {
        total++;
        if (test(nums, k, expected)) passed++;
    };
    
    // Тестовые случаи
    run_test({1,1,1,2,2,3}, 2, {1,2});
    run_test({1}, 1, {1});
    run_test({4,4,4,4}, 1, {4});
    run_test({1,2,3,1,2,1,4,4,4,4}, 3, {1,4,2});
    run_test({5,5,5,5,2,2,3,3,3}, 2, {5,3});
    
    std::cout << "Tests passed: " << passed << "/" << total << "\n";
    return passed == total ? 0 : 1;
}