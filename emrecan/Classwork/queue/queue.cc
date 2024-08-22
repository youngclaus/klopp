#include <iostream>
using namespace std;

class Chunk {
public:
  int value;
  Chunk* next;
  Chunk() {
    value = 0;
    next = NULL;
  }
};

class Queue {
public:
  Chunk* head;
  Queue() {
    head = NULL;
  }

  void enqueue(int x) {
    Chunk* temp;
    temp = new Chunk;
    temp->value = x;
    if (head == NULL) {
      head = temp;
    }
    else {
      Chunk* more;
      more = head;
      while (more->next != NULL) {
        more = more->next;
      }
      more->next = temp;
      temp->next = NULL;
      cout << "Just added: " << x << endl;
    }
  }

  void dequeue() {
    if (head == NULL) {
      cout << "Empty qeueue" << endl;
    }
    else {
      Chunk* temp;
      temp = head;
      head = head->next;
      cout << "About to delete: " << temp->value << endl;
      delete temp;
    }
  }

  void displayContents() {
    Chunk* temp;
    temp = head;
    while (temp != NULL) {
      cout << temp->value << "->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};



int main() {
  Queue Q;
  int choice, var;
  while (1) {
    cout << "1 for enqueue" << endl;
    cout << "2 for dequeue" << endl;
    cout << "3 for display" << endl;
    cout << "Anything else to quit" << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Add what?" << endl;
      cin >> var;
      Q.enqueue(var);
      break;
    case 2:
      Q.dequeue();
      break;
    case 3:
      Q.displayContents();
      break;
    default:
      cout << "peace fam" << endl;
      exit(1);
    }
  }
}