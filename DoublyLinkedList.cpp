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

// Time Complexity: O(1)   & Space complexity :  O(1)             
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

// Time Complexity : O(n) & Space complexity : O(1)
void insertNodeAtPosition (Node* &head, int position, int num){
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

// Time Complexity : O(n) & Space complexity : O(1) 
void deleteNodeByPosition(Node* &head,int position){
    if(head == nullptr){
        cout << "Empty Linked List, Can't delete Node" << endl;
        return;
    }
    else if(position==1 && head->next != nullptr){
        Node* temp = head;
        head = temp->next;
        temp->next = nullptr;
        head->prev = nullptr;
        delete temp;
    }
    else if(position==1 && head->next == nullptr && head->prev == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    else{
        // Delete Middle Node
        Node* prevNode = nullptr;
        Node* currNode = head;

        int count = 1;
        int length = getLinkedListLength(head);

        while(count < position && position <= length){
            prevNode = currNode;
            currNode = currNode->next;
            count ++;
        }

        // Deletion of Last Node at Last
        if (position >= length + 1 || position <=0) {  // Check for invalid positions
            cout << "Invalid position. Cannot Delete beyond the end.\n";
            return;
        } else if (position == length) {  // Delete Last Node
            prevNode->next = currNode->next;
            currNode->prev = nullptr;
            delete currNode;
        }
        else{
            prevNode->next = currNode->next;
            currNode->next->prev = prevNode;
            currNode->next = nullptr;
            currNode->prev = nullptr;
            delete currNode;
        }
    }
}

// Time Complexity : O(n) & Space complexity : O(1) 
void printLinkedList(Node* &head){
    Node* temp = head;
    if(head == nullptr){
        cout << "Empty Linked List" << endl;
        return;
    }
    cout << "NULL";
    while(temp!=nullptr){
        cout << "<---" << temp->data << "--->";
        temp = temp->next; 
    }
    cout << "NULL\n";
}

int main(){
    Node* node1 = nullptr;
    Node* head = node1;

    insertNodeAtHead(head,4);
    cout << "Linked List Length: " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    cout << "\n";

    insertNodeAtPosition(head,2,6);
    cout << "Linked List Length: " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    cout << "\n";

    insertNodeAtPosition(head,1,2);
    cout << "Linked List Length: " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    cout << "\n";

    insertNodeAtPosition(head,4,8);
    cout << "Linked List Length: " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    cout << "\n";

    insertNodeAtPosition(head,6,2); // Invalid position
    cout << "\n";

    deleteNodeByPosition(head,1);
    cout << "Linked List Length: " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    cout << "HEAD: " << head->data << endl;
    cout << "\n";

    deleteNodeByPosition(head,2);
    cout << "Linked List Length: " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    cout << "\n";

    deleteNodeByPosition(head,2);
    cout << "Linked List Length: " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    cout << "\n";

    deleteNodeByPosition(head,2); // Invalid Position
    cout << "\n";

    deleteNodeByPosition(head,1);
    cout << "Linked List Length: " << getLinkedListLength(head) << endl;
    printLinkedList(head);
    cout << "\n";
    return 0;
}
