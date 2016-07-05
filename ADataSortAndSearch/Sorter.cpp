#include "Sorter.h"


CSorter::CSorter()
{
}


CSorter::~CSorter()
{
}

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

