#pragma once
class CSorter
{
public:
	CSorter();
	~CSorter();

	void bubbleSort(int list[]);
	void selectionSort(int list[]);
	void insertionSort(int list[]);
	void quickSort(int list[], int first, int last);
	void mergeSort(int list[], int first, int last);

	int minLocation(int list[], int loc, int length);
	void swap(int list[], int loc, int minIndex);
	int partition(int list[], int first, int last);
	void merge(int list[], int first, int middle, int last);

};

