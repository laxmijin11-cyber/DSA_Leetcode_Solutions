//PRINTING NUMBERS IN REVERSE FASHION 
#include <bits/stdc++.h>
using namespace std;

void printNums(int n)
{
    if (n == 1)
    {
        cout << "1"<<" ";
        return;
    }
    cout << n;
    printNums(n - 1);
}
int main()
{
    printNums(10);
    return 0;
}
//DONT USE printNums like it can cause error as print is keyword
