/*
Approach:
BruteForce: In this approach, we may have to parse the whole ribbons array in linear time for every
possible 'x' where 'x' is the longest possible ribbon with 'k' cuts.
Time Complexity = O(l*n), where l = [0...L], where 'L' is the largest size of ribbon in ribbons array.
n = size of ribbons array.

Optimal Approach: Binary search
We can do binary search on 'l', where l = [0...L], where 'L' is the largest size of ribbon in ribbons array.
In this way, time complexity to find 'x' would be O(log l) * O(n), where n = size of ribbons array.
=> Time Complexity = O(n log l) 
Space Complexity = O(1) as we are not using new additional arrays except variables.
*/

/**
 * @param {number[]} ribbons
 * @param {number} k
 * @return {number}
 */
var maxLength = function(ribbons, k) {
    let longestPiece = -1;
    for (const ribbon of ribbons) {
     if (ribbon > longestPiece) longestPiece = ribbon;
    } 
    let left = 1, right = longestPiece, finalLongestLength = 0;
    while (left <= right) {
     let mid = Math.round((left + right)/2);
     let ribbonCount = 0;
 
     for (let i = 0; i < ribbons.length; ++i) {
         if (ribbons[i] >= mid) ribbonCount += Math.floor(ribbons[i]/mid);
     }
 
     if (ribbonCount >= k) {
         finalLongestLength = mid;
         left = mid + 1;
     } else right = mid - 1;
    }
 
     return finalLongestLength;
 };