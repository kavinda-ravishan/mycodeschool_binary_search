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

	int start = 0;
	int end = size - 1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (arr[mid] == value) return mid;
		else if (value < arr[mid]) end = mid - 1;
		else start = mid + 1;
	}

	return -1;
}

int main(int argc, char** args) {

	const unsigned int size = 5;
	int x[7] = { 2,14,32,51,89 };

	std::cout << Search<int>(x, size, 32) << std::endl;
	std::cout << SearchBin<int>(x, size, 32) << std::endl;

	return 0;
}