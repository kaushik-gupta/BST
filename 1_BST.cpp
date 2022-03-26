#include<iostream>

using namespace std;

struct node
{

    int data;
    node *left;
    node *right;
};

node *Getnewnode(int data)
{

    node *newnode = new node();
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node *head = NULL;

node *Insert(node *head, int data)
{

   if(head==NULL)
      {

          node *nnode = Getnewnode(data);
          head = nnode;
          return head;
      }

   else if(data>head->data)
   {
        head->right = Insert(head->right, data);
   }
   else if(data<= head->data)
   {

       head->left = Insert(head->left, data);
   }
}

bool Search(node *head, int s)
{
if(head)
{

   if(head->data==s)
    return true;
   else if(head->data>s)
    Search(head->left,s);
   else if(head->data<s)
    Search(head->right,s);
}
   else if(head==NULL)
    return false;
}

int InDisplay(node *head)   // In order gives the sorted order.
{
    if(head==NULL)
        return 0;
    InDisplay(head->left);
    cout<<head->data<<" ";
    InDisplay(head->right);
}

int PreDisplay(node *head)
{
    if(head==NULL)
        return 0;
        cout<<head->data<<" ";
        PreDisplay(head->left);
        PreDisplay(head->right);
}

int PostDisplay(node *head)
{

    if(head==NULL)
        return 0;

        PostDisplay(head->left);
        PostDisplay(head->right);
        cout<<head->data<<" ";
}

int main()
{

   node *head = NULL;
   cout<<"Enter 'y' to insert element" <<endl;
   char ch;
   while(1)
   {
       cout<<"Want to insert element? "<<endl;
       cin>>ch;
       if(ch!='y')
        break;
       else
       {
           int value;
           cout<<"Enter the value"<<endl;
           cin>>value;

           head = Insert(head, value);
       }
   }
   cout<<"Enter element to be searched: "<<endl;
   int num;
   cin>>num;
   bool b = Search(head, num);
   if(b==true)
   cout<<"The number is present "<<endl;
   else
    cout<<"The number is not present "<<endl;
    cout<<"The Pre order traversal of the BST is: "<<endl;
    PreDisplay(head);
    cout<<endl<<"The In order traversal of the BST is: "<<endl;
    InDisplay(head);
    cout<<endl<<"The Post order traversal of the BST is: "<<endl;
    PostDisplay(head);

return 0;
}
