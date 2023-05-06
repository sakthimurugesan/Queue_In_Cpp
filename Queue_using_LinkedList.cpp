#include <iostream>
using namespace std;
struct queue
{
    int data;
    queue *next;
};
queue *Front, *Back;
void enqueue(int n)
{
    queue *obj = new queue();
    obj->data = n;
    obj->next = 0;
    if (Front == 0)
    {
        Front = obj;
        Back = obj;
    }
    else
    {
        Back->next = obj;
        Back = obj;
    }
}
void dequeue()
{
    if (Front == 0)
    {
        cout << "Queue is empty";
        return;
    }
    else
    {
        queue *temp=Front;
        Front = Front->next;
        delete temp;
    }
}
int front()
{
    if (Front == 0)
    {
        cout << "Queue is empty";
        return 0;
    }
    return Front->data;
}
int back()
{
    if (Front == 0)
    {
        cout << "Queue is empty";
        return 0;
    }
    return Back->data;
}
bool isEmpty()
{
    if (Front == 0)
    {
        return true;
    }
    return false;
}
void display()
{
    queue *temp = Front;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}
int main()
{
    Front = 0;
    Back = 0;
    for(int i=1;i<=10;i++)
    {
        enqueue(i);
    }
    display();
    dequeue();
    display();
    cout<<front()<<endl<<back();
}