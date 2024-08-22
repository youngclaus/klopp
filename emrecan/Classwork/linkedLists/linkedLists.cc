#include <iostream>
using namespace std;

class Chunk {
public:
  int info;
  Chunk* next;

  Chunk() {
    info = 0;
    next = NULL;
  }
};

class LinkedList {
public:
  Chunk* head;
  int count;

  LinkedList() {
    head = NULL;
    count = 0;
  }

  // 1 Add at head
  void atHead(int value) {
    Chunk* temp;
    temp = new Chunk;
    temp->info = value;

    temp->next = head;  // get new chunk to point to current 1st
    head = temp;
    count++;
    cout << "Added " << value << " at position 1." << endl;
  }

  // 2 ADD: insert at position
  void insertAtPos(int value, int pos) {
    if (pos > 0 && pos <= count + 1) {
      Chunk* temp;
      temp = new Chunk;
      temp->info = value;
      if (pos == 1) {
        temp->next = head;  // get new chunk to point to current 1st
        head = temp;
        count++;
        cout << "Added " << value << " at position 1." << endl;
      }
      else {
        Chunk* helper = head;
        for (int i = 1; i <= pos - 2; i++) {
          cout << helper->info << endl;
          helper = helper->next;
        }
        temp->next = helper->next;
        helper->next = temp;
        count++;
        cout << "Added " << value << " at position " << pos << endl;
      }
    }
  }

  // 3 REMOVE: delete from a position
  void removeFromPosition(int position) {
    if (position > 0 && position <= count) {
      if (position == 1) {
        if (count == 1) {
          delete head;
          head = NULL;
        }
        else {
          Chunk* temp = head;
          head = head->next;
          delete temp;
        }
      }
      else if (position > 1 && position <= count) {
        Chunk* follow;
        Chunk* temp;
        follow = temp = head;
        for (int i = 1; i <= position - 1; i++) {
          temp = follow;
          temp = temp->next;
        }
        follow->next = temp->next;
        delete temp;
      }
      count--;
    }
    else {
      cout << "Can't delete" << endl;
    }

    /*       CODE FROM CLASS
    if (head == NULL) {
      cout << "Empty list, nothing to remove" << endl;
      return;
    }
    if (position > 0 && position <= count) {
      if (position == 1) {
        Chunk* temp;
        temp = head;
        head = head->next;
        cout << "about to delete: " << temp->info << endl;
        delete temp;
        count--;
      }
      else {
        Chunk* chase;
        Chunk* follow;
        chase = follow = head;
        for (int i = 1; i < position; i++) {
          follow = chase;
          chase = chase->next;
        }
      }
    }
*/
  }

  // 4 Display stuff
  void display() {
    Chunk* temp;
    temp = head;
    while (temp != NULL) {
      cout << temp->info << " ---> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main() {
  LinkedList LL;
  int value, position, choice;
  LL.insertAtPos(15, 1);
  LL.insertAtPos(9, 1);
  LL.insertAtPos(7, 1);
  LL.insertAtPos(5, 1);

  while (1) {
    cout << "1 to add at head" << endl;
    cout << "2 to add at position" << endl;
    cout << "3 to delete" << endl;
    cout << "4 to display" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Add what?" << endl;
      cin >> value;
      LL.atHead(value);
      break;
    case 2:
      cout << "Add what?" << endl;
      cin >> value;
      cout << "At what position?" << endl;
      cin >> position;
      LL.insertAtPos(value, position);
      break;
    case 3:
      cout << "Remove from what position?" << endl;
      cin >> position;
      LL.removeFromPosition(position);
      break;
    case 4:
      LL.display();
      break;
    }
  }
}