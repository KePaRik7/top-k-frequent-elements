#include "../src/solution.h"
#include <iostream>

using namespace std;

int main() {
        cout << "Enter array elements separated by spaces (end with 'q'): ";
        vector<int> nums;
        int num;
        
        while (cin >> num) {
            nums.push_back(num);
        }
        cin.clear(); 
        cin.ignore(); 
        
        cout << "Enter k: ";
        int k;
        cin >> k;
        
        vector<int> result = topKFrequent(nums, k);
        
        cout << "Result: [";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i != result.size() - 1) {
                cout << ",";
            }
        }
        cout << "]" << endl;
        
        return 0;
    
}