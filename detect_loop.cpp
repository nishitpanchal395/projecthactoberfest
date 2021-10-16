#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
    int flag;
};
node *head = NULL;
void insert(int d)
{
   
   node *ptr=new node();
    ptr->data=d;
    ptr->flag=0;
    ptr->link=NULL;
    if(head==NULL)
    head=ptr;
    else{
        node*temp =head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=ptr;
    }
}

void display()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->link;
    }
    cout << "\n";
}
bool deletect_loop(node *h)
{
    while (h != NULL)
    {
        if (h->flag == 1)
            return true;
        h->flag = 1;
        h = h->link;
    }
    return false;
}
int main()
{
    insert(1);
    display();
    cout << endl;
    insert(2);
    display();
    cout << endl;
    insert(3);
    display();
    cout << endl;
    insert(4);
    display();
    cout << endl;
    cout << endl;
    head->link->link->link->link=head;
    if(deletect_loop(head))
    cout<< "true";
    else
    cout<<"false";
    return 0;
    
}