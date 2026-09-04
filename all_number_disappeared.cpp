#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> disappear;
        sort(nums.begin(), nums.end());
        for(int i = 1; i <= nums.size(); i++)
        {
            if (!binary_search(nums.begin(), nums.end(), i))
            {
                disappear.push_back(i);
            }
        }
        return disappear;
    }
};