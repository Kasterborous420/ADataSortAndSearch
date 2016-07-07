#include "Sorter.h"


CSorter::CSorter()
{
}


CSorter::~CSorter()
{
}

//======================BUBBLE SORT========================//

void CSorter::bubbleSort(int list[])
{
	int length = sizeof(list) / sizeof(int);
	for (int i = 0; i < length; i++)
	{
		for (int index = 0; index < length - i; index++)
		{
			if (list[index] > list[index + 1])
			{
				//SwappitySwop
				int temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
		}
	}
}

//=========================================================//


//=====================SELECTION SORT======================//

int CSorter::minLocation(int list[], int loc, int length)
{
	//Set Location
	int tempLoc = -1;

	for (; loc < length; loc++)
	{
		//If this is the first iteration
		if (tempLoc == -1)
		{
			//location is set
			tempLoc = loc;
		}
		//not first iteration
		else
		{
			//if the int at index is less than the int at temp
			if (list[tempLoc] > list[loc])
			{
				//replace the location
				tempLoc = loc;
			}
		}
	}
	//return minimum location
	return loc;
}

void CSorter::swap(int list[], int loc, int minIndex)
{
	int temp = 0;

	temp = list[loc];

	list[loc] = list[minIndex];

	list[minIndex] = temp;
}

void CSorter::selectionSort(int list[])
{
	int length = sizeof(list) / sizeof(int);

	int minIndex = 0;

	for (int loc = 0; loc < length; loc++)
	{
		minIndex = minLocation(list, loc, length);
		swap(list, loc, minIndex);
	}
}

//=========================================================//


//=====================INSERTION SORT======================//

void insertionSort(int list[])
{
	int length = sizeof(list) / sizeof(int);

	int loc, temp;

	for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
	{
		//check against previous adjacent element
		if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
		{
			temp = list[firstOutOfOrder];
			loc = firstOutOfOrder; //Init where to start moving back

			while (loc > 0 && list[loc - 1] > temp)
			{
				list[loc] = list[loc -1];
				loc--;
			}
			list[loc] = temp;
		}
	}
}

//=========================================================//

