#ifndef STUDENTQEUE_H
#define STUDENTQEUE_H

#include <iostream>

template <class data>
class StudentQeue
{
	public:
		StudentQeue();
		~StudentQeue();
		bool isEmpty();
		void enqueue(data dataook);	
		void dequeue(); 
		int    queueLength() const;
		void Display();
	private:
		class studentNode{
			public:					
					data dataBook;
					studentNode *next;					
		};
	typedef studentNode * NodePointer;
	NodePointer front , rear;
	int counter;	
};

#include "StudentQeue.cpp"
#endif
