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
    string clearDigits(string s) {
        int resultLength = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(isdigit(s[i])) {
                if(i > 0) resultLength--;
            } else {
                s[resultLength] = s[i];
                resultLength++;
            }
        }
        s.resize(resultLength);
        return s;
    }

//   Solution 2: Time Complexity: O(n); Space Complexity: O(n)
//public:
//    string clearDigits(string s) {
//        string result = "";
//        for(auto ch : s) {
//            if(isdigit(ch)) {
//                if(result.length()) result.pop_back();
//            } else result.push_back(ch);
//        }
//        return result;
//    }

//   Solution 1: Time Complexity: O(n); Space Complexity: O(n)
//public:
//    string clearDigits(string s) {
//        string result = "";
//        for(auto ch : s) {
//            if(ch < 'a') {
//                if(result.length()) result.pop_back();
//            } else result.push_back(ch);
//        }
//        return result;
//    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.clearDigits("abc94a3sd") << endl;
    return 0;
}


