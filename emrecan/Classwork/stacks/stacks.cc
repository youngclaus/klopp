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
class Stack {
public:
  Chunk* top;
  Stack() {
    top = NULL;
  }

  void push(int x) {
    Chunk* temp = new Chunk;
    temp->value = x;
    if (top == NULL) {
      top = temp;
    }
    else {
      temp->next = top;
      top = temp;
    }
    cout << "Added: " << x << " to stack" << endl;
  }

  void pop() {
    if (top == NULL) {
      cout << "Empty" << endl;
    }
    else {
      Chunk* temp = new Chunk;
      temp = top;
      top = top->next;
      cout << "Deleting " << temp->value << endl;
      delete temp;
    }
  }

  void displayContents() {
    Chunk* temp = top;
    while (temp != NULL) {
      cout << temp->value << "-->";
      temp = temp->next;
    }
    cout << "Empty" << endl;
  }
};

int main() {
  Stack myStack;
  int choice, x;
  while (1) {
    cout << "1 to add to stack " << endl;
    cout << "2 to remove from stack " << endl;
    cout << "3 to display stack " << endl;
    cout << "Anything else to quit " << endl;
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Add what?" << endl;
      cin >> x;
      myStack.push(x);
      break;
    case 2:
      myStack.pop();
      break;
    case 3:
      myStack.displayContents();
      break;
    default:
      cout << "cya freshman" << endl;
      exit(1);
    }
  }
  return 1;
}