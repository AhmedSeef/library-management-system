#ifndef BOOKLINKEDLIST_H
#define BOOKLINKEDLIST_H

//include prevent "Null Not Defined in this scope"
#include <iostream>


template <class key, class data>
class BookLinkedList
{
	public:
		BookLinkedList();
		~BookLinkedList();
		bool listIsEmpty() const; 
		bool curIsEmpty() const;
		void toFirst(); 
		bool atFirst() const;
		void advance(); 
		void toEnd(); 
		bool atEnd() const;
		int  listSize() const;
		
		void insertFirst (const key &, const data & );
		void insertEnd (const key &, const data & );
		void insertNode(int position,const key &, const data &);
		
		void deleteFirst();	
		void deleteEnd();
		void deleteNode(const key &keybook);
		
		bool search (const key  keyook);
		void displayDetails(const key  keyook); 
		void display();



		

	private:
		class bookNode{
			public:
					key keyBook;
					data dataBook;
					bookNode *next;					
		};
		
		typedef bookNode * NodePointer;
		NodePointer head, cursor, prev,last;
};

#include "BookLinkedList.cpp"
#endif
