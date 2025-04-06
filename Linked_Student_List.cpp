#include <iostream>
using namespace std;

// A linked list is a numer of values being connected by pointers.


//Creating the Node Class.
class Node
{
    public:
    int data;
    Node* next;
    //constructor to initialize node with data.
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
}; // End of Node Class.

//Start of LinkedList Class.
class LinkedList
{
    private:
    
    Node*head;
    public:
    //constructor to initalize a empty list.
    LinkedList()
    {
        head = nullptr; // ensure the head is empty.
    }

    void setHead(Node*node)
    {
        head = node; // Head is Literally Node.
    }
    void display() 
    {
        Node* curr = head; // Node pointer curr = head.

        while(curr != nullptr) // while not at the end of the list.
        {
            cout << curr-> data << " "; //curr is at the head this line will read the int data inside.
            curr = curr->next; // this line will curr = curr -> will read the data to the next of curr.
        }
        cout << "Null" << endl;
    }// end of display function

    void DeleteNode(int m)
    {
        Node* dptr = nullptr; 
        Node* temp = head; //temp node point to first value in list.
        Node* curr = head; //curr node also points at the first value in the node.

        while(curr != nullptr && curr->data != m) // Loop while curr not at the end of list and curr not equal to data.
        {
            temp = curr; //temp node and curr are at the same position.
            curr = curr-> next; //curr = curr point to the next node.

        }
        if (curr = nullptr) //if we reach the  end of the list
        {
            cout << m << "not in list\n"; 
        }

        //if we exit the loop
        delete dptr;
        cout << "The Value " << m << "was deleted";
    }// End of Delete Node Function 

    void addNode(int num)
    {
        Node* n = new Node(num);
        n-> next = head; 
        cout << num << "Added to list" << endl;

    }
    //Appending function
    void addAtEnd(int num)
    {
        Node* n = new Node(num); // new int num
        n-> data = num;  
        if(head == nullptr) //empty list
        {
            head = n;
            n-> next = nullptr; // the value will become the head and the next value will be empty
        }
        else
        {
            Node* curr = head;

            while(curr-> next != nullptr) // While curr not at the end of the list move to the next.
            {
                curr = curr-> next;
            } // end of while loop
            curr->next = n;
        }// end of else statement
    } // end of at end function

    //find the size of Linkedlist
    int getSize()
    {
        int count = 0;
        Node* temp = head; // temp node points at head of list

        while(temp != nullptr) // while the temp node not equal to empty value/nullptr
        {
            count++;  // increate counter down the list
            temp = temp-> next; 
            
        }
        return count; // return size of the increment.
    }
    
    






};//End of LinkedList