#include <iostream>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;

clock_t begin, end;
bool isRunning = true;

int list[] = {  1, 2, 8, 15, 99, 111, 200, 201, 800, 1010, 1500 };

void DisplayList()
{
	cout << "List: ";
	for (int i = 0; i < sizeof(list) / sizeof(int); i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}

int SequentialSearchList(int numToSearch)
{
	bool isFound = false;
	begin = clock();
	for (int i = 0; i < sizeof(list) / sizeof(int); i++)
	{
		if (numToSearch == list[i])
		{
			isFound = true;
			return i;
		}
	}
	if (!isFound)
	{
		return -1;
	}
	end = clock();
}

int BinarySearchList(int numToSearch)
{
	int first = 0;
	int last = (sizeof(list) / sizeof(int)) - 1;
	int mid;
	bool isFound = false;

	begin = clock();
	while (first <= last)
	{
		mid = (first + last) / 2;

		if (list[mid] == numToSearch)
		{
			return mid;
			isFound = true;
			break;
		}
		else if (list[mid] > numToSearch)
		{
			last = mid - 1; //search first half
		}
		else 
			first = mid + 1; //search second half
	}

	if (!isFound)
	{
		return -1;
	}
	end = clock();
}

void RemoveNumber(int index)
{
	int last = sizeof(list) / sizeof(int) - 1;

	for(int i = index; i < last; i++)
	{
		list[i] = list[i + 1];
	}
	list[last] = NULL;
}

void AddNumber(int num)
{
	 int index = sizeof(list) / sizeof(int) - 1;

	 list[index] = num;

	DisplayList();
}

void Exercise1()
{	
	cout << "This is Sequential Search" << endl;
	cout << endl;

	DisplayList();

	int num, index;
	
	cout << "Please enter the number you wish to find" << endl;
	cin >> num;

	index = SequentialSearchList(num);
	if (index != -1)
	{
		cout << "Number found at list index: " << index << endl;
	}
	else
	{
		cout << "Number Not Found" << endl;
	}

	cout << "Time Taken for Sequential Search" << float(end - begin) / CLOCKS_PER_SEC << endl;
} 

void Exercise2()
{
	cout << "This is Binary Searching" << endl;
	cout << endl;

	DisplayList();

	int num, index;

	cout << "Please Enter the number you wish to find" << endl;
	cin >> num;

	index = BinarySearchList(num);

	if (index != -1)
	{
		cout << "Number found at list index: " << index << endl;
	}
	else
	{
		cout << "Number Not Found" << endl;
	}

	cout << "Time Taken for Binary Search" << float(end - begin) / CLOCKS_PER_SEC << endl;
}

void Extra1()
{
	cout << "This is Removing an Item from a list" << endl;
	cout << endl;

	DisplayList();
	int num;

	cout << "Choose a number from the list to remove" << endl;
	cin >> num;

	int index = SequentialSearchList(num);

	if (index != -1)
	{
		RemoveNumber(index);
	}
	else
	{
		cout << "Number Not Found" << endl;
	}

	DisplayList();
}

void Extra2()
{
	cout << "This is Adding an Item to a list" << endl;
	cout << endl;

	DisplayList();
	int num;
	bool full;
	cout << "Choose a number  to add to the list" << endl;
	cin >> num;

	int index = SequentialSearchList(num);

	if (index != -1)
	{
		cout << "Number Already in the List! Please use a unique Number" << endl;
	}
	else
	{
		for (int i = 0; i < (sizeof(list) / sizeof(int)); i++)
		{
			if (list[i] == 0)
			{
				AddNumber(num);
				full = false;
				break;
			}
			else
			{
				full = true;
			}
		}
	}
	if (full)
	{
		cout << "Array is Full" << endl;
	}
}

void Exit()
{
	isRunning = false;
}
void main()
{
	int choice;

	
	while (isRunning)
	{
		cout << "Choice of Exercise" << endl;
		cout << "1. Exercise 1" << endl;
		cout << "2. Exercise 2" << endl;
		cout << "3. Extra 1" << endl;
		cout << "4. Extra 2" << endl;
		cout << "5. Exit App" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			Exercise1();
			break;
		case 2:
			Exercise2();
			break;
		case 3:
			Extra1();
			break;
		case 4:
			Extra2();
			break;
		case 5:
			Exit();
			break;
		}
		system("pause");
		system("cls");
	}
}