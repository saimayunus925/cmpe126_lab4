#pragma once

#include "stock.h"
#include "Node.h" 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
using namespace std;

class portfolio {
	friend void print(Node* h);
	friend void reverse_print_recursive(Node* h);
public:
	Node* head, * tail;
	int count;
	void load(string fn), store(string fn);
	// 'load' extracts info from file fn, 'store' inserts info into file fn
	void load1(string fn);
	void append_node(Node *tba);
	portfolio() {
		head = NULL;
		tail = NULL;
		count = 0;
	}
	portfolio(int SIZE) {
		head = NULL;
		tail = NULL;
		count = SIZE;
	}
	void print_portfolio(), reverse_print_portfolio();
	void insert_node(stock new_data, int index);
	void insert_node(Node *tbi, int index); // function overloading
	void delete_node(Node* tbd), delete_node_at_index(int index);
	void delete_node(stock tbd); // more function overloading
	void push(stock new_data), append(stock new_data); // of course, these are the insert_front and insert_back functions respectively
};

