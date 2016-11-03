// add code to these functions to make Quack do something useful

#include "quack.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	Quack::YOUR_NAME[]{"I. Forgot"};

// change the value of this variable to true if you're doing the Premium version
const bool	Quack::PREMIUM_VERSION{false};

Quack::Quack(int capacity, int growBy) :
	// replace these initializations with the ones you actually need
	items{new char[1]},
{
	initArray();	// you are required to call this function here, and
					// it must be the first thing in the constructor body


	front		  = -1;
	back		  = 0;
	count		  = 0;
	lstLen	  = capacity;
	direction  = 1;		// Clockwise
}

Quack::~Quack(void)
{
	if (items)
	{
		delete [] items;
		items	= NULL;
	}	
}

// items are pushed to successively LOWER slots in the circular array
// (except for when the beginning of the array "wraps around" to the end)
bool Quack::pushFront(const char ch)
{
	item		anItem;
	
	anItem.n	= n;
	count		= count + 1;
	front		= mod((front + direction), lstLen );
	
		// When front "over lap" back, shift back over one
		// Also, decrease count by 1 because new items are not being added
		// to the list. (only existing items get overwritten when count > lstLen)
	if (count > lstLen)
	{
		back	= mod((back + direction), lstLen);
		count = count - 1;
	}
	
	items[front]	= anItem;
	return false;
}

// items are pushed to successively HIGHER slots in the circular array
// (except for when the end of the array "wraps around" to the beginning)
bool Quack::pushBack(const char ch)
{
	item anItem;
	anItem.n	= n;
	
		// When back "over laps" front, shift front by 1
	if (count >= lstLen)
	{
		back			= front;
		front			= mod((front - direction), lstLen);
		items[back] = anItem;
 	}
 	
	else if (count == 0)
	{
			// When no items in list pushBack and pushFront is the same
			// so just call pushFront
		pushFront(n);	
	}
	
	else
	{
		count		 = count + 1;
		back		 = mod((back - direction), lstLen);
		items	[back] = anItem;
	}

	return false;
}

bool Quack::popFront(char& ch)
{
		bool retVal = false;
	
	if (count != 0)
	{
		n	      = items[front].n;
		front		= mod((front - direction), lstLen);
		count		= count - 1;
	}
	else
	{
			// No items to pop. List is empty
		retVal = true;
	}
	
	return retVal;
}

bool Quack::popBack(char& ch)
{
	bool retVal = false;
	
	if (count != 0)
	{
		n			= items[back].n;
		back		= mod((back + direction), lstLen);
		count		= count - 1;
	}
	else
	{
			// No items to pop
		retVal = true;
	}
	
	return retVal;
}

void Quack::rotate(int r)
{
   if (count == lstLen)
   {
      front    = mod((front + r), lstLen);
      back     = mod((back + r), lstLen);
   }
   
      // Same as popback. If list is big, rotating one by one is very ineficent
   else if (r == (count -1))
   {
      
      //popBack();
   }

   
   else
   {
      int i = 0;
      
         // When input is negative move front and back clockwise
      if ( r < 0)
      {
         while (i > r)
         {
            front        = mod((front + direction), lstLen);
            items[front] = items[back];
            back         = mod((back + direction), lstLen);
            --i;     // because r is negative
         }
         
      }
      
         // When input is non negative, move counter clockwise
      else
      {
         while (i < r)
         {
            back        = mod((back - direction), lstLen);
            items[back] = items[front];
            front       = mod((front - direction), lstLen);
            ++i;
         }
      }
      
   }
	
	return;
}

void Quack::reverse(void)
{ 
	direction == 1? direction = -1: direction = 1;
		// reverse front and back
	swap(front, back);
   
	return;
}

int	Quack::itemCount(void)
{
	return 0;
}

ostream& operator<<(ostream& out, Quack *q)
{
	out << "quack: empty" << endl << endl;

	// returning out is ALWAYS required for an operator<< overload
	return out;
}
