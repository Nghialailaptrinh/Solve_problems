// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

// Define a pair (u, v) which consists of one element from the first array and one element from the second array.

// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

// Example 1:

// Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// Output: [[1,2],[1,4],[1,6]]
// Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// Example 2:

// Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// Output: [[1,1],[1,1]]
// Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 105
// -109 <= nums1[i], nums2[i] <= 109
// nums1 and nums2 both are sorted in non-decreasing order.
// 1 <= k <= 104
// k <= nums1.length * nums2.length

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector <vector<int>> result;
        
        //copy and sort
        vector <int> n1 = nums1;
        vector <int> n2 = nums2;
        int size_1 = n1.size();
        int size_2 = n2.size();
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());

        //create a min heap
        //Ta tao ra một mảng cặp cho n1
        // VD: n1[1,2,3,4], n2[5,6,7,8], k = 3
        // pair[0,1,3,2] -> cặp[(1,5), (2,6), (3,8), (4,7)]
        // Ta đẩy các cặp trên vào queue (-> sẽ chỉ chứa n1.size() cặp)
        // nếu lấy cặp (1,5) -> ta sẽ đẩy cặp (1,6) vào queue
        // Ta nhận ra không cần tạo mảng pair

        priority_queue <pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> min_heap;
        if(!n1.empty() && !n2.empty()){
            for(int i = 0; i < n1.size(); i++){
                min_heap.push({n1[i] + n2[0], {n1[i], 0}});
            }
            while(!min_heap.empty() && result.size() < k){
                auto top = min_heap.top();
                min_heap.pop();
                result.push_back({top.second.first, n2[top.second.second]});
                if(top.second.second + 1 < n2.size()){
                    min_heap.push({top.second.first + n2[top.second.second + 1], {top.second.first, top.second.second + 1}});
                }
            }
        }
    

        return result;
    }
};