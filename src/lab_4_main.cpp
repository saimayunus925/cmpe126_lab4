// lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "portfolio.h"
#include "stock.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
using namespace std;

int main() {
  // the doubly linked list
  portfolio very_real_portfolio;
  stock s2[5];

  for (int i = 0; i < 5; i++) {
    very_real_portfolio.insert_node(s2[i], i);
  }

  very_real_portfolio.print_portfolio();

  // create the node to insert
  cout << "Creating stock..." << endl;
  stock s;
  Node *n = new Node(s);
  cout << "Stock created." << endl;
  n->printNode();

  cout << "Current list count: " << very_real_portfolio.count << endl;

  // the insertion/deletion/printing menu
  int n1;

  cout << "1. Insert our stock at front of list" << endl;
  cout << "2. Insert our stock at back of list" << endl;
  cout << "3. Insert our stock after any index (must be equal to or less than the list count)" << endl;
  cout << "4. Delete the list's front stock" << endl;
  cout << "5. Delete the list's back stock" << endl;
  cout << "6. Delete the stock at any index (must be equal to or less than the list count)" << endl;
  cout << "7. Print the list of stocks" << endl;
  cout << "8. Reverse print the list of stocks" << endl;
  cout << "9. Load content from stock_data.txt into list" << endl;
  cout << "10. Store list content in stocks_file.txt" << endl;
  cout << "11. Exit" << endl;
  cout << "(The index is the number of each element; e.g. the second element in the list has index 2)" << endl;

  cin >> n1;

  while (n1 != 11) {
    if (n1 == 11)
      exit(1);
    else if (n1 == 1)
      very_real_portfolio.push(s);
    else if (n1 == 2)
      very_real_portfolio.append(s);
    else if (n1 == 3) {
      cout << "List count: " << very_real_portfolio.count << endl;
      int n2;
      cout << "Enter an index: " << endl;
      cin >> n2;
      if (n2 > very_real_portfolio.count) {
        cout << "ERROR - index out of range." << endl;
        exit(1);
      }
      very_real_portfolio.insert_node(s, n2);
    }
    else if (n1 == 4)
      very_real_portfolio.delete_node_at_index(1);
    else if (n1 == 5) {
      int INDEX = very_real_portfolio.count;
      very_real_portfolio.delete_node_at_index(INDEX);
    }
    else if (n1 == 6) {
      cout << "List count: " << very_real_portfolio.count << endl;
      int n3;
      cout << "Enter an index: " << endl;
      cin >> n3;
      if (n3 > very_real_portfolio.count) {
        cout << "ERROR - index out of range." << endl;
        exit(1);
      }
      very_real_portfolio.delete_node_at_index(n3);
    }
    else if (n1 == 7)
      very_real_portfolio.print_portfolio();
    else if (n1 == 8)
      very_real_portfolio.reverse_print_portfolio();
    else if (n1 == 9)
      very_real_portfolio.load1("stock_data.txt");
    else if (n1 == 10)
      very_real_portfolio.store("stocks_file.txt");
    cout << "Please pick from the menu again." << endl;
    cin >> n1;
  }
}


