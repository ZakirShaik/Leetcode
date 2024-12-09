/* Approach 1: BruteForce: 
Time Complexity: O(n^2)
Space Complexity: O(1) */

/**
 * Definition for knows()
 * 
 * @param {integer} person a
 * @param {integer} person b
 * @return {boolean} whether a knows b
 * knows = function(a, b) {
 *     ...
 * };
 */

/**
 * @param {function} knows()
 * @return {function}
 */
var solution = function(knows) {
    /**
     * @param {integer} n Total people
     * @return {integer} The celebrity
     */
    return function(n) {
        for (let j = 0; j < n; ++j) {
            for (let i = 0; i < n; ++i) {
                if (!knows(i,j) || (knows(j,i) && i !== j)) break;
                if (i === n-1) {
                    return j;
                }
            }
        }
        return -1;
    };
};