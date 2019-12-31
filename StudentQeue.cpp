#include "StudentQeue.h"
using namespace std;

#ifndef STUDENTQEUE_IMPEL__
#define STUDENTQEUE_IMPEL__

template <class data>
StudentQeue<data>::StudentQeue()
{
	front = NULL; rear = NULL;
}

template <class data>
StudentQeue<data>::~StudentQeue()
{
}

template <class data>
bool StudentQeue<data>::isEmpty(){
	return (rear==NULL);
}

template <class data>
void StudentQeue<data>::enqueue(data dataook){
	NodePointer pnew = new studentNode; 
	pnew->dataBook = dataook; 
	pnew->next = NULL;
	if(isEmpty()){
		rear = front= pnew;
	} else{
	rear->next = pnew;
	 rear = pnew;
	 }  	
counter++;
}	

template <class data>
void StudentQeue<data>::dequeue(){
	NodePointer pdelete; 	
	if(isEmpty()){
		cout<< "there is no student order"<<endl;
	} else{
	 	
		 pdelete = front;
	 	front = front->next;
	 	delete pdelete;
	 	counter--;
	 }  	

}	


template <class data>
int StudentQeue<data>::queueLength() const{
return counter;
}

template <class data>
void StudentQeue<data>::Display(){
	if(!isEmpty()){
		int index = 0;
		while(front != NULL){
			index++;
			cout << index<<"order: "<< front->dataBook <<endl;
			front = front->next;			
		}
	}
	else{
		cout << "all orders completed"<<endl;
	}
}
#endif
