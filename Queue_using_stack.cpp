#include <iostream>
#define max_size 10
using namespace std;
class Solution
{
private:
    int top1 = -1, top2 = -1;
    int stack1[max_size];
    int stack2[max_size];

public:
    void enqueue(int val)
    {
        if (top1 < max_size)
        {
            top1++;
            stack1[top1] = val;
            top2 = -1;
            for (int i = top1; i >= 0; i--)
            {
                top2++;
                stack2[top2] = stack1[i];
            }
        }
    }
    void dequeue()
    {
        if (top1 >= 0)
        {
            top2--;
            top1 = -1;
            for (int i = top2; i >= 0; i--)
            {
                top1++;
                stack1[top1] = stack2[i];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < top1 + 1; i++)
        {
            cout << stack1[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Solution s;
    for (int i = 1; i <= 10; i++)
        s.enqueue(i);
    for (int i = 0; i < 10; i++)
    {
        s.dequeue();
        s.display();
    }
}