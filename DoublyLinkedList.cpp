#include <iostream>
using namespace std;

// Linked List Data structure => Doubly LinkedList

/*
    Operations performed on LL or any data structure
        1) Insertion -> At start & At middle & At the end
        2) Search by value or position and traversal
        3) Deletion -> At start & (middle & in the end)/ At any other position

    Mention Time & Space Complexity of each operation
*/

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    //Constructor
    Node(int num) {
        this->data = num;
        this->prev = nullptr;
        this->next = nullptr;
    }

    // Destructor
    ~Node(){
        int value = data;

        if(this->next!=nullptr){
            delete next;
            this->next = nullptr;
            //this->prev = nullptr;
        }
        cout << "Memory is free for node with data: " << value << endl; 
    }
};

// Time Complexity:    & Space complexity :               
void insertNodeAtHead(Node* &head,int num){
    // If Linked List is empty || No Node present || head == nullptr
        if(head == nullptr){
            Node* newNode = new Node(num); //Create a newNode
            head = newNode;
        }
        else{
            Node* newNode = new Node(num); //Create a newNode
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
}

// Time Complexity : O(n) & Space complexity : O(1) 
int getLinkedListLength(Node* &head){
    Node* temp = head;
    int len = 0;

    while(temp!=nullptr){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertNodeAtPosition(Node* &head,int position,int num){
    // If insert at Head || position == 1
    if(position == 1){
        insertNodeAtHead(head,num);
        return;
    }
    else{
        Node* prevNode = head;
        int count = 1;

        while(count < position-1){
            prevNode = prevNode->next;
            count ++;
        }

        // Insert Node at Last
        int length = getLinkedListLength(head);
        
        if (position > length + 1 || position <=0) {  // Check for invalid positions
            cout << "Invalid position. Cannot insert beyond the end.\n";
            return;
        } else if (position == length + 1) {  // Insert directly at the end
            Node* newNode = new Node(num); // Create newNode
            prevNode->next = newNode;
            newNode->prev = prevNode;
        }
        else{// Insert Node in the Middle
            Node* newNode = new Node(num); // Create newNode
            newNode->next = prevNode->next;
            prevNode->next->prev = newNode;
            prevNode->next = newNode;
            newNode->prev = prevNode;
        }
    }
}

void deleteNodeByPosition(Node* &head,int position){
    if(head == nullptr)
        cout << "Empty Linked List, Can't delete Node" << endl;
    else if(position==1){
        Node* temp = head;
        head = temp->next;
        temp->next = nullptr;
        head->prev = nullptr;
        delete temp;
    }
    else{
        // Delete Middle Node
    }
}

void printLinkedList(Node* &head){
    Node* temp = head;

    cout << "NULL";
    while(temp!=nullptr){
        cout << "<---" << temp->data << "--->";
        temp = temp->next; 
    }
    cout << "NULL\n";
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;

    //cout << node1->data << "\n" << node1->prev << "\n" << node1->next << endl;
    insertNodeAtHead(head,5);
    cout << "Head : "<< head->data << endl;
    insertNodeAtPosition(head,2,6);
    insertNodeAtPosition(head,4,12);
    insertNodeAtPosition(head,5,14);
    cout << "LinkedList Length " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    deleteNodeByPosition(head,1);
    cout << "Head : "<< head->data << endl;
    cout << "LinkedList Length "<<getLinkedListLength(head) << endl;
    printLinkedList(head);
    return 0;
}