/*Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        int n = temperatures.size();
        result[n-1] = 0; // Ngày cuối cùng không có ngày nào sau nó
        for( int i = n-2; i >= 0; i--) {
            if(temperatures[i] < temperatures[i+1]) {
                result[i] = 1;
            } else {
                // truy hồi: tìm tới này có nhiệt độ cao: i+1 + result[i+1]
                int j = i + 1 + result[i + 1];
                while(j < n && temperatures[j] <= temperatures[i]) {
                    if(result[j] == 0) {
                        j = n;
                    } else {
                        j += result[j];
                    }
                }
                if(j < n) {
                    result[i] = j - i;
                }
            }
        }
        return result;
    }
};