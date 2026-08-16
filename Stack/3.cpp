//NEXT GREATER ELEMENT
// CRUCIAL QUES
#include <bits/stdc++.h>
using namespace std;
vector<int> next_greater_element(vector<int> nums)
{
    vector<int> ans(nums.size(), -1);
    stack<int> s;
    for (int i = (int)nums.size() - 1; i >= 0; i--)
    {
        // removing invalid char
        while (s.size() > 0 && s.top() <= nums[i])
        {
            s.pop();
        }
        if (s.size() == 0)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(nums[i]);
    }
    return ans;
}
int main()
{
    vector<int> nums = {4, 0, 6, 3, 8, 9};
    vector<int> ans = next_greater_element(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
