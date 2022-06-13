#include <iostream>
using namespace std;

class Node
{
    public:
        int info;
        Node* next;
        Node* prev;
};

class DLL
{
    private:
        Node *head;
        Node *tail;
    public:
        DLL(){
            head = tail = NULL;
        }
        DLL(int value)
        {
            Node*newnode;
            newnode = new Node;
            newnode->info = value;
            newnode->next = newnode->prev = NULL;
            head = tail = newnode;
        }
        void insertathead(int value)
        {
            Node*newnode;
            newnode = new Node;
            newnode->info = value;
            head->prev = newnode;
            newnode->next = head;
            newnode->prev = NULL;
            head = newnode;
        }
        void insertattail(int value)
        {
            Node*newnode;
            newnode = new Node;
            newnode->info = value;
            tail->next = newnode;
            newnode->prev = tail;
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
                newnode->prev = point;
                newnode->next->prev = newnode;
            }
        }
        void deletefromhead()
        {
            Node*ptr = head;
            head = head->next;
            head->prev = NULL;
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
                Node*oldnode = point->next;
                Node*ptr = oldnode->next;
                point->next = ptr;
                ptr->prev = point;
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
        friend ostream & operator << (ostream&print, DLL&dll)
        {
            Node*current = new Node;
            current = dll.head;
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
    DLL dll(9);
    dll.insertathead(5);
    dll.insertattail(20);
    dll.insertinposition(12,2);
    dll.insertathead(3);
    dll.insertattail(30);
    dll.insertinposition(17,4);
    cout<<dll<<endl<<endl;
    dll.deletefromhead();
    dll.deletefromtail();
    dll.deleteinposition(3);
    cout<<dll<<endl<<endl;
    dll.deleteinposition(0);
    cout<<dll<<endl<<endl;
    dll.insertinposition(2,0);
    cout<<dll<<endl<<endl;
    dll.search(9);
    dll.search(20);
    dll.search(30);
    return 0;
}
