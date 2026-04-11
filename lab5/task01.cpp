#include<iostream>
using namespace std;
#include "Node.h"

void display(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
Node* copy(Node* head)
{
    /*
This function creates a deep copy of a linked list.
It first checks if the given list is empty. If yes, it returns null
Otherwise, it creates a new head node and copies the data of the first node
Then it uses two pointers:
 one to move through the original list
 one to build the new list
For each node in the original list, it creates a new node,
copies the data, and links it to the new list.
At the end, it returns the head of the new list.
The new list is completely separate from the original list.
*/
    if (head == nullptr) //checking if its empty?
    {
        return nullptr;
    }
    // copying first node manually 
    Node* newHead = new Node(); //creating new head
    newHead->data = head->data; // copying first node manually
    newHead->next = nullptr; // making next node = nullptr

    //setting up two nodes to go through both lists
    Node* current = head->next; // this one for old 
    Node* newCurrent = newHead; // this one for new
    
    //copying the remaining data
    while (current != nullptr)
    {
        Node* temp = new Node();
        temp->data = current->data;
        temp->next = nullptr;

        newCurrent->next = temp;
        newCurrent = temp;
        current = current->next;
    }

    return newHead;
}

void freeMemory(Node* head)
{
    /*
This function deletes all nodes of a linked list and frees memory
It starts from the head and moves node by node.
For each node:
 store the current node in a temporary pointer
 move to the next node
 delete the temporary node

This continues until all nodes are deleted.
*/
    Node* current = head;
    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}
void insert(Node* head, const int& value, const int& pos)    // insert a Node of the given value at the given position
{
    /*
This function inserts a new node with given value at a specific position
It first creates a new node
If position is 0, it tries to insert at the beginning
Otherwise, it moves through the list to find the node
just before the required position
Then it links the new node into the list
If the position is invalid, the new node is deleted
*/
    // Create new node
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // Insert at position 0 (beginning)
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    int index = 0;

    // Traverse to the node just before the desired position
    while (current != nullptr && index < pos - 1)
    {
        current = current->next;
        index++;
    }

    // If position is valid
    if (current != nullptr)
    {
        newNode->next = current->next;
        current->next = newNode;
    }
    else
    {
        // If position is out of bounds
        delete newNode;
        cout << "ERROR: Position out of range"<<endl;
    }
}
int remove(Node* head, const int& pos)
{
    /*
This function removes a node at a given position and returns its value
If the list is empty it returns -1
If position is 0 it removes the first node
Otherwise it moves to the node just before the target position
It then unlinks the node, deletes it, and returns its value
If the position is invalid, it returns -1
*/
    // If list is empty
    if (head == nullptr)
        return -1;

    Node* current = head;

    // Remove first node
    if (pos == 0)
    {
        int value = current->data;
        head = current->next;
        delete current;
        return value;
    }

    int index = 0;

    // Move to node before the one to delete
    while (current->next != nullptr && index < pos - 1)
    {
        current = current->next;
        index++;
    }
    // If position is valid
    if (current->next != nullptr)
    {
        Node* temp = current->next;
        int value = temp->data;

        current->next = temp->next;
        delete temp;
        return value;
    }
    return -1;
}
int main() {

    Node* head = new Node{ 10, nullptr };
    head->next = new Node{ 20, nullptr };
    head->next->next = new Node{ 30, nullptr };

    cout << "Original list: ";
    display(head);
    cout << endl;
    Node* copiedList = copy(head);

    cout << "Copied list:   ";
    display(copiedList);

    cout << endl;
    insert(head, 2, 1);   // insert 15 at position 1
    
    cout << "After insert: ";
    display(head);
    cout << endl;
    int val2 = remove(head, 2);  // Remove middle node
    cout << "Removed value: " << val2 << endl;
    cout << endl << "After removal: ";
    display(head);

    freeMemory(head);
    freeMemory(copiedList);
	return 0;
}