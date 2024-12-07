/* Here, searching for banned words is a challenge. 

Consider 
m = number of banned elements.
n = [1...n]

Approach 1: brute force: In the worst case, we can search banned words in a linear time complexity. So, for every i = 1 to n,
we have to search the whole banned array. Time Complexity would be O(m*n).

Approach 2 (Better): Instead of linear search, we can use binary search to reduce the time complexity.
To implement binary search, sorting is needed.
In this approach, the time complexity would be: 
O(m log m) {for sorting} +
O(n log m) {for each n = [1...n] we need to search if it exists in set of m with log m steps}
Total Time Complexity: O((m+n)log m)

Approach 3 (better than approach 2):
We can sort elements with O(m log m)
Then by using two pointers, on pointing to 1...n and other pointing to banned set, we can check if for each
n, if it exists in banned set. Here time complexity is O(m + n)
Total time complexity: O(m log m) + O(m + n) 
                        => O(n + m + m log m)
                        => O(n + m (1 + log m))
                        => O(n + m log m)

Approach 4 (Optimal) (Below Approach):
We can use hash set to store the banned items and the look up time complexity would be O(1)
To store the banned items in hash set, we need to parse the whole array. So, Time complexity for this = O(m)
Total Time Complexity = O(m) + O(n * 1) = O(m + n)
Space complexity = O(m) // to store banned items in hash set.

/**
 * @param {number[]} banned
 * @param {number} n
 * @param {number} maxSum
 * @return {number}
 */
var maxCount = function(banned, n, maxSum) {
    let bannedSet = new Set();
    let sum = 0;
    let maxCount = 0;
    for (const bannedInt of banned) {
        bannedSet.add(bannedInt);
    }

    for (let i = 1; i <= n; ++i) {
        if (!bannedSet.has(i)) {
            if (i + sum <= maxSum) {
                sum += i;
                maxCount++;
            } else {
                break;
            }
        }
    }
    return maxCount;
};