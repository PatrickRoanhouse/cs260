#include <cstring>
#include "list.h"

using namespace std;

const char	List::YOUR_NAME[]{"Patrick Roanhouse"};

List::List()
{
	// your code here, or in this constructor's initialization list

	
}

List::~List()
{
	// your code here

}

/*You will need to uncomment this constructor and write the code for it.*/

List::Node::Node(const Voter& voter)
	// your initialization list here
{
	// your code here


}


void List::displayByName(ostream& out) const
{
	// your code here
}

void List::displayByIntensity(ostream& out) const
{
	// your code here
}

void List::insert(const Voter& voter)
{
	
}

Voter* const List::find(const char * const name) const
{
	// your code here, return the appropriate value

	return nullptr;
}

bool List::remove(const char * const name)
{
	// your code here, return the appropriate value
	
	return false;
}
