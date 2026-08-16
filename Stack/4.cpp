//PREVIOUS SMALLER ELEMENT USING STACK
#include <bits/stdc++.h>
using namespace std;
vector<int> prev_smaller_element(vector<int> arr)
{
    stack<int> s;
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        while (s.size() > 0 && s.top() >= arr[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 6, 7, 2, 5, 0, 1};
    vector<int> ans = prev_smaller_element(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
