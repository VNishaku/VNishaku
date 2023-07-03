//reverse stack?
#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        int temp = input.top();
        input.pop();
        for (int j = 0; j < n - i - 1; j++)
        {
            extra.push(input.top());
            input.pop();
        }

        input.push(temp);

        for (int j = 0; j < n - i - 1; j++)
        {
            input.push(extra.top());
            extra.pop();
        }
    }
}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}