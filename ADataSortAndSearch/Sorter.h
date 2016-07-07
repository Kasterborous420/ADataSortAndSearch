#pragma once
class CSorter
{
public:
	CSorter();
	~CSorter();

	void bubbleSort(int list[]);
	void selectionSort(int list[]);
	void insertionSort(int list[]);

	int minLocation(int list[], int loc, int length);
	void swap(int list[], int loc, int minIndex);

};

