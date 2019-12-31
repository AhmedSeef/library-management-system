#include <iostream>

using namespace std;

#include "BookLinkedList.h"
#include "StudentQeue.h"

using namespace std;

//global variable
BookLinkedList<string,string> BLL;
StudentQeue<string> SQ;

//main menu view
void mainmenuviw();

//book views
void bookview();
void addbookview();
	void addfirstbookview();
	void addlastbookview();
	void addwithpositionbookview(); 
void deletebookview();
	 void deletefirstbookview();
	 void deletelastbookview();
	 void deletewithpositionbookview();	 
void showbookview();



//student order views
void studentactionview();
	void studentAddactionview();
	void studentFinishactionview();
	void uncompleteorder();	
void clear();
int main(int argc, char** argv) {
   mainmenuviw();   
	return 0;
}

//application main menu
void mainmenuviw(){
	clear();
	cout<<"*****************************"<<endl;		
		cout<<"1 " << " Book "<<endl;
		cout<<"2 " << " Student Orders"<<endl;			
	cout<<"*****************************"<<endl;
	cout << "choose correct Number to go department"<<endl;
		int choose;
		cin >> 	choose;
	
	if(choose==1){
		bookview();
	}
	else if(choose==2){
		studentactionview();
	}
	else{
		clear();
		mainmenuviw();
	}
}

//start main menu for books view
void bookview(){
	clear();
	cout<<"*****************************"<<endl;		
		cout<<"1 " << " Add Book "<<endl;
		cout<<"2 " << " Delete Book "<<endl;
		cout<<"3 " << " view Books "<<endl;			
	cout<<"*****************************"<<endl;
	
	cout << "click Number to go Action or click 0 to go home"<<endl;
	int choose;
	cin >> 	choose;
	if(choose==0){
		mainmenuviw();
	}
	else if(choose==1){
		addbookview();
	}
	else if(choose==2){
		deletebookview();
	}
	
	else if(choose==3){
		showbookview();
	}
	else{
		cout<<"choose correct number";
	}
	
}	
//End main menu for books view

/////////////Start Add book view with all methods///////////////	
void addbookview(){
	clear();
	cout<<"*****************************"<<endl;		
		cout<<"1 " << " Add in first "<<endl;
		cout<<"2 " << " add in last "<<endl;
		cout<<"3 " << " add in specific position "<<endl;			
	cout<<"*****************************"<<endl;
	
	cout << "click Number to go Action or click 0 to go book view"<<endl;
	int choose;
	cin >> 	choose;
	if(choose==0){
		bookview();
	}
	else if(choose==1){
		addfirstbookview();
	}
	else if(choose==2){
		addlastbookview();
	}
	
	else if(choose==3){
		addwithpositionbookview(); 
	}
	else{
		cout<<"choose correct number";
	}
	
}
//add in first book
void addfirstbookview(){
	clear();
	int ask= true;
	while(ask == 1){		
	string key,data;
	
	cout << "Enter key Book" <<endl;
	cin >> key;
	
	cout << "Enter name" <<endl;
	cin >> data;
	BLL.insertFirst(key,data);	
	
	cout << "do you want add new book to add click 1 for cancel and go back click 0"<<endl;
	cin >> ask;
	}
	addbookview();
}

// add in last book
void addlastbookview(){
	clear();
	int ask= true;
	while(ask == 1){		
	string key,data;
	
	cout << "Enter key Book" <<endl;
	cin >> key;
	
	cout << "Enter name" <<endl;
	cin >> data;
	
	BLL.insertEnd(key,data);
	cout << "do you want add new book to add click 1 for cancel and go back click 0"<<endl;
	cin >> ask;
	}
	addbookview();
}

//add in specific position book
void addwithpositionbookview(){
	clear();
	int size = BLL.listSize();
	cout << size<<endl;
	int ask= true;
	while(ask == 1){		
	string key,data;
	int position;
	cout << "Enter key Book" <<endl;
	cin >> key;
	
	cout << "Enter name" <<endl;
	cin >> data;
	
	cout << "Enter position" <<endl;
	cin >> position;
	
	if(position > size){
		BLL.insertEnd(key,data);
	}
	else{
		BLL.insertNode(position,key,data);
	}
	cout << "do you want add new book to add click 1 for cancel and go back click 0"<<endl;
	cin >> ask;
	}
	addbookview();
}
/////////////End Add book view with all methods///////////////


/////////////Start Delete books with all methods////////
void deletebookview(){
	clear();
	cout<<"*****************************"<<endl;		
		cout<<"1 " << " delete in first "<<endl;
		cout<<"2 " << " delte in last "<<endl;
		cout<<"3 " << " delete in specific position "<<endl;			
	cout<<"*****************************"<<endl;
	
	cout << "click Number to go Action or click 0 to go book view"<<endl;
	int choose;
	cin >> 	choose;
	if(choose==0){
		bookview();
	}
	else if(choose==1){
		deletefirstbookview();
	}
	else if(choose==2){
		deletelastbookview();
	}
	
	else if(choose==3){
		deletewithpositionbookview();
	}
	else{
		cout<<"choose correct number";
	}
}

void deletefirstbookview(){
	clear();
	int ask= 1;
	while(ask == 1){
		BLL.deleteFirst();
		BLL.display();
		cout << "do you want to delete book click 1 for cancel and go back click 0"<<endl;
		cin >> ask;
		
	}
	deletebookview();
}

void deletelastbookview(){
	clear();
	int ask= 1;
	while(ask == 1){
		BLL.deleteEnd();
		BLL.display();
		cout << "do you want  to delete book click 1 for cancel and go back click 0"<<endl;
		cin >> ask;
	}
	deletebookview();
}

void deletewithpositionbookview(){
	clear();
	int ask= 1;
	while(ask == 1){
		string key;
		cout << "enter key item to delete" <<endl;
		cin >> key;		
		BLL.deleteNode(key);
		BLL.display();
		cout << "do you want delete book click 1 for cancel and go back click 0"<<endl;
		cin >> ask;
	}
	deletebookview();
	
}

////////////End Delete books with all methods////////

//////////////Start show books details///////////
void showbookview(){
	clear();	
	int ask= 1;
	while(ask == 1){
		BLL.display();
		cout << "do you want  to show data again  click 1 for cancel and go back click 0"<<endl;
		cin >> ask;
		
	}
	bookview();
	
}
/////////////End show books details///////////


//////////////////////////////////////////Student order///////////////////////////////


//Start Student actions/////////////////////////////////////////////////////////
void studentactionview(){
	clear();
	cout<<"*****************************"<<endl;		
		cout<<"1 " << " Add Student order "<<endl;
		cout<<"2 " << " Finsh Student Order "<<endl;
		cout<<"3 " << " view Order not completed "<<endl;					
	cout<<"*****************************"<<endl;
	
	cout << "click Number to go Action or 0 to go home"<<endl;
		int choose;
		cin >> 	choose;
	
	if(choose==0){
		mainmenuviw();
	}
	else if(choose==1){
		studentAddactionview();
	}
	else if(choose==2){
		studentFinishactionview();
	}
	else if(choose==3){
		uncompleteorder();
	}
	else{
		clear();
		studentactionview();
	}
}

//Add student order 
void studentAddactionview(){
	clear();
	int ask = 1;
	while(ask ==1){
	cout << "enter order name"<<endl;
	string ordername;
	cin >> ordername;
	SQ.enqueue(ordername);
	
	int size = SQ.queueLength();
	cout << size<<endl;
	
	cout <<"Do you want add another order enter 1 or click 0 to finish and go back" <<endl;
	cin >>ask;
	}
	studentactionview();
}

//for list of student with un complete order view
void uncompleteorder(){	
	int a = SQ.queueLength();
	clear();	
	SQ.Display();
	cout << "for go back click 0"<<endl;
	
	char ask = 1;
	cin >> ask;
	cout << "press 0 to go back";
	
	if(ask =='1'){
	uncompleteorder();
	}
	else if(ask =='0'){
		studentactionview();
	}
}


void studentFinishactionview(){
	clear();
	int ask = 1;
	while(ask ==1){	
	SQ.dequeue();	
	int size = SQ.queueLength();
	cout << size<<endl;
	
	cout <<"Do you want delete another order enter 1 or click 0 to finish and go back" <<endl;
	cin >>ask;
	}
	studentactionview();
}
//end student Acions /////////////////////
void clear(){
	system("CLS");
}
