#pragma once
#include "Person.h"

#include <list>
#include <fstream>

using namespace std;

using TList = list<TPatient*>;
using TIterator = list<TPatient*>::iterator;

struct cell
{
	TPatient* info;
	bool state = false;
};

class Polyclinic
{
private:
	string name;
	int size;
	cell* table;
public:
	Polyclinic(ifstream& file, int table_size);
	~Polyclinic();
	bool Add(TPatient *person);
	int Hash(string key);
	bool Delete(string name);
	int Find(string name);
	void print();
	int getSize() { return size; }
	TPatient* getByIndex(int i) { return table[i].state ? table[i].info : NULL; }
};