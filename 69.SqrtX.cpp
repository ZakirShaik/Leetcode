#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
// Solution 2: Time Complexity: O(log n); Space Complexity: O(1)
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int start = 2, end = x/2;
        long square;
        while(start <= end) {
            int mid = start + (end - start)/2; // Here integer flow doesn't happen. So, we can use int.
            square = (long)mid * mid;
            if(square == x) {
                return mid;
            } else if(square > x) end = mid - 1;
            else start = mid + 1;
        }
        return end;
    }
// Solution: Time Complexity: O(log n); Space Complexity: O(1)
//public:
//    int mySqrt(int x) {
//        if(x < 2) return x;
//        long long start = 1, end = x/2, squareRoot = 0;
//        while(start <= end) {
//            long long mid = (start + end)/2;  // Here (start + end)/2 causes integer overflow. So, long long is being used. It's better to use start + (end - start)/2 to use int
//            long long square = mid * mid;
//            if(square == x) {
//                squareRoot = mid;
//                break;
//            } else if(square > x) end = mid - 1;
//            else {
//                squareRoot = max(squareRoot, mid);
//                start = mid + 1;
//            }
//        }
//        return (int)squareRoot;
//    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.mySqrt(80) << endl;
    return 0;
}


