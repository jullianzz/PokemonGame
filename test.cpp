#include <iostream>
#include <list>
#include <iterator>
using namespace std; 

int main()
{
	struct node {
		int data; //put type here 
		node* next;
	};

	node* n; 
	node* t;
	node* h;
	node* p;

	//initialize linked list
	n = new node;
	n->data = 1;
	t = n;
	h = n;

	n = new node;
	n->data = 2;
	t->next = n;// connect two data points
	t = t->next;// makes tail node the last existing node

	n->next = NULL;

	//traversing linked list
	//p = traversal pointer
	p = new node; 
	p = h;
	while (p != NULL)
	{
		// cout << p->data << endl;
		p = p->next; 
	}

	



	list<int> myList(5,0); // initialize linked list
	list<int>::iterator it = myList.begin();
	advance(it, 2); //advances iterator 2 steps forward **NOT to the 3rd element
	// it++ ; //this method also advances iterator by single step
	advance(it, 2); 
	*it = 10; // {0, 0, 0, 10, 0} Changes value of list

	//cout << myList.size() << endl;

	for(it = myList.begin(); it != myList.end(); it++)
	{
		cout << *it << endl;
	}


// 	//traversing list
// 	list<int>::iterator outputIt;
// 	for(outputIt = myList.begin(); outputIt != myList.end(); outputIt++)
// 	{
// 		//cout << *outputIt << endl;
// 	}




// 	//inserting elements
// 	list<int>::iterator insertIt = myList.begin();
// 	advance(insertIt, 2);
// 	myList.insert(insertIt, 11); //inserts term right before where iterator points to

// 	for(outputIt = myList.begin(); outputIt != myList.end(); outputIt++)
// 	{
// 		cout << *outputIt << endl;
// 	}
// cout << endl;



// 	//removing elements
// 	myList.erase(insertIt); //erases the terms iterator points at
// 	int s = 0;

// 	for(outputIt = myList.begin(); outputIt != myList.end(); outputIt++)
// 	{
// 		cout << s << ": " ;
// 		s++;
// 		cout << *outputIt << endl;
// 	}






	return 0;
}