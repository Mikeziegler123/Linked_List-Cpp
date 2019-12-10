/* Author: Michael Ziegler  Due Date:                      LINKED_LIST
 * 
 * Description: This program manages a dynamically allocated list of students,
 * each with members stored for their first name, last name, and gpa. this 
 * program first reads from a file called "ola7.dat", and dependent on the 
 * preceding letter to that name(a, d), either adds(a) the information to the 
 * linked list, or deletes(d) the information, only recieving the last name, and
 * deleting all of that last name's associated data members within the list. The 
 * program uses an insert(addNode) function to add the new data, a 
 * delete(deleteNode) function to delete the current data, and a printList 
 * function to print to standard output, the current values of the 
 * list(listClass). 
 *    				An example of the input is shown below:
 *	    				    //Adds data:		//Deletes data:
 * 							a			  		d  
 *		  				    Jim Paxton			Paxton
 *		   				    3.0					d
 *		  				    a					Fischer
 *						    Ava Starr
 *		   				    3.5
 *						    a
 *		  				    Jimmy Woo
 *						    3.6
 * Due Date: 11/27/2018 
 */ 	

#include <iostream>
#include <fstream> 
#include <iomanip>
#include <string>
using namespace std;

/*STRUCT DEFINITIONS*/
struct Student
{
	string first;
	string last;
	float gpa;
};
struct Node
{
	Student data;
	Node* next;
};
/*CLASS DEFINITION:*/
class listClass {
    private:
		Node* head;
	public:
		void insertNode(Student);
		void deleteNode(string);
		void printList();
		listClass();
		~listClass();
};
/*MAIN:*/
int main()
{
	listClass myList;
	string first, last, lastNameTarg;
	char op;
	float gpa;
	ifstream infile;
	infile.open("ola7.dat");
	while(!(infile.eof()))
	{
		infile >> op; 
		if(op=='a')
		{
			Student newStudent;
			infile >> first >> last >> gpa;
			newStudent.first = first;
			newStudent.last = last;
			newStudent.gpa = gpa;
			myList.insertNode(newStudent);
		}
		else if(op=='d')
		{
			infile >> lastNameTarg;
			if(infile)
				myList.deleteNode(lastNameTarg);
		}
		else
		{
			cout << "\nInput Error\n";
		}
	}
	myList.printList();
	
return 0;
}/*endMain*/

/*CLASS FUNCTION DEFINITIONS*/
//CONSTRUCTOR
listClass::listClass()
{
	head = nullptr;
}

//DESTRUCTOR
listClass::~listClass()
{
	Node* d = new Node;
	d = head;
	while(!(head==nullptr))
	{
		head = head->next;
		delete d;
		d = head;
	}
}

//INSERT NODE
void listClass::insertNode(Student newStu)
{
	Node* prev;
	Node* cur;
	Node* newData = new Node;
	cur = head;
	prev = nullptr;
	
	newData = new Node;
	newData->data.first = newStu.first;
	newData->data.last = newStu.last;
	newData->data.gpa = newStu.gpa;
	newData->next = nullptr;
	
	if((head == nullptr)||(head->data.last >= newData->data.last))
	{
		newData->next = head;
		head = newData;
	}
	else
	{
		cur = head;
		while((cur->next != nullptr)&&(cur->next->data.last < newData->data.last))
		{
			prev = cur;
			cur = cur->next;
		}	
		newData->next = cur->next;
		cur->next = newData;
	}
}
//DELETE NODE 
void listClass::deleteNode(string target)
{
	Node* prev;
	Node* cur;
	
	cur = head;
	prev = nullptr;
	
	if(!head)
	{
		return;
	
	if(head->data.last==target)
	{
		cur = cur->next;
		delete head;
		head = cur;
	}
	}
	else
	{
		cur = head;
		while((cur != nullptr)&&(cur->data.last != target))
		{
			prev = cur;
			cur = cur->next;
		}
		if(cur)
		{
			prev->next = cur->next;
			delete cur;
			cur = nullptr;
		}
		else
		{
			cout << target << " is not in the list\n";
		}
	}
}
//PRINT LIST
void listClass::printList()
{
	Node* p = head;
	cout << "The list of names is\n";
	while(p!=nullptr)
	{
		cout << p->data.last << ", " << p->data.first << " GPA " << p->data.gpa << endl;
		p = p->next; 
	}
}/*endClassFunctions*/
