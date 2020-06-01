/*
 * Node.h
 *
 *  Created on: Oct 8, 2019
 *      Author: yunus
 */

#include "stock.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>

#ifndef NODE_H_
#define NODE_H_

class Node {
  friend ostream & operator << (ostream &out, const Node &n) {
    out << n.data << endl;
    return out;
  }
  friend istream & operator >> (istream &in, Node &n) {
    in >> n.data;
    return in;
  }
public:
	stock data;
	Node* next, * prev;
	Node() {
		next = NULL;
		prev = NULL;
	}
	Node(stock something) {
		data = something;
		next = NULL;
		prev = NULL;
	}
	void printNode() {
		cout << data << endl;
	}
};





#endif /* NODE_H_ */
