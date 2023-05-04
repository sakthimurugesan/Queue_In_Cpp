#include <iostream>
#define n 5
using namespace std;
int Front=-1,rear=-1;
int queue[n];
void enqueue(int N)
{
    if(rear<n)
    {
        rear++;
        queue[rear]=N;
        if(rear>-1)
        {
            Front=0;
        }
    }
    else
    {
        cout<<"Stack is full\n";
    }
}
void dequeue()
{
    
    Front++;
}
int front()
{
return queue[Front];
}
int back()
{
return queue[rear-1];
    
}

void display()
{
    for(int i=Front;i<n;i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    for(int i=1;i<=6;i++)
    {
        enqueue(i);
    }
    display();
    dequeue();
    display();
    cout<<front()<<endl<<back();

}