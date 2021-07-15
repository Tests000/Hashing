#include"Polyclinic.h"

void Task(Polyclinic &polic);

int main()
{
	ifstream ifile("Task.txt");
	if (ifile)
	{
		Polyclinic polic(ifile, 30);
		polic.print();
		cout << "======================================\n";
		Task(polic);
		polic.print();
	}
	ifile.close();
	return 0;
}

void Task(Polyclinic &polic)
{
	TPatient* pac;
	int size = polic.getSize();
	for (int i = 0; i < size; i++)
	{
		pac = polic.getByIndex(i);
		if (pac)
			if (pac->get_policy_number()[0] == '0')
			{
				polic.Delete(pac->get_policy_number());
				i--;
			}
	}
}

