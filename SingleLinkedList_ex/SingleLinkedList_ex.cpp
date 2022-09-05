// SingleLinkedList_ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


///
///Linked lists are expensive as far as their traversal is concerned since we cannot randomly access the elements like arrays.
/// However, insertion - deletion operations are less expensive when compared arrays.
///
#include <iostream>

template <class T>
class Node {
public:
    T data;        // data to save, can be any data type
    Node* next;  // pointer to the next node 
    Node<T>() {
        next = NULL;
    };
};

//public class inherits from Node 
template <class T>
class SingleLinkedList : public Node<T>{

private:
    bool firstTimeFlag;
public:
    Node<T>* head; // head is the begining of the LinkedList 
    Node<T>* tail; // tail is the end 

    SingleLinkedList<T>() {
        firstTimeFlag = false;
        head = new Node<T>();
        tail = new Node<T>();
        head = tail;  // at start of the link list head and tail pointing to each other or to Null 
    }
    void add(T data) {
        Node<T>* newNode = new Node<T>;  // create a node in heap 
        newNode->data = data;  
        newNode->next = NULL;  // last node always point to NULL 
        tail->next = newNode;  // last pointer now points to the new node 
        tail = newNode; // tail is now the new node 
        if (firstTimeFlag == false) {
            head = newNode;
            tail = newNode;     
            firstTimeFlag = true;     
        }
    }

    void printData() {
        Node<T>* p = head;   // create pointer that points to head 
        // loop through until it gets to NULL
        while (p != NULL) {
            std::cout << p->data << " " << std::endl;
            p = p->next; //p keep going forward to the next node 
        }
    }

    void  insertAt(int index, T data) {
        Node<T>* p = head;
        int i = 0;
        // if we dont reach end and until the we rich the point keep going forward 
        while (p->next != NULL && i < index - 1) {
            p = p->next;
            i++;
        }

        Node<T>* ANewNode = new Node<T>();
        ANewNode->data = data;
        ANewNode->next = p->next;  // new node next pointer is pointing where the P was pointing 
        p->next = ANewNode;   // now P pointer points to new node 
    }

    void  RemoveAt(int index) {
        Node<T>* p = head;
        int i = 0;
        while (p->next != NULL && i < index - 1) {
            p = p->next;
            i++;
        }

        Node<T>* tempNode = p->next;
        p->next = p->next->next;   // because we deleted a node , we have to go two pointers forward. 
        tempNode->next = NULL;
        delete tempNode;
    }

};

int main()
{  
    SingleLinkedList<std::string>* Slink = new SingleLinkedList<std::string>();
    Slink->add("Rose");
    Slink->add("Jack");
    Slink->add("Yahoo");
    Slink->insertAt(4, "Bob");
    Slink->printData();
    Slink->RemoveAt(1);
    Slink->printData();
 
}

