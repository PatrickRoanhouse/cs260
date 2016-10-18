#include <iostream>
#include <string.h>
#include <iomanip>
#include "voter.h"

using namespace std;


Voter::Voter(const char * const name, const Party party, const int intensity) :
	party{party},
	intensity{intensity}
{
	// your code here, or in this constructor's initialization list


	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);

}

Voter::~Voter()
{
	// your code here
	delete [] name;
	name = nullptr;


}

void Voter::displayColumnHeadings(ostream& out)
{
	// your code here
	cout << setw(26) << left << "Name" << setw(17) << "Party" << setw(9) << "Intensity" << endl;
	cout << setw(26) << left << "----" << setw(17) << "-----" << setw(9) << "---------" << endl;


}
ostream& operator<<(ostream& out, Voter* voter)
{
	out << setw(26) << left << voter->name << setw(17) << voter->party << setw(9) << right << voter->intensity << endl;

	return out;

}


ostream& operator<<(ostream& out, Party party)
{
	// your code here
	switch(party)
	{
		case Party::Republican:
			out << "Republican";
			break;
		case Party::Democrat:
			out << "Democrat";
			break;
		case Party::Libertarian:
			out << "Libertarian";
			break;
		case Party::Green:
			out << "Green";
			break;
		default:
			out << "Not Recognized";		

	}
	

	return out;
}
