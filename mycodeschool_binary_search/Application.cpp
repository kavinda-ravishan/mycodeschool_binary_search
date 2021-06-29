#include <iostream>

template <typename T>
int Search(T* arr, unsigned int size, T value) {

	for (int i = 0; i < size; i++) {

		if (arr[i] == value) return i;
	}
	return -1;
}

template <typename T>
int SearchBin(T* arr, unsigned int size, T value) {

	int start = 0, end = size - 1, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (arr[mid] == value) return mid;
		else if (value < arr[mid]) end = mid - 1;
		else start = mid + 1;
	}

	return -1;
}

template <typename T>
int SearchBin(T* arr, T value, int start, int end) {

	if (start > end) return -1;
	
	int mid = (start + end) / 2;

	if (arr[mid] == value) return mid;
	else if (value < arr[mid]) return SearchBin(arr, value, start, mid - 1);
	else return SearchBin(arr, value, mid + 1, end);

}

template <typename T>
int SearchBinRec(T* arr, unsigned int size, T value) {

	int start = 0, end = size - 1;

	return SearchBin<T>(arr, value, start, end);
}

template <typename T>
int SearchBinFO(T* arr, unsigned int size, T value) {

	int start = 0, end = size - 1, result = -1, mid;

	while (start <= end) {

		mid = (start + end) / 2;

		if (arr[mid] == value) {
			result = mid;
			end = mid - 1;
		}
		else if (arr[mid] > value) end = mid - 1;
		else start = mid + 1;
	}

	return result;
}

template <typename T>
int SearchBinLO(T* arr, unsigned int size, T value) {

	int start = 0, end = size - 1, result = -1, mid;

	while (start <= end) {

		mid = (start + end) / 2;

		if (arr[mid] == value) {
			result = mid;
			start = mid + 1;
		}
		else if (arr[mid] > value) end = mid - 1;
		else start = mid + 1;
	}

	return result;
}

template <typename T>
int SearchBinFO(T* arr, unsigned int size, T value, int start, int end) {

	int result = -1, mid;

	while (start <= end) {

		mid = (start + end) / 2;

		if (arr[mid] == value) {
			result = mid;
			end = mid - 1;
		}
		else if (arr[mid] > value) end = mid - 1;
		else start = mid + 1;
	}

	return result;
}

template <typename T>
int SearchBinLO(T* arr, unsigned int size, T value, int start, int end) {

	int result = -1, mid;

	while (start <= end) {

		mid = (start + end) / 2;

		if (arr[mid] == value) {
			result = mid;
			start = mid + 1;
		}
		else if (arr[mid] > value) end = mid - 1;
		else start = mid + 1;
	}

	return result;
}

struct FLI
{
	int last, first;

	FLI(int last, int first):last(last),first(first){}
};

template <typename T>
FLI SearchBinFLO(T* arr, unsigned int size, T value) {

	int start = 0, end = size - 1, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (arr[mid] == value) {
			return FLI(SearchBinLO(arr, size, value, start, end), SearchBinFO(arr, size, value, start, end));
		}
		else if (value < arr[mid]) end = mid - 1;
		else start = mid + 1;
	}

	return FLI(-1, -1);
}

int main(int argc, char** args) {

	//const unsigned int size = 5;
	//int x[] = { 2,14,32,51,89 };

	//std::cout << Search<int>(x, size, 32) << std::endl;
	//std::cout << SearchBin<int>(x, size, 32) << std::endl;
	//std::cout << SearchBinRec<int>(x, size, 32) << std::endl;

	//int x_2[] = { 2,4,10,10,10,18,20 };
	//std::cout << SearchBinFO<int>(x_2, size_2, 10) << std::endl;
	//std::cout << SearchBinLO<int>(x_2, size_2, 10) << std::endl;

	int x_3[] = { 1,1,3,3,5,5,5,5,5,9,9,11 };
	FLI fli(SearchBinFLO<int>(x_3, sizeof(x_3)/sizeof(x_3[0]), 6));

	std::cout << "( first, last ) : "<<fli.first <<", "<< fli.last << std::endl;
	std::cout << "Number of items : " << (fli.first == -1 ? 0 : (fli.last - fli.first + 1))<< std::endl;


	return 0;
}