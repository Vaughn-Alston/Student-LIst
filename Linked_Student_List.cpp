#include <iostream>
using namespace std;


//Creating the Node Class
class Node
{
    public:
    int data;
    Node* next;
    //constructor to initialize node with data
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
}; // End of Node Class

//Start of LinkedList Class
class LinkedList
{
    private:
    
    Node*head;
    public:
    //constructor to initalize a empty list
    LinkedList()
    {
        head = nullptr;
    }

    void setHead(Node*node)
    {
        head = node;
    }
    void display()
    {
        Node* curr = head;

        while(curr != nullptr)
        {
            cout << curr-> data << " ";
            curr = curr->next;
        }
        cout << "Null" << endl;
    }// end of display function

    


    





};//End of LinkedList