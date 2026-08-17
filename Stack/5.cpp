//CELEBRITY PROBLEM
#include <bits/stdc++.h>
using namespace std;

int celebrity_problem(vector<vector<int>> arr)
{
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        s.push(i);
    }

    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if (arr[i][j] == 0)
        {
            // eliminate kar rahe j ko
            s.push(i);
        }
        else
        {
            // eliminate i
            s.push(j);
        }
    }

    int celeb = s.top();
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != celeb && (arr[i][celeb] == 0 || arr[celeb][i] == 1))
        {
            return -1;
        }
    }
    return celeb;
}
int main()
{
    vector<vector<int>> arr = {{0, 1, 0},
                               {0, 0, 0},
                               {0, 1, 0}};
    int celeb = celebrity_problem(arr);
    cout << celeb << endl;
    return 0;
}
