// ID:  SLC.h / Header file for the class SortedList
// RCS:  $Revision$
// AUTHOR:  CSCI 2170 UNTCH
// INSTALLATION:  MTSU
// REMARKS:  Class and type definitions for the SortedList.
//   Items are in strict ascending order; duplicates are not allowed.
//   Simple array-based list implementation.

// ID:  SLC.h / Header file for the class SortedList
#ifndef SLC_h_  // To prevent problems from multiple inclusions
#define SLC_h_


typedef int ItemType;     // data type of list items


class SortedList
{
public:

	// Constructors and Destructor:

	SortedList();                           // (default) constructor
	SortedList(const SortedList& listArg);  // copy constructor
	~SortedList();                          // destructor


	// List Operations:

	bool IsEmpty() const;
	// Determines whether a sorted list is empty.
	// Pre:  None.
	// Post: Returns true if list is empty, otherwise returns false.

	int Length() const;
	// Returns the number of items that are in a sorted list.
	// Pre:  None.
	// Post: Returns the number of items currently on the list.

	void Insert(ItemType newItem, bool& success);
	//          IN                OUT
	// Inserts newItem into its proper sorted position in a sorted 
	// list.  Duplicates are not allowed and attempts to insert
	// duplicates should be unsuccessful.  The success flag indicates
	// whether the insertion was successful.
	// Pre:  newItem is defined.
	// Post: If insertion is successful, newItem is in its proper
	//   sorted position in the list and success is true; otherwise 
	//   success is false.  

	void Remove(ItemType anItem, bool& success);
	//          IN               OUT
	// Deletes anItem from a sorted list.  The success flag indicates
	// whether the deletion was successful.
	// Pre:  anItem is defined.
	// Post: If anItem was in the sorted list, it is removed and
	//   success is true; otherwise success is false.

	int Find(ItemType anItem) const;
	//       IN
	// Returns the position (in the range 1<= position<= Length()) where
	// anItem exists in a sorted list or -1 if anItem is not in the list.
	// Pre:  anItem is defined.
	// Post: Returns the position in the sorted list where anItem resides
	//   or -1 if anItem is not in the sorted list.
	//   The item anItem and the list are unchanged.

	void Retrieve(int position, ItemType& dataItem, bool& success) const;
	//            IN            OUT                 OUT
	// Sets dataItem to the item at "position" of the sorted list.
	// The success flag indicates whether the retrieval was successful.
	// Pre:  position is defined and is the number of the item to be retrieved.
	// Post: If 1 <= position <= Length(), then dataItem is the value
	//   of the desired item and success is true; otherwise success is
	//   false.  The list is left unchanged by this operation.


private:
	const static int MAX_LIST = 20; // maximum length of list

	ItemType  list[MAX_LIST];   // array of list items
	int       size;             // number of items on list

	int locatePosition(ItemType anItem, bool& isPresent) const;
	//                 IN               OUT
	// Returns the position where anItem belongs or exists in a sorted
	// list.  The isPresent flag indicates whether anItem is currently
	// in the list.
	// Pre:  anItem is defined.
	// Post: Returns the position in the sorted list where anItem resides
	//   or, if anItem is not in the sorted list, where it would be if
	//   inserted into the list;  the position lies in the range
	//   1 <= position <= Length()+1.  If anItem exists
	//   in the list, isPresent is true; otherwise isPresent is false.
	//   The item anItem and the list are unchanged.

}; // end SortedList class

#endif
