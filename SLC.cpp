// ID:  SLC.cpp / Implementation file for the class SortedList
// RCS:  $Revision$
// AUTHOR:  Michael Ziegler
// INSTALLATION:  MTSU
// REMARKS:  Implementation file for the class SortedList.
//   Simple array-based list implementation.

#include <iostream>
using namespace std;

#include "SLC.h"


// Constructors and Destructor:

SortedList::SortedList() : size(0)
{
} // end (default) constructor


SortedList::SortedList(const SortedList& listArg): size(listArg.size)
//                     IN
{
	// NOTE:  The array implementation of SortedList does not require
	// a user-defined copy constructor, but the system-supplied copy
	// constructor would not be as efficient.

	for (int pos = 1; pos <= listArg.size; pos++)
		list[pos-1] = listArg.list[pos-1];
} // end copy constructor


SortedList::~SortedList()
{
	// NOTE:  This is just "placeholder" code.  The array implementation
	// of SortedList does not really need a destructor.
} // end destructor


// List Operations:

bool SortedList::IsEmpty() const
{
	return (size == 0);
} // end IsEmpty


int SortedList::Length() const
{
	return size;
} // end Length


void SortedList::Insert(ItemType newItem, bool& success)
//                      IN                OUT
{
	bool isPresent;

	int desiredPosition = locatePosition(newItem, isPresent);

	if (isPresent || size>=MAX_LIST)
		success = false;
	else
	{
		// Make room for new item by shifting all items at
		// positions >= desiredPosition toward the end of the
		// list (no shift if desiredPosition == size+1)
		for (int pos = size; pos >= desiredPosition; pos--)
			list[pos] = list[pos-1];

		// Insert new item.
		list[desiredPosition-1] = newItem;
		size++;

		success = true;
	}
} // end Insert


void SortedList::Remove(ItemType anItem, bool& success)
//                      IN               OUT
{
	int lastPosition = Length();
	int deletePosition = locatePosition(anItem, success);

	if (success)
	{
		// Delete item by shifting all items at
		// positions > deletePosition toward the beginning of the list.
		// (No shift if deletePosition == lastPosition.)
		for (int pos = deletePosition+1; pos <= lastPosition; pos++)
			list[pos-2] = list[pos-1];
		size--;
	}
} // end Remove


int SortedList::	Find(ItemType anItem) const
//	                 IN
{
	bool isPresent;
	int  position = locatePosition(anItem, isPresent);
	return  (isPresent) ? position : -1;
} // end Find


void SortedList::Retrieve(
    int position, ItemType& dataItem, bool& success) const
//	IN            OUT                 OUT
{
	success = position>=1 && position<=Length();

	if (success)
		dataItem = list[position-1];
} // end Retrieve


int SortedList::locatePosition(ItemType anItem, bool& isPresent) const
//	                           IN               OUT
{
	int position;   // position index

	isPresent = false;
	for (position = 1; position <= size; position++)
	{
		if (list[position-1] >= anItem)
		{
			if (list[position-1] == anItem)
				isPresent = true;
			break;
		}
	}
	return position;
} // end locatePosition


//  End of implementation file.
