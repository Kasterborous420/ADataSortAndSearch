#pragma once
class CSorter
{
public:
	CSorter();
	~CSorter();

	void bubbleSort(int list[]);
	int selectionSort(int list[], int length);
	int insertionSort(int list[], int length);

};

