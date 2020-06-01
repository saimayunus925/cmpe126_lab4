/*
 * stock.h
 *
 *  Created on: Sep 30, 2019
 *      Author: yunus
 */

#ifndef STOCK_H_
#define STOCK_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
using namespace std;

class stock {
  friend string generate_symbol(unsigned int length);
  // generating random numbers - rand % 10 gives numbers from 0-9
  friend int generate_cost(), generate_shares();
  // overloaded operators
  friend ostream& operator<< (ostream&, const stock&);
  friend istream& operator>> (istream&, stock&);
public:
  stock();
  stock(string sym, double c, int sh);
  // void print();
  void operator = (const stock& s) {
    symbol = s.symbol;
    cost = s.cost;
    shares = s.shares;
  }
  bool operator < (const stock&);
  stock(const stock&);
  // rule of three - assignment operator, copy constructor, destructor (automatically generated)
  string symbol;
  int cost;
  int shares;
};


#endif /* STOCK_H_ */
