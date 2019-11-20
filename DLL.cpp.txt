// ID:  DLL.cpp / Implementation file for the class SortedList
// AUTHOR:  Michael Ziegler
// INSTALLATION:  MIDDLE TENNESSEE STATE UNIVERSITY
// RCS: $Revision$
// REMARKS:  Implementation file for the class SortedList.
//   Pointer-based dummy-headed circular singly-linked list implementation.


#include <iostream>
using namespace std;

#include "DLL.h"

// Constructors and Destructor:

//CONSTRUCTOR
SortedList::SortedList() : size(0)  
{
	head = new tNode;
	head->next = head;
  //  head->item = NULL;    // optional - for debugging only
} // end Constructor

//COPYCONSTRUCTOR
SortedList::SortedList(const SortedList& listArg)  
{
	size = listArg.size;

	head = new tNode;
	head->next = head;
	//head->item = -888;    // optional - for debugging only
	
	copyList(listArg.head, head);
} // end Copy Constructor

//DECONSTRUCTOR
SortedList::~SortedList()
{
	tNodePtr future;
	tNodePtr curDestruct = head->next;
	
	while(curDestruct != head)	     //While: any Node exists along the head's
	{			
		future = curDestruct->next;         //point both to the same node.
		delete curDestruct;
		curDestruct = future;
	}
	delete head;
} // end Destructor

//OVERLOADEDOPERATOR
SortedList& SortedList::operator=(const SortedList& rhs)
{
	tNodePtr future, cur, prev;
	// Is there any work to be done?  Check if target same as rhs.
	if ( this != &rhs )
	{
		if(size != 0)
		{
		// Deallocate anything the target of the assignment target
		// might already have allocated to it.
			cur = head->next->next;
			prev = head->next;
			
			while(size!=0)		 //While not circled back to head.
			{	
				delete prev;
				prev = cur;
				cur = cur->next;
				
				--size;
			}
		}
		// Now "copy" the object
		size = rhs.size;
		copyList(rhs.head, head);
	}
	return *this;
} // end operator=


// List Operations:

//ISEMPTY
bool SortedList::IsEmpty() const
{
	return (size == 0);
} // end IsEmpty

//LENGTH
int SortedList::Length() const
{
	return size;
} // end Length


//INSERT
void SortedList::Insert(ItemType newItem, bool& success)
//                      IN                OUT
{
	int position = 1;
	tNodePtr previous = NULL;
	tNodePtr newPtr = new tNode;
	newPtr->item = newItem;
	bool isPresent = locateNode(newItem, previous, position);

	if(!isPresent)
	{
		newPtr->next = previous->next;
		previous->next = newPtr;
		
		++size;
		success = true;
	}
	else
		success = false;
} // end Insert


//REMOVE
void SortedList::Remove(ItemType anItem, bool& success)   
//                      IN               OUT
{
	int position = 1;
	bool isFound;
	tNodePtr previous = NULL;
	tNodePtr current = NULL;
	
	isFound = locateNode(anItem, previous, position);

	if (isFound)
	{
		// Redirect the "previous node's NEXT", making it point to
		//the node following-the node we're about to remove (target).
		//target = list[previous].next;- - - - - - - OLA_ALL_VERSION
		current = previous->next;
		
		//list[previous].next = list[target].next; - OLA_ALL_VERSION
		previous->next = current->next; 
		
		//PushAvail(target); - - - - - - - - - - - - OLA_ALL_VERSION
		delete current;
		current = NULL;
		
		//Adjust the size of the list, return success.
		success = true;
		--size;
	}
	else
		success = false;
} // end Remove.

//FIND
int SortedList::Find(ItemType anItem) const
//                   IN
{
	tNodePtr prev;   // Pointer to predecessor of found node
	int position;    // Item's list position

	bool isPresent = locateNode(anItem, prev, position);

    return  (isPresent) ? position : -1;
} // end Find

//RETRIEVE
void SortedList::Retrieve(
    int position, ItemType& dataItem, bool& success) const
//	IN            OUT                 OUT
{	
	if(position > size || position <= 0)
		success = false;
	else
	{
		int count = 1;
		tNodePtr cur = head->next;
	
		while(count != position)
		{
			cur = cur->next;
			++count;
		}
		dataItem = cur->item;
		
		success = true;
	}
} // end Retrieve


// Private functions:

//COPYLIST
void SortedList::copyList(tNodePtr original, tNodePtr duplicate)
//                        IN                 OUT
{
	//Declarations.
	tNodePtr duplicatePrev = duplicate;
	tNodePtr duplicateCur;				   //Pointer to duplicate item.
	tNodePtr originalCur = original->next; //Pointer to current original item.

	//Go through entire list. stop at dummy head.
	while(originalCur != original) 	
	{
		//New node for copied list.
		duplicateCur = new tNode;              
		
		//Make the Copy.
		duplicateCur->item = originalCur->item;
		//Point 'new duplicate Node'to the dummy head.
		duplicateCur->next = duplicatePrev->next;
		
		//Point 'duplicatePrev' to the new node.
		duplicatePrev->next = duplicateCur;
		duplicatePrev = duplicateCur;
		
		//move on to next Node.
		originalCur = originalCur->next; 

	}
} // end copyList

//LOCATENODE
bool SortedList::locateNode
    (ItemType anItem, tNodePtr& previous, int& position) const
//   IN               OUT                 OUT
{
	position = 1;
	tNodePtr curPtr = head->next;
	previous = head;
		//Traverse the list until 'curPtr' circles back to head/anItem is found.
	
		while(curPtr != head && curPtr->item < anItem)
		{
			previous = curPtr;          	//Continue traversing.
			curPtr = curPtr->next;
			++position;				//Increment position Count.
		}
		
		//Check current item to see if it matches anitem.
		if(curPtr->item == anItem)
			return true; 
		else 
			return false;  
} // end locateNode

//  End of implementation file.
