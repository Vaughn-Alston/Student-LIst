#include <iostream>
using namespace std;

// A linked list is a numer of values being connected by pointers.

// 
//Creating the Node Class.
class Node
{
    public:
    int data; // data and string are the two user variables 
    string name; 
    Node* next;

    //constructor to initialize node with data.
    Node(string student, int value)
    {
        name = student;
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
            cout << curr-> name << "Student ID : " << curr-> data << "\n "<<
            "\n------------------------------------------------------\n";
             //curr is at the head this line will read the int data inside.
            curr = curr->next; // this line will curr = curr -> will read the data to the next of curr.

        }
        cout << "Null" << endl;
    }// end of display function

    void DeleteNode(int m)
    {
        Node* curr = head;  // cursor point to head of list.
        Node* temp = nullptr; // temp points to nothing 
        

        while(curr != nullptr && curr-> data != m)
        {
            temp = curr;
            curr = curr-> next;
        }
        if(curr == nullptr)
        {
            cout << "Student ID:" << m << " not in list";
            return;
        }
        if(curr == head)
        {
            head = head-> next;
        } else{
            temp-> next = curr-> next;
        }
        delete curr;
        cout << "\n Student with ID: " << m << " was deleted\n";
    }// End of Delete Node Function 

    //Appending function
    void addAtEnd(string student, int data)
    {

       Node* n = new Node(student, data);

       if (head == nullptr)
       {
        head = n;
       } 
       else{
        Node* curr = head;
        while(curr-> next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = n;
       }
       cout << student << " (" << data << ") Added to list \n\n"; 

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

    Node* searchLinkedlist(int search)
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

// I want to allow the user to define each ID with a Name.

int main()
{
    LinkedList list;

    //function variables
    int search, remove, value ,  choice, size;
    string name;


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
       cout << "Enter Student Name " << i << " : ";
       cin >> name;
       cout << "Enter Student ID " << i << " : ";
       cin >> value;

       list.addAtEnd(name, value);

    }
    
    

    while(true)
    {
        cout << "\n\n<-------Student Directory------->\n"<<
                 "\n 1. Display Student List\n" <<
                 "\n 2. Remove Student from List\n"<<
                 "\n 3. Search Student ID\n" <<
                 "\n 4. Add Student to end\n" << 
                 "\n 5. Size of Class\n" <<
                 "\n 6. Close Program\n";

                 cout << "\nSelect a Chocie :";
                 cin >> choice;

                 if(choice == 1)
                 {
                    cout << "\nDisplaying Student Roster\n" <<
                            "---------------------------\n";
                    list.display();
                 }  
                else if (choice ==  2) 
                {
                    cout << "\nEnter ID to remove : ";
                    cin >> remove;

                list.DeleteNode(remove);
                

                } 
                else if (choice == 3)
                {
                    //The User has to use the users Student ID to remove, or search
                    cout << "\nEnter ID to search : ";
                    cin >> search;

                   Node* found = list.searchLinkedlist(search);
                    if (found)
                    {
                        cout << "\nFound: " << found->name << " (" << found-> data << ")\n";
                    }   
                    else 
                    {
                        cout << "\nID NOT FOUND.\n";
                    }
                       
                 }
                 else if (choice == 4)
                 {
                    cout << "\nEnter Student Name : ";
                    cin >> name;
                    cout << "\nEnter Student ID : ";
                    cin >> value;
                    list.addAtEnd(name, value);
                 }
                 else if(choice == 5)
                 {
                    cout << "Current Class Size : " << list.getSize() << "\n";
                 }
                 else if(choice == 6)
                 {
                    cout << "\nExiting Program. \n";
                    break;
                 }
                 else {
                    cout << "\nInvalid chocie. Try again. \n";
                 }


    }
    return 0;

}
