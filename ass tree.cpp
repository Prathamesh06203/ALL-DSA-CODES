#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
};
class stackk{
    node *nn,*top;
    public:
    stackk();
    void push()
    {
      if(top==NULL)
      {
        cout << "Stack Is Empty"<< endl;
      }
      else{
        nn=new node;
        cout << "Enter data" << endl;
        cin>>nn->data;
        nn->next=top;
        top=nn;
      }
    }
    void pop()
    {
        node *temp=top;
        top=top->next;
        int x=temp->data;
        delete temp;

    }
    void isempty()
    {
        if(top==NULL)
        {
            cout << "Stack is Empty " << endl;
    
        }
        else
        {
                cout << "Stack is not Empty" << endl;
        }
    }
    void dispaly()
    {
        node *temp=top;
        cout << "Stack is :"<<endl;
        while(temp!=NULL)
        {
            cout << temp->data;
            temp=temp->next;
        }
    }

};
int main()
{
    stackk s;
    s.push();
    s.pop();
    s.dispaly();
    s.isempty();
    return 0;
}
