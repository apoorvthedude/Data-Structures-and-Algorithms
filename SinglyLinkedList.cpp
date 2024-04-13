#include <iostream>
using namespace std;

// Linked List Data structure => Singly LL

/*
    Operations performed on LL or any data structure
        1) Insertion
        2) Search by value or position and traversal
        3) Deletion

    Mention Time & Space Complexity of each operation
*/

class Node{
    public:
        int data;
        Node* next;

    //Constructor
    Node(int num){
        this->data = num;
        this->next = nullptr;
    }
    
    // Destructor
    ~Node(){
        int value = data;
        if(this->next!=nullptr) {
            delete next;
            this->next = nullptr;
        }
        cout << "Memory is free for node with data: " << value << endl;
    }
};


// Time Complexity : O(1) & Space complexity : 
void insertNodeAtHead(Node* &head, int num) {
        // No Node present [Empty Linked List]
        if(head == nullptr){
            // Create new Node
            Node* newNode = new Node(num);
            head = newNode; // Point head to first node
        }
        else{
            // Insert Node at Head/beginning
                // 1) Create new Node
                Node* newNode = new Node(num);
                newNode-> next = head; // Point next pointer to head
                head = newNode; // Point head to new Node (which is new first node)
        }
}

void insertNodeAtEnd(Node* &head, int num){
    // Insert node at end or last
    Node* newNode = new Node(num); // Create a new Node
    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* last = head;
    while(last->next!=nullptr){
        last = last->next;
    }
    last->next = newNode;
    last = newNode;
}

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
    if(position == 1){
        insertNodeAtHead(head,num);
        return;
    }
    else{
        // Insertion of Node at End
        int length = getLinkedListLength(head);
        if (position > length + 1 || position <=0) {  // Check for invalid positions
            cout << "Invalid position. Cannot insert beyond the end.\n";
            return;
        } else if (position == length + 1) {  // Insert directly at the end
            insertNodeAtEnd(head, num);
            return;
        }

        // Insertion of Node at middle
        Node* prevNode = head;
        int count = 1;
        
        while(count < position-1){
            prevNode = prevNode->next;
            count++;
        }

        // Create new Node
        Node* newNode = new Node(num);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }
}

void deleteNodeByPosition(Node* head, int position){
    if (head == nullptr) { 
        cout << "Empty LinkedList" << endl;
        return;
    }

    if(position == 1){
        Node* temp = head;
        head = head -> next; // Update the head pointer

        //Memory free the start Node
        temp -> next = nullptr;
        delete temp;
    }
    else{
        cout << "-----------------";
    }
}

void printLinkedList(Node* &head){
    Node* temp = head;
    
    while(temp!=nullptr){
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main(){
    Node* node1 = nullptr;
    Node* head = node1;

    insertNodeAtHead(head,1);

    insertNodeAtHead(head,0);
    cout << "Length of the LinkedList is : " << getLinkedListLength(head) << endl;

    insertNodeAtPosition(head,3,3);
    cout << "Head : " << head->data << endl;

    insertNodeAtPosition(head,3,2);
    cout << "Length of the LinkedList is : "<< getLinkedListLength(head) << endl;

    insertNodeAtPosition(head,5,4);
    insertNodeAtPosition(head,1,-1);

    deleteNodeByPosition(head,1);
    printLinkedList(head);
    return 0;
}