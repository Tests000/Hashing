#include "Polyclinic.h"

Polyclinic::Polyclinic(ifstream& file, int table_size)
{
	size = table_size;
	table = new cell[table_size];
	getline(file, name);
	while (!file.eof())
	{
		string FIO_; getline(file, FIO_);
		string gender_; getline(file, gender_);
		TPatient* new_person;
		short age_;
		string polic;
		file >> age_ >> polic;
		file.ignore();
		new_person = new TPatient(FIO_, gender_, age_, polic);
		getline(file, FIO_);
		Add(new_person);
	}
}

Polyclinic::~Polyclinic()
{
	for (int i = 0; i < size; i++)
		if (table[i].state)
			delete table[i].info;
	delete table;
}

bool Polyclinic::Add(TPatient* person)
{
	bool res = true;
	int pos = Hash(person->get_policy_number());
	int i;
	for (i = 0; i <= size && table[(pos + i) % size].state != false; i++);
	if (i < size)
	{
		table[pos + i].info = person;
		table[pos + i].state = true;
	}
	else
		res = false;
	return res;
}

int Polyclinic::Hash(string key)
{
	int res = 0;
	for (char i : key)
	{
		res += i;
	}
	return res % size;
}

bool Polyclinic::Delete(string name)
{
	int hash = Hash(name);
	int i;
	bool res=false;
	int pos = Find(name);
	if (table[pos].state)
	{
		int last_empty=pos;
		delete table[pos].info;
		table[pos].state = false;
		for (i=1; table[(pos + i) % size].state; i++)
		{
			int cur_hash = Hash(table[(pos + i) % size].info->get_policy_number());
			if ((pos + i) % size- cur_hash >= (pos + i) % size - last_empty)
			{
				table[last_empty].info = table[(pos + i) % size].info;
				table[last_empty].state = true;
				last_empty = (pos + i) % size;
				table[last_empty].info = NULL;
				table[last_empty].state = false;
			}
		}
		res = true;
	}
	return res;
}

int Polyclinic::Find(string name)
{
	int hash = Hash(name);
	int i;
	for (i = 0; table[(hash + i) % size].state && i<=size && table[(hash + i) % size].info->get_policy_number() != name; i++);
	int pos = (hash + i) % size;
	if (!table[pos].state || i == size)
		pos = -1;
	return pos;
}

void Polyclinic::print()
{
	for (int i = 0; i < size; i++)
		if (table[i].state)
		{
			cout << i << ' ' << Hash(table[i].info->get_policy_number()) << '\n';
			table[i].info->print();
		}
}
