// Asav Bhakta
// DS project 1 -  Question 2
// Understanding Linked list

#include<iostream>
using namespace std;


int i, j = 0; // global variable for checking 

class node
{
public:
	int data;
	node* next;

	node()
	{
		next = NULL;
	}
};

class PointerList
{
public:
	PointerList()
	{
		top = NULL;
	}

	bool empty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}

	void insert(int position, int element)
	{
	
		node *newptr = new node;
		newptr->data = element;

		if (top == NULL)			//insert the very first element
			if (position == 0)
			{
				newptr->next = NULL;
				top = newptr; 
			}
			else
				cout << "Location Error!!";
		else
			if (position == 0)		//insert on the first position when some elements existed
			{
				newptr->next = top;
				top = newptr;
			}
			else				//most cases belongs to this situation (as showed in the class slide)
			{
				node* preptr = top;

				node* temp2 = top->next;
				
				

					while (preptr->data != position) // loop until the position is not found 
					{
						

						if (preptr->data != position && preptr->next == NULL) // if it is last linked list it will show error
						{
							i = 1;
							cout << "error # " << position << " is not exisited" << endl;
							break;
						}
						
						preptr = preptr->next;
						temp2 = preptr->next;
						
					}

					if (i == 0) // if there is not error this will work 
					{
						newptr->next = temp2;
						preptr->next = newptr;
					}

			}
	}

	void remove(int position)
	{
		if (position == 0)			//delete the first element
		{
			node * ptr = top;
			top = ptr->next;
			delete(ptr);
		}
		else
		{
			node *preptr;
			preptr = top;

			
			while (preptr->data != position) // loop until position is not found 
			{

				if (preptr->data != position && preptr->next == NULL) // for check if data is not in the list 
				{
					j = 1;
					cout << "error # " << position << " is not exisited" << endl;
					break;
				}

				preptr = preptr->next;

			}

			if (j == 0) 
			{
				node * ptr = preptr->next;
				preptr->next = ptr->next;
				delete(ptr);
			}
		}
	}


	void print() // print function 
	{
		node *temp;
		temp = top;
	
			while (temp != NULL)
			{
				cout << temp->data << ",";
				temp = temp->next;
				
			}
		
		
	}

private:
	node *top;
	int stackData;
};

int main() {
	PointerList *sl = new PointerList();

	sl->insert(0, 10);   //current linked list: 10 (default status, when empty)   
	sl->insert(10, 20);	//current linked list: 10->20
	sl->insert(20, 30);	//current linked list: 10->20->30
	sl->insert(20, 40);	//current linked list: 10->20->40->30
	sl->insert(30, 50);	//current linked list: 10->20->40->30->50
	sl->insert(50, 60);	//current linked list: 10->20->40->30->50->60
	sl->insert(5, 70);	//error, no 5 existed in the linked list
	sl->remove(30); 	//current linked list: 10->20->40->30->60
	sl->remove(10);	//current linked list: 10->40->30->60
	sl->remove(50);	//error, no 50 existed in the linked list
	sl->print();

	return 0;
}
