#include "LinkedList.hpp"


LinkedList::LinkedList(string cmd) {
  head = nullptr;
  nodeCount = 1;
  average = 0;
  maxSale = 0;
  minSale = 0;
  sum = 0;
  workerCount = 0;
  output.open(cmd);
}

LinkedList::~LinkedList() {

  Node * temp;
  cout << "Deleting Database" << endl;
  if(head == NULL) {
    cout << "Database already empty!" << endl;
  }
  else {
    while(head){
      temp = head;
      head = head->next;
      free(temp);
}
    cout << "Database empty!" << endl;
  }
}

void LinkedList::makeReport() {

  Node * temp = head;
  output << "\t\t\t" "***ANNUAL REPORT***" << endl << endl << endl;
  output << "\t" << "Owners this Year: " << endl;
  while(temp) {
    if(temp->code == 'O') {
      output << "-" << temp->name << endl;
    }
    temp = temp->next;
  }
  output << endl << endl << endl;
  temp = head;
  output <<"\t" <<"Managers this year: " << endl;;
 
  while(temp) {
    if(temp->code == 'M') {
      output << "-" << temp->name << endl;
    }
    temp = temp->next;
  }
  output << endl << endl << endl;

  temp = head;
  output << "\t" <<"Workers this year: " << endl;
  while(temp) {
    if(temp->code == 'W') {
      output << "-" << temp->name << endl;
    }
    temp = temp->next;
  }
  output << endl;
 
  temp = head;
  while(temp) {
    if(temp->sales == minSale) {
      output << "Lowest Earning Emloyee: "<< temp->name << endl << endl;
      output << temp->name << " to be terminated at next meeting." << endl;
    }
    
    temp = temp->next;
  }
   
  output << endl << endl << endl; 
  output << "Totals Annual Sales: $" << sum  << endl<< "Average Annual Sales: $"<< average << endl << endl;
  output << "All employees earnings greater than the average are to recieve a five percent bonus on next pay period " << endl;
  temp = head;
  while( temp) {
    if (temp->code == 'M') {
      if(temp->sales >= average) {
	output << "\tManager(Bonus): " << temp->name << endl;
      }
    }
      else if(temp->code == 'W') {
	if(temp->sales >= average) {
	  output << "\tWorker(Bonus): " << temp->name << endl;
	}
      }
    temp = temp->next;
    }
}
void LinkedList::sumAll() {

  Node * temp = head;
  while(temp != nullptr) {
    sum += temp->sales;
    temp = temp->next;
  }
}

void LinkedList::avg() {

  average = sum / (double)workerCount;
  
}

void LinkedList::max() {

  Node * temp = head;

  while(temp!= nullptr) {
    if (maxSale < temp->sales) {
      maxSale = temp->sales;
    }
    temp = temp->next;
  }
}

void LinkedList::min() {
  Node * temp = head;
  while(temp!= nullptr) {
    if(temp->code == 'M' || temp->code =='W') {
      if(minSale == 0) {
	minSale = temp->sales;
      }
    if(temp->sales < minSale) {
      minSale = temp->sales;
    }
    }
    temp = temp->next;
  }
}

void LinkedList::pop_front() {

  Node * temp = head;
  if(isEmpty()) {
    cout << "List is empty!" << endl;
    return;
  }
  else {
  head = temp->next;
  free(temp);
  }

}
void LinkedList::pop_back() {

  Node * current = head;
  Node * temp;
  if(isEmpty()) {
    cout << "List is empty!" << endl;
    return;
  }
  else {
    while (current->next != nullptr) {
      temp = current;
      current = current->next;
    }
    free(current);
    temp->next = nullptr;
  }
}

void LinkedList::at(int num) {
  Node * temp = head;
  if(isEmpty()) {
    cout << "List is empty" << endl;
  }
  else {
    while (temp!= nullptr) {

      if (temp->key == num) {

	cout << "Name: " << temp->name << endl << "Code: " <<temp->code << endl;
	    if(temp->code == 'O') {
       		cout << "Total Sales: N/A" << endl;
		return;
    	    }
	else {
	cout << "\tTotal Sales: $"<<temp->sales << endl;
	return;
      }
}
      else {
	temp = temp->next;
      }
    }
      cout << "Employee not found" << endl;
    
  }
}
void LinkedList::printList() {
  
  Node * temp = head;
  if(isEmpty()) {
    cout << "List is empty!" << endl;
    return;
  }
  else {
    
    while(temp!= nullptr) {
    
    cout << "Employee " << temp->key <<": " << temp->name << endl;
    cout << "Paycode: " << temp->code << endl;
    if(temp->code == 'O') {
	cout << "Total Sales: N/A " << endl;
    }
    else {
      cout << "Total Sales: " << temp->sales << endl;
    }
    cout << endl;
    temp = temp->next;
    }
  }
}

void LinkedList::push_back(){

  Node * temp = head;
  Node * newNode = new Node;
  newNode->next = nullptr;
  newNode->key = nodeCount;
  nodeCount++;
  cout << "Enter name: ";
  cin.ignore();
  getline(cin, newNode->name);
  cout << "Enter paycode(O/Owner, M/Manager, W/Worker): ";
  cin >> newNode->code;
  if(newNode->code == 'M' || newNode->code == 'W') {
  cout << "Enter sales for employee: ";
  cin >> newNode->sales;
  workerCount++;
  }
  cout << endl;
  
  if(isEmpty()) {
    head = newNode;
    minSale = newNode->sales;
  }
  else {
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}


void LinkedList::peek_front() {

  if(isEmpty()) {
    cout << "List is empty!" << endl;
    return;
  }
  else {
    cout << "Employee " << head->key <<": " << head->name << endl;
    cout << "Paycode: " << head->code << endl;
    if(head->code == 'O') {
      cout << "Total Sales: N/A" << endl;
    }
    else {
    cout << "Total Sales: " << head->sales << endl;
    cout << endl;
    }
  }
}

void LinkedList::peek_back() {

  Node * temp = head;
  if(isEmpty()) {
    cout << "List is empty!" << endl;
    return;
  }
  else {
    while(temp->next != nullptr) {
      temp = temp->next;
    }
    cout << "Employee " << temp->key <<": " << temp->name << endl;
    cout << "Paycode: " << temp->code << endl;
    if(temp->code == 'O') {
      cout << "Total Sales: N/A" << endl;
    }
    else {
    cout << "Total Sales: " << temp->sales << endl;
    cout << endl;
    }
  }
}

bool LinkedList::isEmpty(){

  if(head == nullptr) {
    return true;
  }
  else {
    return false;
  }
}

void LinkedList::push_front(){

  Node * newNode = new Node;
  newNode->key = nodeCount;
  nodeCount++;
  cout << "Enter name: ";
  cin.ignore();
  getline(cin, newNode->name);
  cout << "Enter paycode: ";
  cin >> newNode->code;
  cin.ignore();
  if(newNode->code == 'M' || newNode->code == 'W') {
  cout << "Enter sales for employee: ";
  cin >> newNode->sales;
  workerCount++;
  }
  cout << endl;

  newNode->next = head;
  head = newNode;

}



