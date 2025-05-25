#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string resultingString(string s) {
        string result;
        int i = 0;
        while(i < s.size()) {
            if(result.size() &&
               (abs(s[i] - result.back()) == 1 ||
                (s[i] == 'z' && result.back() == 'a') ||
                (s[i] == 'a' && result.back() == 'z'))) {
                result.pop_back();
            } else result.push_back(s[i]);
            i++;
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.resultingString("aabbeccdd") << endl;
    return 0;
}

