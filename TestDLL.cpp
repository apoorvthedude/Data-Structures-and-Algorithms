#include<iostream>
using namespace std;

// Write code for Linked List data structure
    // Doubly Linked List

    // Insertion and Deletion
        // -> At head/start
        // -> At any position
        // -> At tail/end

    // Searching or Traversing (Done)
    // Length of LinkedList (Done)

    class Node{
        public:
            int data;
            Node* prev;
            Node* next;

        // Constructor
        Node(int num){
            this->data = num;
            this->prev = nullptr;
            this->next = nullptr;
        }
        // Destructor
        ~Node(){
            int value = this->data;
            
            if(this->next!=nullptr){
                delete next;
                this->next = nullptr;
            }
            cout << "Memory is free for node with data: " << value << endl;
        }
    };

    // Insertion of Node at the beginning
        // T.C : O(1) & S.C : O(1)
    void insertAtBeginning(Node* &head,int num){
        if(head == nullptr){
            Node* newNode = new Node(num);
            head = newNode;
        }
        else{
            // Create a new Node
            Node* newNode = new Node(num);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // To get the length of the linkedlist
        // Time complexity : O(n) & Space complexity : O(1)
    int getLinkedListLength(Node* &head){
        int len = 0;
        Node* temp = head;

        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    void insertAtPosition(Node* &head, int position, int num){
        if(position == 1){
            insertAtBeginning(head,num);
            return;
        }

        // Create prev Node pointer which is equal to head
        Node* prev = head;
        int count = 1; 
        while(count < position - 1 && prev !=nullptr){
            prev = prev -> next;
            count ++;
        }
        
        // Create a new Node
        Node* newNode = new Node(num);
        newNode->next = prev->next;
        prev->next->prev = newNode;
        prev->next = newNode;
        newNode->prev = prev;
    }

    // Deletion of Node in LinkedList by Position
    void deleteNodeByPosition(Node* &head, int position){
        if(head == nullptr){
        cout << "Empty LinkedList" << endl;
        return;
        }

        if(position==1){
            Node* temp = head;

            // Memory free start node
            temp->next->prev = nullptr;
            head = temp->next;
            temp->next = nullptr;
            delete temp;
        }
        else{
        // deletion from middle
        int count = 1;
        Node* curr = head;
        Node* prev = nullptr;

        while(count < position && curr !=nullptr){
            prev = curr;
            curr = curr -> next;
            count++;
        }

        curr -> prev = nullptr;
        prev->next = curr->next;
        // Memory free the node
        curr->next = nullptr;
        delete curr;
        }
    }

    //void deleteNodeByValue(Node* &head, int num){}

    // Print LinkedList
        // Time complexity to print: O(n) & Space complexity : 0(1)
    void printLinkedList(Node* &head){
        // Create a temp node pointing to head
        Node* temp = head;
        cout << "NULL";
        while(temp!=nullptr){
            cout << "<-" << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

int main(){
    Node* node1 = new Node(2);
    Node* head = node1;
    insertAtBeginning(head,1);
    printLinkedList(head);
    cout << getLinkedListLength(head) <<endl;
    return 0;
}