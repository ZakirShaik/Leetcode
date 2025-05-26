#include <iostream>

using namespace std;

class Solution {
// Solution 3: Time Complexity: log n base 4 ≈ (log n base 2)/2 ≈ (log n) ;
// Space Complexity: O(1)
public:
    bool isPowerOfFour(int n) {
        if(n == 0) return false;

        while(n%4 == 0) n /= 4;

        return n == 1;
    }

/*
Solution 2:  Time Complexity: log n base 4 ≈ (log n base 2)/2 ≈ (log n) ; Space Complexity: O(1)
public:
    bool isPowerOfFour(int num) {
        while (num > 1) {
			if (num % 4) return false;
			num /= 4;
		}
		return (num == 1);
    }
};
*/

/*
Solution 1:  Time Complexity: log n base 4 ≈ (log n base 2)/2 ≈ (log n) ; 
            Space Complexity: log n base 4 ≈ (log n base 2)/2 ≈ (log n) ;
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        else if (n < 4) return false;

        if(n%4 == 0)
            return isPowerOfFour(n/4);

        return false;
    }
*/

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.isPowerOfFour(40) << endl;
    return 0;
}