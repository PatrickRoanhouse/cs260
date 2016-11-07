// add code to these functions to make Quack do something useful

#include "quack.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	Quack::YOUR_NAME[]{"Patrick Roanhouse"};

// change the value of this variable to true if you're doing the Premium version
const bool	Quack::PREMIUM_VERSION{true};

Quack::Quack(int capacity, int growBy) :
	// replace these initializations with the ones you actually need
	capacity(capacity),
	growBy(growBy),
	nItems(0),
	items(new char[capacity]),
	queueFront(0),
	queueBack(0)
{
	initArray();	// you are required to call this function here, and
					// it must be the first thing in the constructor body
}

Quack::~Quack(void)
{
	delete[] items;
}

// items are pushed to successively LOWER slots in the circular array
// (except for when the beginning of the array "wraps around" to the end)
bool Quack::pushFront(const char ch)
{
	if ( nItems >= capacity)
		return false;

	if (nItems != 0)
		queueFront = queueFront - 1;
	if (queueFront < 0)
		queueFront = queueFront + capacity;

	items[queueFront] = ch;
	nItems++;

	return true;
}

// items are pushed to successively HIGHER slots in the circular array
// (except for when the end of the array "wraps around" to the beginning)
bool Quack::pushBack(const char ch)
{
	if ( nItems >= capacity)
		return false;

	if (nItems != 0)
		queueBack = queueBack + 1;
	if (queueBack >= capacity)
		queueBack = queueBack - capacity;

	items[queueBack] = ch;
	nItems++;

	return true;
}

bool Quack::popFront(char& ch)
{
	if ( nItems == 0)
		return false;
	
	ch = items[queueFront++];

	if ( queueFront >= capacity )
		queueFront = queueFront - capacity;

	nItems--;

	return true;
}

bool Quack::popBack(char& ch)
{
	if ( nItems == 0)
		return false;
	
	ch = items[queueBack--];

	if (queueBack < 0)
		queueBack = capacity + queueBack;

	nItems--;

	return true;
}

void Quack::rotate(int r)
{
	// Avoid extra rotations if nItems = 2 and rotate(5) is called
	if (r > nItems)
		r = r % nItems;

	// 
	if (r > nItems/2)
		r = r - nItems;

	if (r > 0)
	{
		for (int i = 1; i <= r; i++)
		{
			//char temp;
			//popFront(temp);
			//pushBack(temp);

			//popFront
			char ch = items[queueFront];
			queueFront = (queueFront+1) % capacity;

			//pushBack
			queueBack = (queueBack+1) % capacity;
			items[queueBack] = ch;			
		}
	}
	else
	{
		for (int i = 1; i <= (r*-1); i++)
		{
			//popBack
			char ch = items[queueBack];
			queueBack = (queueBack-1) % capacity;

			//pushFront
			queueFront = (queueFront-1) % capacity;
			if (queueFront < 0)
				queueFront = queueFront + capacity;
			items[queueFront] = ch;
		}
	}
}

void Quack::reverse(void)
{
	int lastIndex = capacity - 1;
	char tempChar;

	for (int i = 0; i <= (lastIndex/2); i++)
	{
		tempChar = items[i];
		items[i]=items[lastIndex-i];
		items[lastIndex-i]=tempChar;

	}
}

int	Quack::itemCount(void)
{
	return nItems;
}

ostream& operator<<(ostream& out, Quack *q)
{
	if (q->itemCount() == 0)
		out << "quack: empty" << endl << endl;
	else
	{
		out << "quack: ";
		
		int passes = 0;
		int printIdx = q->queueFront;
		while  (passes < q->nItems)
		{
			out << q->items[printIdx];

			if (printIdx == q->capacity-1)
				printIdx = 0;
			else
				printIdx++;
			passes++;
			if (passes != q->nItems)
				out << ", ";
		}

		out << endl << endl;
	}

	// returning out is ALWAYS required for an operator<< overload
	return out;
}
