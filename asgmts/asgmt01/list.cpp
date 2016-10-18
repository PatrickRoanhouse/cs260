#include <cstring>
#include "list.h"

using namespace std;

const char	List::YOUR_NAME[]{"Patrick Roanhouse"};

List::List()
{
	// your code here, or in this constructor's initialization list
	*headByName = NULL;
	*headByIntensity = NULL;

	
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
	 item.name = voter.name;
	 item.party = voter.party;
	 item.intensity = voter.intensity;

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
	Node *cur;
	Node *next;

	Node insertNode = new Node (voter);
	if ((headByName == NULL) && (headByIntensity == NULL))
	{
		*headByName = insertNode;
		*headByIntensity = insertNode;
	}
	else if (headByName->nextByName == NULL)
	{
		if (0 <= strcmp(insertNode->item.name , cur->item.name))
		{
			insertNode->nextByName = headByName;
			headByName = insertNode;
		}
		else
		{
			headByName->nextByName = insertNode;
		}
	else
	{
		cur = headByName;
		next = headByName->nextByName;
		while ((0 <= strcmp(insertNode->item.name , cur->item.name)) && (0 < strcmp(insertNode->item.name , next->item.name)) && (nextByName!=NULL))
		{
			cur = next;
			next = nextByName;
		}
		cur->nextByName = insertNode;
		insertNode->nextByName = next;

	}	

			
	}


}

Voter* const List::find(const char * const name) const
{
	// your code here, return the appropriate value
	

	return nullptr;
}

bool List::remove(const char * const name)
{
	// your code here, return the appropriate value
	find()


	return false;
}
