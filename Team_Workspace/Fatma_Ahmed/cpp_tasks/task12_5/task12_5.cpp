// task12_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;


class LidraData {

public:
	LidraData() { cout << "Data Allocated"<<endl;}
	~LidraData() { cout << "Data Freed" << endl; }

};
int main()
{
	shared_ptr<LidraData> main_ptr(new LidraData());
	cout << main_ptr.use_count() << endl;

	{
		shared_ptr <LidraData> algo_ptr = main_ptr;

		cout << main_ptr.use_count() << endl;

	}
	cout << main_ptr.use_count() << endl;
	main_ptr.reset();

}

