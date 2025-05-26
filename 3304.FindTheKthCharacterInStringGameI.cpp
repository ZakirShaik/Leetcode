#include <iostream>

using namespace std;

class Solution {
// Time Complexity: (log k); Space Complexity: 2^(log k)+1 ~~ 2^(log k)
public:
    char kthCharacter(int k) {
        string s = "a";
        while(k > s.length()-1) {
            int len = s.length();
            for(int i = 0; i < len; ++i) {
                (s[i] == 'z') ? s.push_back('a') : s.push_back(s[i] + 1);
            }
        }
        return s[k-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.kthCharacter(5) << endl;
    return 0;
}