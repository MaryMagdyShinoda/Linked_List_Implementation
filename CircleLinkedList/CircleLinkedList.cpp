#include <iostream>
using namespace std;

class Node
{
public:
    Node*next;
    int info;
};

class CLL
{
private:
    Node*head;
    Node*tail;
public:
    CLL(){
        head = tail = NULL;
    }
    CLL(int value)
    {
        Node*newnode;
        newnode = new Node;
        newnode->info = value;
        newnode->next = newnode;
        head = tail = newnode;
    }
    void insertathead(int value)
    {
        Node*newnode;
        newnode = new Node;
        newnode->info = value;
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
    void insertattail(int value)
    {
        Node*newnode;
        newnode = new Node;
        newnode->info = value;
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
    void insertinposition(int value, int position)
    {
        if(position==0)
            insertathead(value);
        else{
            Node*newnode;
            newnode = new Node;
            newnode->info = value;
            Node*point = head;
            for(int i=1; i<position; i++)
            { point = point->next; }
            newnode->next = point->next;
            point->next = newnode;
        }
    }
    void deletefromhead()
    {
        Node*ptr = head;
        head = head->next;
        tail->next = head;
        delete ptr;
    }
    void deletefromtail()
    {
        Node*oldnode = tail;
        Node*ptr = head;
        while(ptr->next != tail){
            ptr = ptr->next;
        }
        tail = ptr;
        tail->next = head;
        delete oldnode;
    }
    void deleteinposition(int position)
    {
        if(position==0)
            deletefromhead();
        else{
            Node*point = head;
            for(int i=1; i<position-1; i++)
            { point = point->next; }
            Node*ptr = point;
            Node*oldnode = point->next;
            ptr->next = oldnode->next;
            delete oldnode;
        }
    }
    void search (int value)
    {
        int count = 0;
        Node*current = new Node;
        current = head;
        do
        {
            if(current->info == value){
                cout<<current->info<<"  it is in position : "<<count<<endl;
                break;
            }
            current = current->next;
            count++;
        }
        while(current != head);
        if(current != head){
            cout<<" this value not found "<<endl;
        }
    }
    friend ostream & operator << (ostream&print, CLL&cll)
    {
        Node*current = new Node;
        current = cll.head;
        do
        {
            print<<current->info <<" ";
            current = current->next;
        }
        while(current != cll.head);
        return print;
    }
};

int main()
{
    CLL cll(9);
    cll.insertathead(5);
    cll.insertattail(20);
    cout<<cll<<endl<<endl;
    cll.insertinposition(12,2);
    cll.insertathead(3);
    cll.insertattail(30);
    cll.insertinposition(17,4);
    cout<<cll<<endl<<endl;
    cll.deletefromhead();
    cll.deletefromtail();
    cll.deleteinposition(3);
    cout<<cll<<endl<<endl;
    cll.deleteinposition(0);
    cout<<cll<<endl<<endl;
    cll.insertinposition(2,0);
    cout<<cll<<endl<<endl;
    cll.search(9);
    cll.search(20);
    cll.search(30);
    return 0;
}
