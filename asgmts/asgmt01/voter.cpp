#include <iostream>
#include <string.h>
#include <iomanip>
#include "voter.h"

using namespace std;


Voter::Voter(const char * const name, const Party party, const int intensity)
{
	// your code here, or in this constructor's initialization list
	this->Party(party);
	this->intensity(intensity);

	this->name = new char[strlen(name)+1];

	// test 
	cout << name << " " << party << " " << intensity;

}

Voter::~Voter()
{
	// your code here
	delete name [];


}

void Voter::displayColumnHeadings(ostream& out)
{
	// your code here



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
