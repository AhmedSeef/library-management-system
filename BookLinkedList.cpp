#include "BookLinkedList.h"
using namespace std;

#ifndef BookLinkedList_IMPL__
#define BookLinkedList_IMPL__

//constructor
template <class key, class data>
BookLinkedList<key,data>::BookLinkedList()
{
	head = NULL;cursor=NULL; prev=NULL;
}

//destructor
template <class key, class data>
BookLinkedList<key,data>::~BookLinkedList()
{
}

//check list empt
template <class key, class data>
bool BookLinkedList<key,data>::listIsEmpty() const{
	return(head==NULL);
}

//check cursor empty
template <class key, class data>
bool BookLinkedList<key,data>::curIsEmpty() const{
	return(cursor==NULL);
}

//move cursor to first == head
template <class key, class data>
void BookLinkedList<key,data>::toFirst(){
	cursor = head;
}

//check cursor if at first == head
template <class key, class data>
bool BookLinkedList<key,data>::atFirst() const{
	return(cursor==head);
}

//make prev equal cursor,and move cursor to its next
template <class key, class data>
void BookLinkedList<key,data>::advance(){
	prev = cursor;
	cursor = cursor->next;
}

//move cursor to end element
template <class key, class data>
void BookLinkedList<key,data>::toEnd(){
	toFirst();
	if(!listIsEmpty())
	while(cursor->next != NULL)
	advance();
}

// check if cursor at end its next == null
template <class key, class data>
bool BookLinkedList<key,data>::atEnd() const{
	return (cursor->next==NULL);
}

//return list count 
template <class key, class data>
int BookLinkedList<key,data>::listSize() const{
	NodePointer q; 	int counter = 0;
	q = head;	
	if (!listIsEmpty())
	while ( q != NULL) 
	{
		q  = q  ->next;
		counter++;
	}	
	return counter;
}


//add in first 
template <class key, class data>
void BookLinkedList<key,data>::insertFirst (const key &keybook, const data &databook ){
	NodePointer newp;
	newp = new bookNode;
	newp->keyBook = keybook;
	newp->dataBook= databook;
	
	newp->next = head;  	
	head = newp; 
}

//add in last 
template <class key, class data>
void BookLinkedList<key,data>::insertEnd (const key &keybook, const data &databook ){
	NodePointer newp;
	newp = new bookNode;
	newp->keyBook = keybook;
	newp->dataBook= databook;
	newp->next = NULL;	
	toEnd();
	cursor->next = newp;
	cursor = newp;
}

//insert in any position expect first
template <class key, class data>
void BookLinkedList<key,data>::insertNode(int position,const key &keybook, const data &databook){
		NodePointer newp;
		newp = new bookNode;
		newp->keyBook = keybook;
		newp->dataBook= databook;
		toFirst();
		if(!listIsEmpty())		
		for(int i=0;i<position-1;i++){
			advance();
		}
		
		prev->next = newp;
		newp->next = cursor;	
}

//delete ifirst elemnt
template <class key, class data>
void BookLinkedList<key,data>::deleteFirst(){
	if(!listIsEmpty())
		{
			NodePointer p;
			p = new bookNode;
			p = head;
			head = head->next;		
			delete p;
		}
		
		else{
			cout << " no book in list";
		}
}

//delete from last
template <class key, class data>
void BookLinkedList<key,data>::deleteEnd(){
		NodePointer pdel;		
		toFirst();
		if(!listIsEmpty())
		{
			toEnd();
			pdel = cursor;
			delete pdel;
			prev->next = NULL;
		}
		else{
			cout << " no book in list";
		}					
}

//delete by position expect first elemnt head
template <class key, class data>
void BookLinkedList<key,data>::deleteNode(const key &keybook){
		NodePointer pdel;		
		toFirst();
		if(!listIsEmpty())
		{
			while(cursor->keyBook!=keybook){
			advance();			
		}
			pdel = cursor;
			if(pdel != NULL){
				prev->next = cursor->next;
				delete pdel;
			}
			else{
				cout <<"no item with this key";
			}
			
		}
		else{
			cout<< " No books to delete";
		}
}
		
								


//check if book in list
template <class key, class data>
bool BookLinkedList<key,data>::search(const key keybook){
	bool found = false;
	toFirst();
	while(head!=NULL){
		if(head->keyBook != keybook){
			head=head->next;
		}
		else{
			found = true;
			return found;
		}
	}	
	return found;
}


//display details
template <class key, class data>
void BookLinkedList<key,data>:: displayDetails(const key  keybook){
	
	if(!search(keybook)){
		cout << "Not Found";
	}
	else{
		
		NodePointer pdisplay;		
		toFirst();
		if(!listIsEmpty())
		while(cursor->keyBook!=keybook){
			advance();
		}
		
		pdisplay = cursor;
		cout<<"the details of " <<pdisplay->keyBook<<endl;
		cout<<"key  :" <<pdisplay->keyBook <<"  "<< " data Book :"<<pdisplay->keyBook ;
	}
		
}

//display all node elements
template <class key, class data>
void BookLinkedList<key,data>::display(){
	NodePointer first = head;
	int index = 0;
	if(!listIsEmpty()){
		while(first != NULL){
		index++;
		cout << index <<" -the key :"<<first->keyBook <<" "<<"the value :"<< first->dataBook <<endl;
		first = first->next;
	}	
}
	
	else{
		cout <<"No item to show"<<endl;
	}
}
	


#endif
