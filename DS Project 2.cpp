// Asav Bhakta
// Project 2

#include <iostream>
#include <ctime>
using namespace std;

class Linkedlist
{
private: // Private vriabels 

	int top ;
	int random = 0;
	int check[25]; // array to check if it generate the same random numbers 
	int list[25][3];
	
	// variabels for keeping track of index;
	int j = 0;
	int a = 2;
	int z = 1;

public: 
	Linkedlist() // will set top to -1 
	{
	
		top = -1;
	}

	bool empty() // check if stack is empty or not
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void push(int value) // will push the values in stack
	{
		
		srand(time(0));

		random = rand() % 25; // will generate random numbers up to 25
		check[j] = random; // will add that random number into array for checking 

		for (int i = 0; i < j; i++) // this loop will check if random number is repeated or not 
		{
			if (check[i] == random)
				{
					random = rand() % 25;
					check[j] = random;

					i = 0;
				}
		}

		list[random][0] = random; // will show the index
		list[random][1] = value; // value in that index
		list[random][2] = top;  // next index
		top = random; // top will set to index
		
		j++; // this variabel will keep track of how many time push function is executed 
		
	}

	void MyTop() // will display the top value 
	{
		if (top != -1) 
		{
			cout << "the top value is: " << top << endl;
		}
		else
		{
			cout << "Stack is Empty!";
		}
	}
	
	void pop() // will pop the value 
	{
		if (top != -1)
		{
			// will set index, value, and next index to -1
			list[top][0] = -1;
			list[top][1] = -1;
			list[top][2] = -1;

			// will set the check value to -1 so the loop cannot find it. 
			check[j] = -1;

			top = check[j-a]; // will set the top value to old index
		
			a++;  
			z++;

			cout << "Pop function was executed now  " << endl;
			MyTop(); // top function wiil be executed
		}

		else
		{
			cout << "no elements in stack";
		}
	
	}

	void display() // will display 
	{
					// row will be set to how many time push have executed minus the amount of time pop has been executed 
			for (int row = j-z; row >= 0 ; row -- ) // nested loop to display elements in stack 
			{
				for (int column = 0; column<3; column++)
					{
						cout << list[check[row]][column] << "\t";
						if (column == 2)
						cout << endl;
					}
			}
			cout << endl;
	}

	


};

int main() // main function 
{
	Linkedlist list;

	list.push(1);
	list.push(2);
	list.push(3);
	list.push(4);
	list.push(5);
	list.push(6);
	list.push(7);
	list.push(8);
	list.push(9);
	list.push(10);

	list.display();

	list.push(20);
	list.display();
	list.push(30);
	list.display();
	list.push(40);
	list.display();

	list.MyTop();
	list.pop();
	list.display();

	list.MyTop();
	list.pop();
	list.display();

	list.MyTop();
	list.pop();
	list.display();


}