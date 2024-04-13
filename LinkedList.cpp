#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    // Constructor
    Node(int num){
        this->data = num;
        this->next = NULL;
    }

    ~Node(){
        int num = this->data;
        if()
    }
};

    void insertAtHead(Node* &head, int num){
        //Create new Node
        Node* temp = new Node(num);
        temp->next = head;
        head = temp;
    }

    void insertAtTail(Node* &tail, int num){
        //Create new Node
        Node* temp = new Node(num);
        tail->next = temp;
        tail = temp;
    }

    void printLinkedList(Node* &head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAtPosition(Node* &tail,Node* &head,int position, int num){
        if(position == 1){
            insertAtHead(head,num);
            return;
        }

        Node* temp = head;
        int count = 1;
        while(count < position-1){
            temp = temp->next;
            count++;
        }

        // Insertion at Last position
        if(temp->next == NULL){
            insertAtTail(tail,num);
            return;
        }

        // Create a new Node
        Node* nodeToInsert = new Node(num);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;

    }

    void deleteNodeByPosition(Node* &head, int position){
        // First Node
        if(position == 1){
            Node* temp = head;
            head = head->next;
            // Free memory
            delete temp;

        }
        else{

        }
    }

    void deleteNodeByValue(Node* &head, int num){

    }

    int getLinkedListLength(Node* &head){
        int len = 0;
        Node* temp = head;
        while(temp !=NULL){
            len++;
            temp = temp -> next;
        }
    return len;
    }

int main(){
    // Create a new Node
    Node* node1 = new Node(34);
    
    // head pointed to first node
    Node* head = node1;
    // tail pointed to first node
    Node* tail = node1;
    printLinkedList(head);

    //insertAtHead
    insertAtHead(head,12);
    printLinkedList(head);

    cout << "Length of the Linked List :  " << getLinkedListLength(head) << endl;
    return 0;
}