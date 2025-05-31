#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
//   Solution 3: Time Complexity: O(n); Space Complexity: O(1)
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; ++i) {
            // Here == has higher precedence than ^. So, adding extra parentheses here.
            if(((nums[i] & 1) ^ (nums[i+1] & 1)) == 0) return false;
        }
        return true;
    }
    
//   Solution 2: Time Complexity: O(n); Space Complexity: O(1)
//public:
//    bool isArraySpecial(vector<int>& nums) {
//        for(int i = 0; i < nums.size()-1; ++i)
//            if(nums[i]%2 == nums[i+1]%2) return false;
//        return true;
//    }
    
// Solution 1: Time Complexity: O(n);Space Complexity: O(1)
//public:
//    bool isArraySpecial(vector<int>& nums) {
//        if(nums.size() == 1) return true;
//        bool result = true;
//        string type = "";
//        if(nums[0]%2 == 0) type = "even";
//        else type = "odd";
//        int i = 1;
//        while(i < nums.size()) {
//            if((nums[i]%2 == 0 && type == "even") ||
//            (nums[i]%2 == 1 && type == "odd")) result = false;
//            
//            if(type == "even") type = "odd";
//            else type = "even";
//            
//            i++;
//        }
//        return result;
//    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2, 1, 4, 5, 8, 3};
    Solution sol;
    cout << sol.isArraySpecial(nums) << endl;
    return 0;
}


