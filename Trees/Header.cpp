
#include <iostream>
using namespace std;
#ifndef Queuetree_h
#define Queuetree_h


class Node 
{
    public:
     Node *lchild;
     int data;
      Node *rchild;
};
class Queue
{
private:
 int front;
 int rear;
 int size;
 int *Q;
public:
 
 Queue(int size){
     front=rear=-1;
     this->size=size;
     Q=new Node*[this->size];}   //Every element of the queue is the Node
 void enqueue(Node *x);
 Node* dequeue();
 void Display();
};
void Queue::enqueue(Node *x)
{
 if(rear==size-1)
 printf("Queue Full\n");
 else
 {
 rear++;
 Q[rear]=x;
 }
}
Node* Queue::dequeue()
{
 Node *x=-1;
 if(front==rear)
 printf("Queue is Empty\n");
 else
 {
 x=Q[front+1];
 front++;
 }
 return x;
}
void Queue::Display()
{
 for(int i=front+1;i<=rear;i++)
 printf("%d ",Q[i]);
 printf("\n");
}
int main()
{
 Queue q(5);

 q.enqueue(10);
 q.enqueue(20);
 q.enqueue(30);

 q.Display();
 return 0;
}