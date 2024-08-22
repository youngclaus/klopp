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

// Statistically Option 2 is more efficient, while both options are more efficient than having one line and one counter

//The following array is used to select the more accurate piece of data between line 1 and 2 for display after day is over
//I was lazy and did not want to make fifteen new variables just to display text
//
//The problem is that I have Queue 1 and Queue 2 each with their own objects; waitTime, serviceTime, and inLineTime;
//    and these objects each have their own variables for keeping track of what is in the array
//    however, to display the data I have to compare each queue's variables against the other to find the true minimum for serviceTime, for example
//    This array is in lieu of making fifteen FINAL variables that are the true mins and maxes for the data output
//    It is not practical but it works so cheers
//
// 0-14: waitMin, waitMinTime, waitMax, waitMaxTime, waitAvg, serviceMin, serviceMinT, serviceMax, serviceMaxT, serviceAvg, inLineMin, inLineMinT, inLineMax, inLineMaxT
//    After writing this I realized it would have been less typing to make the fifteen variables rather than explaining myself

double arr[11];   // <-- Aforementioned Array
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
    minT = 1; //Times earlier in the day like at time 0 and 1 will always be the min, figured time of 1 was at least realistic as opposed to time 0
    max = 0;
    maxT = 0;
    avg = 0;
    total = 0;
  }
};

class Queue {
public:
  Customer* head;
  string title;
  Important waitTime, serviceTime, inLine;

  Queue() {
    head = NULL;
  }

  void fullCheck(Customer* head, Customer* temp) {
    //Min Max Wait Time
    if (individualWaitTime(head) < waitTime.min) {
      waitTime.min = individualWaitTime(head);
      waitTime.minT = storeClock;
      arr[0] = waitTime.min;
      arr[1] = waitTime.minT;
    }
    if (individualWaitTime(head) > waitTime.max) {
      waitTime.max = individualWaitTime(head);
      waitTime.maxT = storeClock;
      arr[2] = waitTime.max;
      arr[3] = waitTime.maxT;
    }

    //Min Max Service Time
    if (serviceTime.min == 0) {
      serviceTime.min = individualWaitTime(head) + temp->orderTime;
      serviceTime.minT = storeClock;
      arr[4] = serviceTime.min;
      arr[5] = serviceTime.minT;
    }
    else {
      if ((individualWaitTime(head) + temp->orderTime) < serviceTime.min) {
        serviceTime.min = individualWaitTime(head) + temp->orderTime;
        serviceTime.minT = storeClock;
        arr[4] = serviceTime.min;
        arr[5] = serviceTime.minT;
      }
      if ((individualWaitTime(head) + temp->orderTime) > serviceTime.max) {
        serviceTime.max = individualWaitTime(head) + temp->orderTime;
        serviceTime.maxT = storeClock;
        arr[6] = serviceTime.max;
        arr[7] = serviceTime.maxT;
      }
    }

    //Min Max Line Length
    if (numCustomersInLine(head) < inLine.min) {
      inLine.min = numCustomersInLine(head);
      inLine.minT = storeClock;
      arr[8] = inLine.min;
      arr[9] = inLine.minT;
    }
    if (numCustomersInLine(head) > inLine.max) {
      inLine.max = numCustomersInLine(head);
      inLine.maxT = storeClock;
      arr[10] = inLine.max;
      arr[11] = inLine.maxT;
    }
  }

  void enqueue(string title) {
    Customer* temp = new Customer();
    waitTime.total += individualWaitTime(head);
    serviceTime.total += (individualWaitTime(head) + temp->orderTime);
    cout << "service total: " << serviceTime.total << endl;
    fullCheck(head, temp);

    cout << "--> Added Customer " << temp->in << " to " << title << " at [" << temp->in << "] mins with an order time of [" << temp->orderTime << "] mins,\n    and a line wait of [" << individualWaitTime(head) << "] mins.\n";

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
  Queue store2;
  store.title = "Line 1";
  store2.title = "Line 2";

  int numCustomer = 0;
  int queueLength = 0;
  const int maxClockTime = 1020;  //Max time is 1020 for full work day; Use 10 or 20 for testing
  int randNum;
  int randProb;

  while (storeClock < maxClockTime) {   //Open 17 hours after 8 am
    cout << "\n";
    storeClock++;
    randProb = getProb(storeClock);
    store.inLine.total += store.numCustomersInLine(store.head);     // Add up all line lengths from every minute for average calculation
    store2.inLine.total += store2.numCustomersInLine(store2.head);   // Same thing for store 2

    //Part 1: new customer
    randNum = rand() % 100 + 1;
    if (randNum <= randProb) {
      cout << "At " << storeClock << " a new customer arrived.\n";
      numCustomer++;
      if (store.numCustomersInLine(store.head) <= store2.numCustomersInLine(store2.head)) {
        store.enqueue(store.title);
      }
      else {
        store2.enqueue(store2.title);
      }
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
    if (store2.head != NULL) {
      if (store2.head->orderTime == 0) {
        cout << "--> Customer " << store2.head->in << " left.\n";
        store2.dequeue();
      }
      else {
        store2.head->orderTime--;
      }
    }

  } // end while

  //Part 3: Stats
  cout << "\n-------------------------------------------------------------------------------------------\n";
  double a = store.avg(store.waitTime.total, numCustomer);
  double b = store.avg(store.serviceTime.total, numCustomer);
  double c = store.avg(store.inLine.total, maxClockTime);
  double a2 = store2.avg(store2.waitTime.total, numCustomer);
  double b2 = store2.avg(store2.serviceTime.total, numCustomer);
  double c2 = store2.avg(store2.inLine.total, maxClockTime);

  cout << "Shortest Wait Time:     " << arr[0] << " mins at time " << arr[1] << " mins\n";
  cout << "Longest Wait Time:      ";
  hr(arr[2]);
  cout << " at time ";
  hr(arr[3]);
  cout << "\nAvg Wait Time:          ";
  hr((a + a2) / 2);
  cout << " \n\n";

  cout << "Shortest Service Time:  " << arr[4] << " mins at time ";
  hr(arr[5]);
  cout << "\n";
  cout << "Longest Service Time:   ";
  hr(arr[6]);
  cout << " at time ";
  hr(arr[7]);
  cout << "\nAvg Service Time:       ";
  hr((b + b2) / 2);
  cout << " \n\n";

  cout << "Least people in line:   " << arr[8] << " people at time " << arr[9] << " mins\n";
  cout << "Most people in line:    " << arr[10] << " people at time ";
  hr(arr[11]);
  cout << " mins\n";
  if (c < 1) {
    cout << "Avg peeps in Line 1:    Less than 1 person [" << c << "]\n";
    cout << "Avg peeps in Line 2:    Less than 1 person [" << c2 << "]";
  }
  else {
    cout << "Avg peeps in Line 1:    " << int(c) << " people\n";
    cout << "Avg peeps in Line 2:    " << int(c2) << " people";
  }
  cout << "\n-------------------------------------------------------------------------------------------\n";

}