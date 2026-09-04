#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;

        // Thêm một số 0 giả ở cuối
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {

                int h = heights[st.top()];
                st.pop();

                int left;

                if (st.empty())
                    left = -1;
                else
                    left = st.top();

                int width = i - left - 1;

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};