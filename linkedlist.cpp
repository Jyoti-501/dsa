#include <iostream>
using namespace std;
class Node {
public:
int data;
Node* next;
Node(int val) : data(val), next(nullptr) {}
};
class SinglyLinkedList {
private:
Node* head;
public:
SinglyLinkedList() : head(nullptr) {}
void insertAtBeginning(int val) {
Node* newNode = new Node(val);
newNode->next = head;
head = newNode;
cout<<"Element inserted in beginning is: "<<val<<endl;
}
void insertAtEnd(int val) {
Node* newNode = new Node(val);
if (head == nullptr) {
head = newNode;
} else {
Node* temp = head;
while (temp->next != nullptr) {
temp = temp->next;
}
temp->next = newNode;
}
cout<<"Element inserted in end is: "<<val<<endl;
}
void deleteFromBeginning() {
if (head == nullptr) {
cout << "List is-* empty!" << endl;
return;
}
Node* temp = head;
head = head->next;
delete temp;
cout<<"deleting element from the beginning:"<<endl;
}
void deleteFromEnd() {
if (head == nullptr) {
cout << "List is empty!" << endl;
return;
}
if (head->next == nullptr) {
delete head;
head = nullptr;
} else {
Node* temp = head;
while (temp->next->next != nullptr) {
temp = temp->next;
}
delete temp->next;
temp->next = nullptr;
}
cout<<"deleting el-ement from the end:"<<endl;
}
void display() {
cout<<"Elements in linked list are:"<< endl;
Node* temp = head;
while (temp != nullptr) {
cout << temp->data << " ";
temp = temp->next;
}
cout<< endl;
}
};
int main() {
SinglyLinkedList list;
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
