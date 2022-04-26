#include <vector>
#include <iostream>
#include <algorithm>

class Sorting{

    private:
        std::vector<int> vec;

    public:
        void buildSorted(int length);
        void buildPartiallySorted(int length);
        void buildReversed(int length);
        void buildRandom(int length);

        void insertionSort(int length); //1
        void quickSort(int length, int lo, int hi);   //2
        void mergeSort(int length, int *aux, int lo, int hi);   //3
        void radixSort(int length); //4
        void printList(int length);
        void clearVector();

        int partition(int lo, int hi);
        void merge(int length, int *aux, int lo, int mid, int hi);

};




//User is going to be able to select which sorting algorithm they want by choosing a number 1-4. 5 will be the quit function.

//Next, the user will select a type of vector to sort. Sorted, unsorted, reversed, random.

