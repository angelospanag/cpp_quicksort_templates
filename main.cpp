#include <iostream>
#include <vector>
#include <iterator>

//Templated implementation of quicksort
template <typename T>
void quickSort(std::vector<T> &aVector, int left, int right)
{
    int i = left;
    int j = right;

    T tmp;
    T pivot = aVector[(left + right) / 2];

    //Partition step
    while (i <= j)
    {
        //Move left pointer to the right
        while (aVector[i] < pivot)
        {
            i++;
        }

        //Move right pointer to the left
        while (aVector[j] > pivot)
        {
            j--;
        }

        //Swapping step
        if (i <= j)
        {
            tmp = aVector[i];
            aVector[i] = aVector[j];
            aVector[j] = tmp;
            i++;
            j--;
        }
    }

    //Recursion step
    if (left < j)
    {
        quickSort(aVector, left, j);
    }
    if (i < right)
    {
        quickSort(aVector, i, right);
    }
}

//Templated function to print the elements of a vector
template <typename T>
void printVector(std::vector<T> &aVector)
{
    std::ostream_iterator<T> output(std::cout, " ");
    std::copy(aVector.begin(), aVector.end(), output);
    std::cout << std::endl;
}

//Main function
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

