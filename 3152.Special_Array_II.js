/*
Approach 1: Brute Force: Time Limit Exceeded
Time Complexity: O(n*m); where n = nums.length, m = queries.length
*/
/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var isArraySpecial = function(nums, queries) {
    let answer = [];
    for (let query of queries) {
        let isSpecial = true;
        for (let i = query[0]; i < query[1]; ++i) {
            if ((nums[i]%2 === 0) && (nums[i+1]%2 === 0) || 
                (nums[i]%2 !== 0) && (nums[i+1]%2 !== 0)) {
                    isSpecial = false;
                    break;
                }
        }
        answer.push(isSpecial);
    }
    return answer;
};