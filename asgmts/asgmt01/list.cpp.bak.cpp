#include <cstring>
#include "list.h"

using namespace std;

const char	List::YOUR_NAME[]{"Patrick Roanhouse"};

List::List()
{
	// your code here, or in this constructor's initialization list
	headByName = NULL;
	headByIntensity = NULL;

	
}

List::~List()
{
	// your code here
		

		Node * curr(nullptr);
		Node * prev(nullptr);
		curr = headByName;
		while(curr != nullptr)
		{
			curr = curr->nextByName;
			delete curr;
		
		}




}

/*You will need to uncomment this constructor and write the code for it.*/

List::Node::Node(const Voter& voter) : item{voter.getName(), voter.getParty(), voter.getIntensity()}
	// your initialization list here
{
	// your code here
	nextByName(nullptr);
	nextByIntensity(nullptr);

}


void List::displayByName(ostream& out) const
{
	// your code here
	node * curr{nullptr};

	Voter::displayColumnHeadings(out);

	if(headByName == nullptr)
	{
		out << "List is empty" << endl;
	}
	else if(headByName != nullptr)
	{
		curr = headByName;
		while(curr != nullptr)
		{
			out << &curr->item;
			curr = curr->nextByName;
		}
	}

}

void List::displayByIntensity(ostream& out) const
{
	// your code here
	Node * curr{nullptr}
	Voter::displayColumnheadings(out);
	if(headByIntensity != nullptr)
	{
		curr = headByIntensity;
		while (curr != nullptr)
		{
			out << &curr->item;
			curr = curr->nextByIntensity;
		}
	}
}

void List::insert(const Voter& voter)
{
	Node *curr;
	Node *prev;

	Node newNode(new Node (voter));
	if (headByName == NULL)
	{
		*headByName = newNode;
		*headByIntensity = newNode;
	}
	else if (headByName != NULL)
	{	
		prev = nullptr;
		curr = headByName;
		
		if (strcmp(voter.getName(), curr->item.getName()) == 0)
		{
			prev = curr;
			curr = curr->nextByName;
			newNode->nextByName = curr;
			prev->nextByName = newNode;

		}
		else if (strcmp(voter.getName(), curr->item.getName()) < 0)
		{
			newNode->nextByName == curr;
			headByName = newNode;
		}
		else if(strcmp(voter.getName(), curr->item.getName()) > 0)
		{
			while(strcmp(voter.getName(), curr->item.getName()) > 0)
			{
				prev = curr;
				curr = curr->nextByName;

				if(strcmp(voter.getName(), curr->item.getName()) <= 0)
				{
					newNode->nextByName = curr;
					prev->nextByName = newNode;
					break;
				}
			}
		}
	}
	

	prev = nullptr;
	curr = headByIntensity;

	if(voter.getIntensity() > curr->item.getIntensity())
	{
		newNode->nextByIntensity = curr;
		headByIntensity = newNode;
	}
	else
	{
		while(curr != nullptr)
		{
			prev = curr;
			curr = curr->nextByIntensity;
			if(voter.getIntensity() < prev->item.getIntensity() && curr == nullptr)
			{
				newNode->nextByIntensity == nullptr;
				prev->nextByIntensity = newNode;
			}
			else if (voter.getIntensity() < prev->item.getIntensity() && voter.getIntensity() > curr->item.getIntensity())
			{
				newNode->nextByIntensity = curr;
				prev->nextByIntensity = newNode;
			}
		}
	}

}

Voter* const List::find(const char * const name) const
{
	// your code here, return the appropriate value
	Node * curr(nullptr);

	if(headByName == nullptr)
	{
		return nullptr;
	}
	else if (headByName != nullptr)
	{
		curr = headByName;
		while(strcmp(curr->item.getName(), name) != 0)
		{
			curr = curr->nextByName;
			if(curr == nullptr)
			{
				return nullptr;
			}
		}
		if(strcmp(curr->item.getName(), name) == 0)
		{
			return &curr->item;
		}
	}

	return nullptr;
}

bool List::remove(const char * const name)
{
	// your code here, return the appropriate value
	Node * currName{nullptr};
	Node * prev{nullptr};
	Node * currIten{nullptr};

	currName = headByName;
	currIten = headByIntensity;
	while (currName->nextByName != nullptr)
	{
		prev = currName;
		currName = currName->nextByName;
		if(strcmp(name, currName->item.getName()) == 0)
		{
			prev->nextByName = currName->nextByName;
			while(currIten->nextByIntensity != nullptr)
			{
				prev = currIten;
				currIten = currIten->nextByIntensity;
				if(currIten == currName)
				{
					prev->nextByIntensity = currIten->nextByIntensity;
					delete currName;
				}
			}
		}
	}

	return false;
}