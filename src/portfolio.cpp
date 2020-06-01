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

void portfolio::push(stock new_data) {
	Node* new_node = new Node(new_data);
	new_node->next = head;
	new_node->prev = NULL;
	if (head == NULL)
		head->prev = new_node;
	head = new_node;
	count++;
}

void portfolio::insert_node(stock new_data, int index) {
	if (index < 0) {
		cout << "No negative indices allowed." << endl;
		exit(1);
	}
	Node* curr = head, * previous = NULL;
	while (index-- > 0) {
		if (!curr) {
			cout << "Invalid index." << endl;
			exit(1);
		}
		previous = curr;
		curr = curr->next;
	}
	Node* new_node = new Node(new_data);
	new_node->prev = previous;
	new_node->next = curr;

	if (new_node->prev)
		new_node->prev->next = new_node;
	else
		head = new_node;

	if (new_node->next)
		new_node->next->prev = new_node;
	else
		tail = new_node;
	count++;
}

void portfolio::insert_node(Node *tbi, int index) {
  // assume tbi has the data we need to insert
  if (index < 0) {
    cout << "No negative indices allowed." << endl;
    exit(1);
  }
  Node* curr = head, * previous = NULL;
  while (index-- > 0) {
    if (!curr) {
      cout << "Invalid index." << endl;
      exit(1);
    }
    previous = curr;
    curr = curr->next;
  }
  tbi->prev = previous;
  tbi->next = curr;

  if (tbi->prev)
    tbi->prev->next = tbi;
  else
    head = tbi;

  if (tbi->next)
    tbi->next->prev = tbi;
  else
    tail = tbi;
  count++;
}

void portfolio::append(stock new_data) {
	Node* new_node = new Node(new_data), * last = head;
	if (head == NULL) {
		new_node->prev = NULL;
		head = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
	count++;
}

void portfolio::append_node(Node *tba) {
    Node* last = head;
    if (head == NULL) {
      tba->prev = NULL;
      head = tba;
      return;
    }
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = tba;
    tba->prev = last;
    count++;
}

void portfolio::delete_node(Node* tbd) {
	if (head == NULL || tbd == NULL)
		return;
	if (head == tbd)
		head = tbd->next;
	if (tbd->next != NULL)
		tbd->next->prev = tbd->prev;
	if (tbd->prev != NULL)
		tbd->prev->next = tbd->next;
	free(tbd);
	count--;
}

void portfolio::delete_node(stock tbd) {
  Node *tbd_node = new Node(tbd);
  if (head == NULL || tbd_node == NULL)
    return;
  if (head == tbd_node)
    head = tbd_node->next;
  if (tbd_node->next != NULL)
    tbd_node->next->prev = tbd_node->prev;
  if (tbd_node->prev != NULL)
    tbd_node->prev->next = tbd_node->next;
  free(tbd_node);
  count--;
}

void portfolio::delete_node_at_index(int index) {
	if (head == NULL || index <= 0)
		return;
	Node* curr = head;
	for (int i = 1; curr != NULL && i < index; i++)
		curr = curr->next;
	if (curr == NULL)
		return;
	delete_node(curr);
}

void print(Node* h) {
	Node* temp = h;
	while (temp != NULL) {
		temp->printNode();
		temp = temp->next;
	}
}
void reverse_print_recursive(Node* h) {
	if (h == NULL)
		return;
	reverse_print_recursive(h->next);
	h->printNode();
}

void portfolio::print_portfolio() {
	print(head);
}

void portfolio::reverse_print_portfolio() {
	reverse_print_recursive(head);
}

void portfolio::load(string fn) {
	// we need to pull stocks from a file fn and put them in our linked list
	// how? idea: pull stocks from fn, put each stock in a node, insert each node in our list
	// for now, we will append the stocks to the list
	// how do we know how many nodes to make? easy: make a variable like count, increment it each time we take in a stock object
	int running_count = 0, i = 0;
	stock s, * collection = NULL;
	Node* nodes = NULL;
	ifstream fin;
	fin.open(fn.c_str());
	if (fin.fail()) {
		cout << "Input file failed to open." << endl;
		exit(1);
	}
	while (!fin.eof()) {
		fin >> s;
		running_count++;
	}
	// so I realized that this is kind of a problem because we keep taking in s, but we need the running_count for an array of nodes
	// so I did what I do best: make more arrays (the stock array is 'collection', the Node array is 'nodes')
	collection = new stock[running_count];
	nodes = new Node[running_count];
	// yes, collection is full, but we will reassign each element as we are taking in the stock objects
	while (!fin.eof() && i < running_count) {
		fin >> collection[i];
		nodes[i].data = collection[i];
		i++;
	}
	fin.close();
	// now we have our nodes, so we will repeatedly call insert_node or something until all the elements have been inserted
	for (int j = 1; j <= running_count; j++) {
		insert_node(nodes[j].data, j);
	}
}

void portfolio::load1(string fn) {
  ifstream  fin;
    fin.open(fn.c_str());
    if (fin.fail())
      exit(1);
    while(!fin.eof()){
      Node *sp = new Node();
      fin >> *sp;
      append_node(sp);
    }
    fin.close();
    // return(true);
}

void portfolio::store(string fn) {
	// we need to store each stock in our list in a file fn
	// algorithm: loop through/traverse list, output data of each node to fn
	// first let's open our output stream
	ofstream fout;
	fout.open(fn.c_str());
	if (fout.fail()) {
		cout << "Output file failed to open." << endl;
		exit(1);
	}
	Node* temp = head;
	while (temp != NULL) {
		fout << temp->data;
		temp = temp->next;
	}
	fout.close();
}
