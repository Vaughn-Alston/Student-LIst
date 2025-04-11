#include <iostream>
using namespace std;

// A linked list is a numer of values being connected by pointers.


//Creating the Node Class.
class Node
{
    public:
    int data; // data and string are the two user variables 
    

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

    void display() 
    {
        Node* curr = head; // Node pointer curr = head.

        while(curr != nullptr) // while not at the end of the list.
        {
            cout << curr-> data 
            << "    " << 
        "\n--------------------\n"; //curr is at the head this line will read the int data inside.
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
        if (curr == nullptr) //if we reach the  end of the list
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

    //Search function for linked list

    Node* searchLinkedlist(Node*head, int search)
    {
        Node* temp = head; // Start from the head of the node
    
    while( temp != nullptr)
    {
        if(temp-> data == search)
        {
            return temp; // return the node if target is found.
        }
        
        temp = temp-> next; // if not found move to next Node
    }
    return nullptr; // return nohting if target not found
    } // end of search function


};//End of LinkedList

//Starting the Driver Class
// my plan is to make my program user friendly prompting the user with 4 choices while stuck in a true loop untill they break
//user will have a choice to 1 - display list, 2- remove student, 3- searchID, 4- addtoend. 5- exit;


int main()
{
    LinkedList list;

    //function variables
    int search, remove, value;


    //Driver Variables;// I want the user to be able to choose the size of their roster.
    int choice, size;


 // size of linked list
    cout << "Enter the Size of your class :";
    cin >> size;

    if(size <= 0)
    {
        cout << "List size must be postive.\n";
        return 0;
    }

    // adding to the linked list with the addAtEnd Function
    for(int i = 1; i <= size; i++)
    {
        cout << "Enter Student " << i << ": ";
        cin >> value;
        list.addAtEnd(value);
    }
    
    

    while(true)
    {
        cout << "\n\n<-------Student Directory------->\n"<<
                 "\n 1. Display Student List\n" <<
                 "\n 2. Remove Student from List\n"<<
                 "\n 3. Search Student ID\n" <<
                 "\n 4. Add Student to end\n" << 
                 "\n 5. Size of Class\n" <<
                 "\n 5. Close Program\n";

                 cout << "\nSelect a Chocie :";
                 cin >> choice;

                 if(choice == 1.)
                 {
                    cout << "Displaying Student Roster\n" <<
                            "---------------------------\n";
                    list.display();
                 }


    }


}
