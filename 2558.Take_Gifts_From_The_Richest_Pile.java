/*
Time Complexity:
- Inserting into priority queue takes O(log n), where n = size of gifts.
So, totally it's O(n log n)
- For each 'k', where 1 <= k <= 10^3, we are doing the operations on priority queue elements
and accessing the elements take log n time. 
- In the end, we are going through all the elements in the priority queue O(n)
Total Time Complexity = O(n log n + k log n + n log n) 
= O((2n + k) log n)
= O((n + k) log n)
Space Complexity: O(n) as we are storing n gifts in priority queue.
*/


class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        long giftsRemaining = 0;
        for (var gift : gifts) {
            pq.add(gift);
        }
        while(k > 0) {
            pq.add((int)Math.floor(Math.sqrt(pq.poll())));
            k--;
        }

        while(pq.size() > 0) giftsRemaining += pq.poll();

        return giftsRemaining;
    }
}