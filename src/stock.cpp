/*
 * stock.cpp
 *
 *  Created on: Sep 30, 2019
 *      Author: yunus
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
#include "stock.h"
using namespace std;

string generate_symbol(unsigned int length) {
	string newstr;
	int pos;
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	while (newstr.size() != length) {
		pos = ((rand() % (str.size() - 1)));
		newstr += str.substr(pos, 1);
	}
	return newstr;
}

// generating random numbers - rand % 10 gives numbers from 0-9
int generate_cost() {
	// int rand();
	return (rand() % 100);
}
int generate_shares() {
	// int rand();
	return (rand() % 100);
}

stock::stock() {
	symbol = generate_symbol(4);
	cost = generate_cost();
	shares = generate_shares();
}
stock::stock(string sym, double c, int sh) {
	symbol = sym;
	cost = c;
	shares = sh;
}
stock::stock(const stock& s) {
	symbol = s.symbol;
	cost = s.cost;
	shares = s.shares;
}

ostream& operator<< (ostream& out, const stock& s) {
	out << "STOCK SYMBOL: " << s.symbol << endl;
	out << "SHARES: " << s.shares << endl;
	out << "COST: " << s.cost << endl;
	return out;
}
istream& operator>> (istream& in, stock& s) {
	in >> s.symbol >> s.shares >> s.cost;
	return in;
}
