//STOCK SPAN PROBLEM
#include <bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> price)
{
    stack<int> s;
    vector<int> ans(price.size(), 0);
    for (int i = 0; i < price.size(); i++)
    {
        while (s.size() > 0 && price[s.top()] <= price[i])
        {
            s.pop();
        }
        if (s.size() == 0)
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - s.top();
        }
        s.push(i);
    }
    return ans;
}
int main()
{
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    cout << "The stock span is: ";
    vector<int> ans = stockspan(price);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
