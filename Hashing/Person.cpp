#include"Person.h"

string TPerson::getFIO()
{
	return FIO;
}

string TPerson::get_gender()
{
	return gender;
}

TPerson::TPerson(string FIO, string gender)
{
	this->FIO = FIO;
	this->gender = gender;
}

int TPerson::Compare(TPerson* p)
{
	int res = -1;
	if (p->FIO == FIO)
		res = 0;
	else
		if (FIO > p->FIO)
			res = 1;
	return res;
}

void TPerson::print()
{
	cout << FIO << '\n' << gender << '\n';
}

bool TPerson::operator()(TPerson* p1, TPerson* p2) const
{
	return p1->Compare(p2) < 0;
}

void TPatient::print()
{
	TPerson::print();
	cout << age << '\n' << policy_number;
	cout << "\n--------------------\n";
}

short TPatient::get_age()
{
	return age;
}

string TPatient::get_policy_number()
{
	return policy_number;
}