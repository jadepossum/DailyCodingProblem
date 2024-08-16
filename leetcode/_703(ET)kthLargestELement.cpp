// class KthLargest {
// public:
//     priority_queue<int, vector<int>, greater<int>> pq;
//     int size;
//     KthLargest(int k, vector<int>& nums) {
//         size = k;
//         if (nums.size() < k) {
//             for (auto i : nums) {
//                 pq.push(i);
//             }
//         }
//         else{
//             int i = 0;
//             for (; i < k; i++) {
//                 pq.push(nums[i]);
//             }

//             while (i < nums.size()) {
//                 if (pq.top() < nums[i]) {
//                     pq.pop();
//                     pq.push(nums[i]);
//                 }
//                 i++;
//             }
//         }
//     }

//     int add(int val) {
//         if(pq.size()<size){
//             pq.push(val);
//         }
//         else if (pq.top() < val) {
//             pq.pop();
//             pq.push(val);
//         }
//         return pq.top();
//     }
// };



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Implement KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 

// Example 1:

// Input
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]

// Explanation
// KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
// kthLargest.add(3);   // return 4
// kthLargest.add(5);   // return 5
// kthLargest.add(10);  // return 5
// kthLargest.add(9);   // return 8
// kthLargest.add(4);   // return 8
 