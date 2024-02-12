#include<iostream>
#include<string.h>
#define MX 20
using namespace std;
struct node{
    char data;
    node *left,*right;
};
node *top;
class cStack{
    node *exp[MX];
    int top;

    public:
        cStack()
        {
            top=-1;
        }
        void push(node *e)
        {
            if(isFull())
                cout<<"Empty";
            else{
                top++;
                exp[top]=e;
            }
        }

        node *pop()
        {
            if(isEmpty())
                cout<<"Stack is Empty...";
            else
            {
                return(exp[top--]);
            }
        }
        int isEmpty()
        {
            if(top==-1)
                return 1;
            else
                return 0;
        }
        int isFull()
        {
            if(top==MX-1)
                return 1;
            else
                return 0;
        }
};


class eTree{
    public:

        void expr(string ex)
        {
            cStack s;
            int len=ex.length();
            for(int i=len-1;i>=0;i--)
            {
                top=new node;
                top->left=NULL;
                top->right=NULL;
                if(isalpha(ex[i]))
                {
                    top->data=ex[i];
                    s.push(top);
                }
                else if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/')
                    {
                        node *t1,*t2;
                        t1=s.pop();
                        t2=s.pop();
                        top->data=ex[i];
                        top->left=t1;
                        top->right=t2;
                        s.push(top);
                    }


            }
            top=s.pop();

        }

        void postOrd(node *t)
        {
            cStack s1,s2;
            node *t1=top;
            s1.push(t1);
            while(!s1.isEmpty())
            {
                t1=s1.pop();
                s2.push(t1);
                if(t1->left!=NULL)
                {
                    s1.push(t1->left);
                }
                if(t1->right!=NULL)
                {
                    s1.push(t1->right);

                }

            }
                while(!s2.isEmpty())
                {
                    node *t2;
                    t2=s2.pop();
                    cout<<t2->data;

                }
                /*
                node *t1=t;
                while(t1!=NULL)
                {
                    postOrd(t1->left);
                    postOrd(t1->right);
                    cout<<t1->data;
                }*/




        }
        void del(node *top)
        {

            del(top->left);
            del(top->right);
            delete(top);
        }
};
int main()
{
    string prExp;
    cout<<"Enter prefix expression...";
    cin>>prExp;

    eTree e;
    e.expr(prExp);

    e.postOrd(top);
   e.del(top);
    return 0;
}
