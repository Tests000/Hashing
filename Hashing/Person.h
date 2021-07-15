#pragma once
#include <iostream>
#include <string>

using namespace std;

class TPerson
{
private:
	string FIO, gender;
public:
	TPerson() {};
	TPerson(string FIO, string gender);
	string getFIO(), get_gender();
	int Compare(TPerson* p);
	virtual void print();
	bool operator()(TPerson* p1, TPerson* p2) const;
};

class TPatient :public TPerson
{
private:
	short age;
	string policy_number;
public:
	TPatient(string FIO_, string gender_, short age_, string policy_number_) :TPerson(FIO_, gender_), age(age_), policy_number(policy_number_) {}
	virtual void print();
	short get_age();
	string get_policy_number();

};