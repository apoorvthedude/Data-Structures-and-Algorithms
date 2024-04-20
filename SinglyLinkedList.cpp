#include <iostream>
using namespace std;

// Linked List Data structure => Singly LL

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
            delete this->next;
            this->next = nullptr;
        }
        cout << "Memory is free for node with data: " << value << endl;
    }
};


// Time Complexity : O(1) & Space complexity : O(1) 
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
                head = newNode; // Point head to new Node (which is now the first node)
        }
}

// Time Complexity : O(n) & Space complexity : O(1)
void insertNodeAtEnd(Node* &head, int num) {
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

// Time Complexity : O(n) & Space complexity : O(1) 
void deleteNodeByPosition(Node* &head, int position){
    if (head == nullptr) { 
        cout << "Empty LinkedList" << endl;
        return;
    }

    if(position == 1){
        Node* temp = head;
        head = head -> next; // Update the head Pointer

        //Memory free the start Node
        temp -> next = nullptr;
        delete temp;
    }
    else{
        // Deletion Node at invalid position
        int length = getLinkedListLength(head);

        if (position > length + 1 || position <=0) {  // Check for invalid positions
            cout << "Invalid position. Cannot delete beyond the end.\n";
            return;
        } else if (position == length + 1 || position > 0) {  // Delete directly at the end
        // Delete Node present at any location other than end Node
        Node* currNode = head;
        Node* prevNode = nullptr;
        int count = 1;

        while(count < position){
            prevNode = currNode;
            currNode = currNode -> next;
            count++;
        }
        prevNode->next = currNode->next;
        
        // Memory free
        currNode->next = nullptr;
        delete currNode;
        }
    }
}

/*
void deleteNodeByValue(Node* &head, int num){
    Node* prevNode = nullptr;
    Node* currNode = head;
}
*/

// Time Complexity : O(n) & Space complexity : O(1) 
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

    cout <<"\n";
    if(head == nullptr){
        cout << "LinkedList is empty" << endl;
    }
    cout <<"\n";

    insertNodeAtHead(head,1);
    printLinkedList(head);
    cout << "HEAD : " << head->data << endl;
    cout << "LinkedList Length : "<< getLinkedListLength(head) << endl;
    cout <<"\n";

    insertNodeAtHead(head,0);
    printLinkedList(head);
    cout << "HEAD : " << head->data << endl;
    cout << "LinkedList Length : "<< getLinkedListLength(head) << endl;
    cout <<"\n";

    insertNodeAtPosition(head,3,3);
    printLinkedList(head);
    cout << "HEAD : " << head->data << endl;
    cout << "LinkedList Length : "<< getLinkedListLength(head) << endl;
    cout <<"\n";

    insertNodeAtPosition(head,3,2);
    printLinkedList(head);
    cout << "HEAD : " << head->data << endl;
    cout << "LinkedList Length : "<< getLinkedListLength(head) << endl;
    cout <<"\n";

    insertNodeAtPosition(head,5,4);
    printLinkedList(head);
    cout << "HEAD : " << head->data << endl;
    cout << "LinkedList Length : "<< getLinkedListLength(head) << endl;
    cout <<"\n";

    insertNodeAtPosition(head,1,-1);
    printLinkedList(head);
    cout << "HEAD : " << head->data << endl;
    cout << "LinkedList Length : "<< getLinkedListLength(head) << endl;
    cout <<"\n";

    deleteNodeByPosition(head,6);
    printLinkedList(head);
    cout << "LinkedList Length : "<< getLinkedListLength(head) << endl;
    cout <<"\n";
    
    return 0;
}
