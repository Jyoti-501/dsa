#include <iostream>
using namespace std;
class Node {
public:
int data;
Node* next;
Node* prev;
Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyCircularLinkedList {
private:
Node* head;
public:
DoublyCircularLinkedList() : head(nullptr) {}
void insertAtBeginning(int val) {

Node* newNode = new Node(val);
if (head == nullptr) {
head = newNode;
head->next = head;
head->prev= head;
} else {
Node* tail = head->prev;
newNode->next = head;
newNode->prev = tail;
head->prev = newNode;
tail->next = newNode;
head = newNode;
}
cout<<"Element inserted in beginning is: "<<val<<endl;
}
void insertAtEnd(int val) {
Node* newNode = new Node(val);
if (head == nullptr) {
head = newNode;
head->next = head;
head->prev= head;
} else {
Node* tail = head->prev;
newNode->next = head;
newNode->prev = tail;
tail->next = newNode;
head->prev = newNode;
}
cout<<"Element inserted in end is: "<<val<<endl;
}
void deleteFromBeginning() {
if (head == nullptr) {
cout << "List is empty!" << endl;
return;
}
if (head->next == head) {
delete head;
head = nullptr;
} else {
Node* tail = head->prev;
Node* temp = head;
head = head->next;
head->prev = tail;
tail->next = head;
delete temp;
}
cout<<"deleting element from the beginning:"<<endl;
}
void deleteFromEnd() {
if (head == nullptr) {
cout << "List is empty!" << endl;
return;
}
if (head->next == head) {
delete head;
head = nullptr;
} else {
Node* tail = head->prev;
Node* temp = tail;
head->prev = tail->prev;
tail->prev->next = head;
delete temp;
}
cout<<"deleting element from the end:"<<endl;
}
void display() {
cout<<"Elements in linked list are:"<< endl;
if (head == nullptr) {
cout << "List is empty!" << endl;
return;
}
Node* temp = head;
do {
cout << temp->data << " ";
temp = temp->next;
} while (temp != head);
cout << endl;
}
};
int main() {
DoublyCircularLinkedList list;
list.insertAtBeginning(2);
list.insertAtBeginning(1);
list.insertAtEnd(3);
list.insertAtEnd(4);
list.display();
list.deleteFromBeginning();
list.display();
list.deleteFromEnd();
list.display();
}
