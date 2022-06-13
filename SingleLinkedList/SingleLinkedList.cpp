#include <iostream>
using namespace std;

class Node
{
public:
    Node*next;
    int info;
};

class SLL
{
private:
    Node*head;
    Node*tail;
public:
    SLL(){
        head = tail = NULL;
    }
    SLL(int value)
    {
        Node*newnode;
        newnode = new Node;
        newnode->info = value;
        newnode->next = NULL;
        head = tail = newnode;
    }
    void insertathead(int value)
    {
        Node*newnode;
        newnode = new Node;
        newnode->info = value;
        newnode->next = head;
        head = newnode;
    }
    void insertattail(int value)
    {
        Node*newnode;
        newnode = new Node;
        newnode->info = value;
        tail->next = newnode;
        newnode->next = NULL;
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
        tail->next = NULL;
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
        while(current != NULL)
        {
            if(current->info == value){
                cout<<current->info<<"  it is in position : "<<count<<endl;
                break;
            }
            current = current->next;
            count++;
        }
        if(current == NULL){
            cout<<" this value not found "<<endl;
        }
    }
    friend ostream & operator << (ostream&print, SLL&sll)
    {
        Node*current = new Node;
        current = sll.head;
        while(current != NULL)
        {
            print<<current->info <<" ";
            current = current->next;
        }
        return print;
    }
};

int main()
{
    SLL sll(9);
    sll.insertathead(5);
    sll.insertattail(20);
    sll.insertinposition(12,2);
    sll.insertathead(3);
    sll.insertattail(30);
    sll.insertinposition(17,4);
    cout<<sll<<endl<<endl;
    sll.deletefromhead();
    sll.deletefromtail();
    sll.deleteinposition(3);
    cout<<sll<<endl<<endl;
    sll.deleteinposition(0);
    cout<<sll<<endl<<endl;
    sll.insertinposition(2,0);
    cout<<sll<<endl<<endl;
    sll.search(9);
    sll.search(20);
    sll.search(30);
    return 0;
}
