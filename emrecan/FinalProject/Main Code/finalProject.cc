#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//---------------------------------------------------------------------
//  Liamjohn Velazquez and Chris Youngclaus
//  CPE 360 - Prof. Iyengar
//  17 May 2021
//  We pledge our honor that we have abided by the Stevens Honor Code
//---------------------------------------------------------------------

int storeClock = 0;

class Customer {
public:
  int in, out, wait, orderTime;
  Customer* next;

  Customer() {
    in = storeClock;
    out = 0;
    wait = 0;
    orderTime = rand() % 6 + 1;
    next = NULL;
  }
};

class Important {
public:
  double min, minT, max, maxT, avg, total;

  Important() {
    min = 0;
    minT = 0;
    max = 0;
    maxT = 0;
    avg = 0;
    total = 0;
  }
};

class Queue {
public:
  Customer* head;

  Important waitTime, serviceTime, inLine;

  Queue() {
    head = NULL;
  }

  void fullCheck(Customer* head, Customer* temp) {
    //Min Max Wait Time
    if (time == 0) {
      return;
    }
    if (individualWaitTime(head) < waitTime.min) {
      waitTime.min = individualWaitTime(head);
      waitTime.minT = storeClock;
    }
    if (individualWaitTime(head) > waitTime.max) {
      waitTime.max = individualWaitTime(head);
      waitTime.maxT = storeClock;
    }

    //Min Max Service Time
    if (serviceTime.min == 0) {
      serviceTime.min = individualWaitTime(head) + temp->orderTime;
      serviceTime.minT = storeClock;
    }
    else {
      if ((individualWaitTime(head) + temp->orderTime) <= serviceTime.min) {
        serviceTime.min = individualWaitTime(head) + temp->orderTime;
        serviceTime.minT = storeClock;
      }
      if ((individualWaitTime(head) + temp->orderTime) > serviceTime.max) {
        serviceTime.max = individualWaitTime(head) + temp->orderTime;
        serviceTime.maxT = storeClock;
      }
    }

    //Min Max Line Length
    if (numCustomersInLine(head) < inLine.min) {
      inLine.min = numCustomersInLine(head);
      inLine.minT = storeClock;
    }
    if (numCustomersInLine(head) > inLine.max) {
      inLine.max = numCustomersInLine(head);
      inLine.maxT = storeClock;
    }
  }

  void enqueue() {
    Customer* temp = new Customer();
    waitTime.total += individualWaitTime(head);
    serviceTime.total += (individualWaitTime(head) + temp->orderTime);
    fullCheck(head, temp);

    cout << "--> Added Customer " << temp->in << " to line at [" << temp->in << "] mins with an order time of [" << temp->orderTime << "] mins,\n    and a line wait of [" << individualWaitTime(head) << "] mins.\n";

    if (head == NULL) {
      head = temp;
    }
    else {
      Customer* another;
      another = head; // start from beginning
      while (another->next != NULL) {
        another = another->next;
      }

      //end of line
      another->next = temp;
      temp->next = NULL;
    }
  }

  void dequeue() {
    if (head == NULL) {
      cout << "Line empty" << endl;
    }
    else {
      Customer* temp;
      temp = head;
      head = head->next;
      delete temp;
    }
  }

  int numCustomersInLine(Customer* head) {
    if (head == NULL) {
      return 0;
    }
    else {
      int counter = numCustomersInLine(head->next);
      return (counter + 1);
    }
  }

  double avg(int total, int customers) {
    double dif = (double)total / (double)customers;
    return (dif);
  }

  int individualWaitTime(Customer* head) {
    int sum = 0;
    if (head == NULL) {                   //Check if nobody's there just in case
      return 0;
    }
    else {
      int sum = individualWaitTime(head->next);
      return sum += head->orderTime;
    }
  }
};

int getProb(int time) {
  if (time <= 120) {
    return 30;
  }
  else if (time <= 210) {
    return 10;
  }
  else if (time <= 330) {
    return 40;
  }
  else if (time <= 570) {
    return 10;
  }
  else if (time <= 780) {
    return 25;
  }
  else if (time <= 960) {
    return 20;
  }
  else if (time <= 1080) {
    return 10;
  }
  else {
    cout << "Error\n";
  }
  return 1;
}

void hr(double time) {
  int hours, minutes, seconds;

  if (time > 60) {
    hours = int(time / 60);
    minutes = int(time) - (hours * 60);
    cout << hours << " hours and " << minutes << " minutes";
  }
  else {
    minutes = int(time);
    seconds = (time - double(minutes)) * 60;
    cout << minutes << " minutes and " << seconds << " seconds";
  }
}

int main() {
  srand(time(NULL));
  Queue store;

  int numCustomer = 0;
  int queueLength = 0;
  const int maxClockTime = 1020;  //Max time is 1020 for full work day; Use 10 or 20 for testing
  int randNum;
  int randProb;

  while (storeClock < maxClockTime) {   //Open 17 hours after 8 am
    cout << "\n";
    storeClock++;
    randProb = getProb(storeClock);
    store.inLine.total += store.numCustomersInLine(store.head);

    //Part 1: new customer
    randNum = rand() % 100 + 1;
    if (randNum <= randProb) {
      cout << "At " << storeClock << " a new customer arrived.\n";
      numCustomer++;
      store.enqueue();
    }
    else {
      cout << "At " << storeClock << " nobody came in.\n";
    }

    //Part 2: customer departing
    if (store.head != NULL) {
      if (store.head->orderTime == 0) {
        cout << "--> Customer " << store.head->in << " left.\n";
        store.dequeue();
      }
      else {
        store.head->orderTime--;
      }
    }

  }

  cout << "\n-------------------------------------------------------------------------------------------\n";
  double a = store.avg(store.waitTime.total, numCustomer);
  double b = store.avg(store.serviceTime.total, numCustomer);
  double c = store.avg(store.inLine.total, maxClockTime);

  cout << "Shortest Wait Time:     " << store.waitTime.min << " mins at time " << store.waitTime.minT << " mins\n";
  cout << "Longest Wait Time:      ";
  hr(store.waitTime.max);
  cout << " at time ";
  hr(store.waitTime.maxT);
  cout << "\nAvg Wait Time:          ";
  hr(a);
  cout << " \n\n";

  cout << "Shortest Service Time:  " << store.serviceTime.min << " mins at time ";
  hr(store.serviceTime.minT);
  cout << "\n";
  cout << "Longest Service Time:   ";
  hr(store.serviceTime.max);
  cout << " at time ";
  hr(store.serviceTime.maxT);
  cout << "\nAvg Service Time:       ";
  hr(b);
  cout << " \n\n";

  cout << "Least people in line:   " << store.inLine.min << " people at time " << store.inLine.minT << " mins\n";
  cout << "Most people in line:    " << store.inLine.max << " people at time ";
  hr(store.inLine.maxT);
  cout << " mins\n";  cout << "Avg Peeps in Line:      " << int(c) << " people";
  cout << "\n-------------------------------------------------------------------------------------------\n";

}