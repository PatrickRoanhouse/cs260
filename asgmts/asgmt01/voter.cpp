#include <iostream>
#include <string.h>
#include <iomanip>
#include "voter.h"

using namespace std;


Voter::Voter(const char * const name, const Party party, const int intensity)
{
	// your code here, or in this constructor's initialization list
	party{party};
	intensity{intensity};

	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);

}

Voter::~Voter()
{
	// your code here
	delete [] name;


}

void Voter::displayColumnHeadings(ostream& out)
{
	// your code here
	cout << setw(26) << left << "Name" << setw(17) << "Party" << setw(9) << "Intensity" << endl;
	cout << setw(26) << left << "----" << setw(17) << "-----" << setw(9) << "---------" << endl;


}

ostream& operator<<(ostream& out, Voter* voter)
{
	// your code here
	switch(party)
	{
		case Party::Republican:
			cout << "Republican";
			break;
		case Party::Democrat:
			cout << "Democrat";
			break;
		case Party::Libertarian:
			cout << "Libertarian";
			break;
		case Party::Green:
			cout << "Green";
			break;
		default:
			cout << "Not Recognized";		

	}
	

	return out;
}
