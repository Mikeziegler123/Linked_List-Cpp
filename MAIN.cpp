// olaDLL BY Michael Ziegler,  CSCI2170-002,  Due: 04/10/18
// PROGRAM ID:  SortedListTester.cpp / Illustration of using the SortedList
// AUTHOR:  Michael Ziegler
// REMARKS:  Simple-minded driver for exercising the SortedList methods.
// Original concept based on a variation of Carrano (5th Ed.), Chapter 3,
// pp. 133-134.
//
//  .    1    .    2    .    3    .    4    .    5    .    6    .    7    .
//3456789012345678901234567890123456789012345678901234567890123456789012345
                                                                        
#include <iostream>
using namespace std;

#define MAXLOOP 50   // Maximum loop iterations terminator

#if   defined DLL
#include "DLL.h"     // Dynamic dummy-headed circular linked list
#define OLA "olaDLL"
#elif defined ALL 
#include "ALL.h"     // Array storage dummy-headed linked list
#define OLA "olaALL"
#elif defined SLC
#include "SLC.h"     // Simple array-based sorted list
#define OLA "olaSLC"
#else                // Default to "SLC":
#include "SLC.h"     // Simple array-based sorted list
#define OLA "olaSLC"
#endif

void DisplayList(SortedList List);


int main()
{
	SortedList  L, LL, LLL;
	ItemType    dataItem;
	bool        success;
	int         position;

	cerr << endl << "Starting " << OLA << " testing:" << endl;

	// Assign empty list L to empty list LL, thereby checking assignment
	// and "deep copy" semantics.
	LL = L;

	// Check initial status of list L.
	if ( L.IsEmpty() )
		cerr << "OKAY: List is initially empty." << endl;
	else
		cerr << "ERROR: IsEmpty() returning bad value." << endl;

	// See what happens when you try to insert one item.
	dataItem = 50;
	L.Insert(dataItem, success);
	if (success)
		cerr << "OKAY: Insert operation (seemingly) succeeded." << endl;
	else
		cerr << "ERROR: Insert operation failed." << endl;
	if ( L.IsEmpty() )
		cerr << "ERROR: IsEmpty() returning bad value." << endl;
	else
		cerr << "OKAY: List is not empty anymore." << endl;
	cerr << "Length of list = " << L.Length() << endl;

	// See what happens when you try ...
	// ...these extra instructor-supplied tests for grading

	// Check initial status of list LL.
	if ( LL.IsEmpty() )
		cerr << "OKAY: List LL is initially empty." << endl;
	else
		cerr << "ERROR: LL.IsEmpty() returning bad value." << endl;

	// Check initial status of list LLL.
	if ( LLL.IsEmpty() )
		cerr << "OKAY: List LLL is initially empty." << endl;
	else
		cerr << "ERROR: LLL.IsEmpty() returning bad value." << endl;

	// See what happens when you try to retrieve an item.
	L.Retrieve(1, dataItem, success);
	if (success)
	{
		if (dataItem == 50)
			cerr << "OKAY: List item #" << 1 << " is: " << dataItem << endl;
		else
			cerr << "ERROR: List item #" << 1 << " is: " << dataItem << endl;
	}
	else
		cerr << "ERROR: Retrieve operation failed." << endl;
	L.Retrieve(0, dataItem, success);
	if (success)
		cerr << "ERROR: Retrieve operation failed." << endl;
	L.Retrieve(2, dataItem, success);
	if (success)
		cerr << "ERROR: Retrieve operation failed." << endl;

	// Fill list L with a bunch of numbers.
	L.Insert(25, success);
	if (!success)
		cerr << "ERROR: Insert operation failed." << endl;
	L.Insert(80, success);
	if (!success)
		cerr << "ERROR: Insert operation failed." << endl;
	L.Insert(10, success);
	if (!success)
		cerr << "ERROR: Insert operation failed." << endl;
	L.Insert( 5, success);
	if (!success)
		cerr << "ERROR: Insert operation failed." << endl;
	L.Insert(35, success);
	if (!success)
		cerr << "ERROR: Insert operation failed." << endl;
	L.Insert(15, success);
	if (!success)
		cerr << "ERROR: Insert operation failed." << endl;
	L.Insert(15, success);
	if (success)
		cerr << "ERROR: Invalid insert of duplicate succeeded." << endl;
	for (int i = 1; i <= 9; i++)
	{
		L.Insert(i+100, success);
		if (!success)
			cerr << "ERROR: Insert operation failed." << endl;
	}

	// Display the items on the list L.
	cerr << endl;
	cerr << "DisplayList( L ): should list 16 items \n  "
	  << "(starting with 5 and ending with 109):" << endl;
	DisplayList( L );
	cerr << endl;

	// See what happens when you try to delete an item.
	L.Remove(25, success);
	if (!success)
		cerr << "ERROR: Remove operation failed." << endl;
	position = L.Find(5);
	if (position!=1)
		cerr << "ERROR: Find failed. Remove() error?" << endl;
	position = L.Find(109);
	if (position!=15)
		cerr << "ERROR: Find failed. Remove() error?" << endl;
	// Delete the first item.
	L.Remove(5, success);
	if (!success)
		cerr << "ERROR: Remove operation failed." << endl;
	// Delete the last item.
	L.Remove(109, success);
	if (!success)
		cerr << "ERROR: Remove operation failed." << endl;
	// Check that really gone.
	position = L.Find(5);
	if (position!=-1)
		cerr << "ERROR: Find operation failed." << endl;
	position = L.Find(109);
	if (position!=-1)
		cerr << "ERROR: Find operation failed." << endl;
	// Check what happens with duplicates.
	L.Remove(15, success);
	if (!success)
		cerr << "ERROR: Remove operation failed." << endl;
	position = L.Find(15);
	if (position!=-1)
		cerr << "ERROR: Find found a duplicate." << endl;
	L.Remove(15, success);
	if (success)
		cerr << "ERROR: Remove operation should have failed." << endl;
	L.Remove(100, success);
	if (success)
		cerr << "ERROR: Remove operation should have failed." << endl;

	{SortedList M;
		M = L;
		LLL = M;
		// Display the items on the list M.
		cerr << "DisplayList( M ): should list 12 items \n  " <<
		  "(10, 35, 50, 80, 101, ..., 108):" << endl;
		DisplayList( M );
		cerr << endl;
	}
	
	// Display the items on the list L.
	cerr << "DisplayList( L ): should list 12 items \n  " <<
	  "(10, 35, 50, 80, 101, ..., 108):" << endl;
	DisplayList( L );
	cerr << endl;

	// See what happens when you try to delete ALL items.
	cerr << "Should go from List Length = 11 down to 0:" << endl;
	for ( int maxLoop=MAXLOOP; ! L.IsEmpty() && maxLoop>0; maxLoop--)
	{
		L.Retrieve(1,dataItem,success);
		if (!success)
		{
			cerr << "ERROR: Retrieve operation failed." << endl;
			break;
		}
		else
		{
			L.Remove(dataItem,success);
			if (!success)
				cerr << "ERROR: Delete operation failed." << endl;
			cerr << "List Length = " << L.Length() << endl;
		}
	}

	// Display the items on the list LLL.
	cerr << endl;
	cerr << "DisplayList( LLL ): should list 12 items \n  " <<
	  "(10, 35, 50, 80, 101, ..., 108):" << endl;
	DisplayList( LLL );

	// ...end extra instructor-supplied tests for grading
	
	// Display the items on the list L.
	cerr << endl << "Next line of output should say: End " << OLA << endl;
	DisplayList( L );

	cerr << "End " << OLA << endl;

	return 0;
} // end main


void DisplayList(SortedList list)
//               IN
{
	ItemType  dataItem;
	bool      success;

	// Display the items on the list.
	int maxLoop=MAXLOOP;
	for (int pos = 1; pos <= list.Length(); pos++)
	{
		list.Retrieve(pos, dataItem, success);
		if (success)
			cerr << "List item #" << pos << " is: " << dataItem << endl;
		else
			cerr << "ERROR: Retrieve operation failed." << endl;
		if (--maxLoop==0)
		{
			cerr << "ERROR: Length() failed." << endl;
			break;
		}
	}
} // end DisplayList

