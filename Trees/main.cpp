#include<bits/stdc++.h>
#include "Queetree.h"

class Tree
{
 public: 
    Node *root;   
    Tree(){
        root=NULL;
    }
    void CreateTree();
    void Preorder(Node *x);
    void Postorder(Node *x);
    void Inorder(Node *x);
    void levelorder(Node *X);
    int Height(Node *x);

};
void Tree::CreateTree()
{
       Node *p,*t;
      int data;
       Queue q(100);
       printf("Enter -1 incase of no values");
       printf("Enter root Value");
       cin>>data;
       root=new Node;
       root->data=data;
       root->lchild=root->rchild=NULL;
       q.enqueue(root);
      while(!q.isEmpty())
      {   

          p=q.dequeue();
           cout<<"Enter left child";
           cin>>data;
           if(data!=-1)
           {
           t=new Node;
           t->data=data;
           t->lchild=t->rchild=NULL;
           p->lchild=t;
           q.enqueue(t);
           }
           cout<<"Ente right child ");
           cin>>data;
           if(data !=-1)
           {
               t=new Node;
               t->data=data;
               t->lchild=t->rchild=NULL;
               p->rchild=t;
               q.enqueue(t);
           }
      }


}


void Tree::Preorder(struct Node *p)
{
    if(p)
    {
          cout<<p->data;
          Preorder(p->lchild);
          Preorder(p->rchild);
    }
}


void Tree::Inorder(struct Node *p)
{
    if(p)
    {
          
          Inorder(p->lchild);
          cout<<p->data;
          Inorder(p->rchild);
    }
}



void Tree::Postorder(struct Node *p)
{
    if(p)
    {
          
          PostOrder(p->lchild);
          Postorder(p->rchild);
          cout<<p->data;
         
    }
}



void Tree::levelorder(Struct Node *root)

{
 Queue q(100);
 cout<<root->data;
 q.enqueue(root);
 while(!q.isEmpty())
 {
     root =q.dequeue();
     if(root->lchild)
     {
        cout<<root->lchild->data;   //not a recursion both will be executed simultaneously
        q.enqueue(root->lchild);


     }
      if(root->rchild)
     {
        cout<<root->rchild->data;
        q.enqueue(root->rchild);

     }
 }

}

int Tree::Height(strict Node *root )
{
    int x=0,y=0;
    if(root==0)
      return 1;
      x=Height(root->lchild);
      y=Height(root->rchild);
      if(x>y)
         return x+1;
      else
         return y+1;
}



int main()
{
    Tree t;                            //root is the public member of the class
    t.CreateTree();
    t.Preorder(t.root);
    t.Inorder(t.root);
    t.Postorder(t.root);
    t.levelorder(t.root);
    t.Height(t.root);
}