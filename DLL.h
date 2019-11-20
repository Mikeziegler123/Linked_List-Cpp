// ID:  DLL.h / Header file for the class SortedList
// INSTALLATION:  MIDDLE TENNESSEE STATE UNIVERSITY
// RCS: $Revision$
// REMARKS:  Class and type definitions for the SortedList.
//   Items are in strict ascending order; duplicates are not allowed.
//   Dynamic storage dummy-headed circular singly-linked list implementation.

#ifndef DLL_h_  // To prevent problems from multiple inclusions
#define DLL_h_

typedef int ItemType;     // data type of list items  ItemType-Alias for int.

class SortedList
{
public:

	// Constructors and Destructor:	
	SortedList();                           // (default) constructor
	SortedList(const SortedList& listArg);  // copy constructor
	~SortedList();                          // destructor

	// Overloaded Operator:

	SortedList& operator=(const SortedList& rhs);  // assignment


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
	// list.  Duplicates are not allowed and attempts to 		insert
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
	struct tNode;
	typedef tNode*  tNodePtr;   // pointer to list node
	struct tNode
	{
		ItemType    item;
		tNodePtr    next;
	};

	void copyList(tNodePtr original, tNodePtr duplicate);
	//            IN                 IN
	// Make a deep copy of a list.
	// Pre:  original points to an existing list's dummy node and
	// duplicate points to an existing dummy node that points to itself.
	// Post: duplicate points to a duplicate copy of the "original" list.

	bool locateNode(ItemType anItem, tNodePtr& previous, int& position) const;
	//              IN               OUT                 OUT
	// Returns true if anItem exists in the list, a pointer to the previous
	// (i.e., predecessor) node in the list and and anItem's list position.
	// Returns false if anItem is not in the list and a pointer to what would
	// have been the previous node if anItem had been in the list; the value
	// of position is that of what anItem's would have been if it were in the
	// list.
	// Pre:  anItem is defined.
	// Post: See above.  Note that the value of position lies in the range
	// 1 <= position <= Length()+1. The pointer "previous" points to
	// the last node on the list whose value was less than that of
	// anItem or to the dummy node if the position==1.

	int        size;        // number of items on list.
	tNodePtr   head;        // pointer to the dummy node of the
	                        //   dummy headed circular singly-linked list.

}; // end SortedList class

#endif
