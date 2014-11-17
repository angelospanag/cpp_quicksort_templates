#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
void quickSort(std::vector<T> &arr, int left, int right) {
      int i = left, j = right;
      T tmp;
      T pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      }

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

template <typename T>
void printVector(std::vector<T> &aVector)
{
    std::ostream_iterator<T> output(std::cout, " ");
    std::copy(aVector.begin(), aVector.end(), output);
    std::cout << std::endl;
}

int main()
{
    std::vector<int> aVector = {22, 12, 23, 35, 1, 2};
    std::cout << "Vector of integers before quicksort: ";
    printVector(aVector);
    quickSort(aVector, 0, aVector.size()-1);
    std::cout << "Vector of integers after quicksort: ";
    printVector(aVector);
    std::cout << std::endl;

    std::vector<double> aBVector = {12.23, 12.34, 34.53, 56.23, 1.23};
    std::cout << "Vector of doubles before quicksort: ";
    printVector(aBVector);
    quickSort(aBVector, 0, aBVector.size()-1);
    std::cout << "Vector of doubles after quicksort: ";
    printVector(aBVector);
    std::cout << std::endl;

    return 0;
}

