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

/*
Approach 2: Binary Search
Time Complexity: We traverse thw whole nums array to find the violating Indices which takes O(n) time.
In the worst case, we can consider that all the indices are violating. So, In order for us to check the 
violating Indices, it takes log n time. Now, we do this for every query.
Consider, query length = m; Then Time complexity to check if the query range is special array or not, it 
takes O(m log n).
Now, Total time complexity (initial nums traversal + is special array check) = O(n + m log n)
Space Complexity: O(m + n); m = size of violating indices array, n = size of answer array (= queries array)
*/
/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean[]}
 */

const binarySearch = (from, to, violatingIndices) => {
    let left = 0, right = violatingIndices.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) >> 1);
        if (violatingIndices[mid] < from) left = mid + 1;
        else if (violatingIndices[mid] > to) right = mid - 1;
        else return true;
    }
    return false;
 }
var isArraySpecial = function(nums, queries) {
    let violatingIndices = [];
    let answer = [];
    for (let i = 0; i < nums.length - 1; ++i) {
        if (nums[i] % 2 === nums[i+1] % 2)
            violatingIndices.push(i);
    }

    for (let query of queries) {
        let isViolatingIndex = binarySearch(query[0], query[1] - 1, violatingIndices);
        answer.push(!isViolatingIndex);
    }
    
    return answer;
};