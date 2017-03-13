// Asav Bhakta
// Bonus Project

#include <iostream>
#include <ctime>
using namespace std;

class Queue
{
private: // Private vriabels 

	int Front; 
	int Back;
	int Next = -1;

	int check[25]; // array to check if it generate the same random numbers 
	int list[25][3];
	
	// variabels for keeping track of index;
	int j = 0;
	int a = 0;
	int z = 0;

	

public: 
	Queue() // will set Front and Back to -1 
	{
	
		Front = -1;
		Back = -1;
	}

	bool Empty() // check if queue is empty or not
	{
		if (Front == Back)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void Enqueue(int value) // will push the values in queue
	{
		
		srand(time(0));

			Back = rand() % 25; // will generate random numbers up to 25
			check[j] = Back; // will add that random number into array for checking 

			for (int i = 0; i < j; i++) // this loop will check if random number is repeated or not 
			{
				if (check[i] == Back)
				{
					Back = rand() % 25;
					check[j] = Back;

					i = 0;
				}
			}
			
		

			list[Back][0] = Back; // will show the index
			list[Back][1] = value; // value in that index
			list[Back][2] = Next;
			Next = Back; // next will set to back
		
		if (j == 0) // Front will be set to back for the first time 
		{
			Front = Back;
		}

		j++; // this variabel will keep track of how many time Enqueue function is executed 
		
	}

	void MyFront() // will display the Front value 
	{
		if (Front != -1) 
		{
			cout << "The Front value is: " << Front << endl;
		}
		else
		{
			cout << "Stack is Empty!";
		}
	}
	
	void Dequeue() // will Dequeue the value 
	{
		if (Front != -1)
		{
			// will set index, value, and next index to -1
			list[Front][0] = -1;
			list[Front][1] = -1;
			list[Front][2] = -1;

			// will set the check value to -1 so the loop cannot find it. 
			check[j] = -1;

			Front = check[a+1]; // will set the Front value to new index
		
			a++;  
			z++;

			cout << "Dequeue function was executed now  " << endl;
			MyFront(); // MyFront function wiil be executed
		}

		else
		{
			cout << "no elements in queue";
		}
	
	}

	void display() // will display 
	{
					// row will be set to 0 plus z (the times dequeue is executed) 
		for (int row = 0 + z ; row < j ; row++) // nested loop to display elements in queue 
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
	Queue list;

	list.Enqueue(1);
	list.Enqueue(2);
	list.Enqueue(3);
	list.Enqueue(4);
	list.Enqueue(5);
	list.Enqueue(6);
	list.Enqueue(7);
	list.Enqueue(8);
	list.Enqueue(9);
	list.Enqueue(10);

	list.display();


	list.Enqueue(20);
	list.display();
	list.Enqueue(30);
	list.display();
	list.Enqueue(40);
	list.display();

	list.MyFront();
	list.Dequeue();
	list.display();

	list.MyFront();
	list.Dequeue();
	list.display();

	list.MyFront();
	list.Dequeue();
	list.display();

}