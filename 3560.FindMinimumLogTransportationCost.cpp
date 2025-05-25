#include <iostream>

using namespace std;

/*
Time Complexity: O(1)
Space Complexity: O(1)
This approach will handle all the following scenarios as more details are not provided in description:

Scenario 1: m = 11, n = 4, k = 5 -> In this case, m needs to be cut twice so that 5, 5, (1 + 4) will fit in 3 trucks.
Scenario 2: When m > k and n > k. Eg: m = 7, n = 8, k = 5. Here we need to cut both m and n so that 5, 5, (2+3) will fit in 3 trucks.
*/

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        if(n <= k && m <= k) return 0;
        else if(n <= k) {
            while(m > k) {
                cost += (m - k) * k;
                m = m - k;
            }
        }
        else if(m <= k) {
            while(n > k) {
                cost += (n - k) * k;
                n = n - k;
            }
        }
        else cost = ((m - k) * k) + ((n - k) * k);
        return cost;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.minCuttingCost(7, 8, 5) << endl;
    return 0;
}

