#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include "solution.h"

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequency_map;
    for (int num : nums) {
        frequency_map[num]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    
    // Исправленная часть: используем iterator вместо structured binding
    for (auto it = frequency_map.begin(); it != frequency_map.end(); ++it) {
        min_heap.push({it->second, it->first});
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }
    
    vector<int> result;
    while (!min_heap.empty()) {
        result.push_back(min_heap.top().second);
        min_heap.pop();
    }
    
    return result;
}

