#include "LinkedList.hpp"

int main(int argc, char * argv[]) {

  LinkedList LL(argv[1]);
  int choice = -1;
  int count = 0;
  int at = 0;
  
  
  cout << "How many employees will you be adding: ";
  cin  >> count;
  cout << "Enter employee information when prompted." << endl << endl;
 
  for (int i = 0; i < count;i++) {
    LL.push_back();
  }

  cout << endl << endl << " DATABASE MENU " << endl;
  cout << "[1] View the current database " << endl;
  cout << "[2] View the TOP entry in the database " << endl;
  cout << "[3] View the BOTTOM entry in the database " << endl;
  cout << "[4] Add an entry to the TOP of the database " << endl;
  cout << "[5] Search by employee key " << endl;
  cout << "[6] Remove an entry from the BOTTOM of the database " << endl;
  cout << "[7] Remove an entry from the TOP of the database " << endl;
  cout << "[0] To exit and print Annual Report " << endl << endl;

  cout << endl << endl;

  while (choice != 0) {
    cout << "Enter a menu command: ";
    cin >> choice;
    switch(choice) {
    case 1:
      LL.printList();
      break;
    case 2:
      LL.peek_front();
      break;
    case 3:
      LL.peek_back();
      break;
    case 4:
      LL.push_front();
      break;
    case 5:
      cin >> at;
      LL.at(at);
      break;
    case 6:
      LL.pop_back();
      break;
    case 7:
      LL.pop_front();
      break;
    case 0:
      break;
    default:
      cout << "Not a valid command. Try again: ";
      break;
    }
  }
  
    LL.sumAll();
    LL.min();
    LL.max();
    LL.avg();
    LL.makeReport();
   
  return 0;
  
}
