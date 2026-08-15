#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <stack>

// class Stack
// {
// public:
//     vector<int> v;

//     void push(int val)
//     {
//         v.push_back(val);
//     }

//     void pop()
//     {
//         if (!v.empty())
//         {
//             v.pop_back();
//         }
//     }

//     int top()
//     {
//         if (!v.empty())
//         {
//             return v[v.size() - 1];
//         }
//         return -1; // Return -1 if the stack is empty
//     }

//     bool empty()
//     {
//         // return v.empty();
//         return v.size() == 0;
//     }
// };

// STACK USING LINKED LIST
// class Stack
// {
// public:
//     list<int> ll;

//     void push(int val)
//     {
//         ll.push_front(val);
//     }

//     void pop()
//     {
//         if (!ll.empty())
//         {
//             ll.pop_front();
//         }
//     }

//     int top()
//     {
//         if (!ll.empty())
//         {
//             return ll.front();
//         }
//         return -1; // Return -1 if the stack is empty
//     }

//     bool empty()
//     {
//         // return ll.empty();
//         return ll.size() == 0;
//     }
// };

int main()
{
    // Stack s;
    stack<int> s;
    s.push(10);
    s.push(20);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
