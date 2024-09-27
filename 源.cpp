#include <vector>
using namespace std;
class Solution
{
public:
    void backTrack(vector<int>& path, int startIndex, int k, int n)
    {
        // if (startIndex + k > n)
        //     return;
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            backTrack(path, i + 1, k, n);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        if (k > n)
            return res;
        vector<int> path;
        backTrack(path, 1, k, n);
        return res;
    }

private:
    vector<vector<int>> res;
};