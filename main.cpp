#include <iostream>
#include "Algs.h"
#include <vector>
#include <algorithm>
#include <iomanip>

// to run: g++ main.cpp Algs.cpp -o main && ./main

int main() {

    int vec_type;                  // the type of sort
    int sort_algorithm;             // algorithm that is being used
    int input_length;               //input_length is the length of the vector being filled and sorted
    int vecType = 1;                //vecType is an integer that represents a type of list. Sorted, unsorted, reversed, random
    Sorting Object;     // initialize class called sort


    while(vecType != 0) {             //enter while loop, 0 is to quit. Got to be sure to empty the vector at the end of the loop
        std::cout << "1 = Sorted" << std::endl;
        std::cout << "2 = Partially Sorted" << std::endl;
        std::cout << "3 = Reversed" << std::endl;
        std::cout << "4 = Random" << std::endl;
        std::cout << "0 = Exit" << std::endl;
        std::cout << std::endl;

        std::cout << "What kind of list do you want to sort (enter 1, 2, 3, 4, 0)? ";
        std::cin >> vecType;
        std::cout << '\n';
        if (vecType != 0) {
            std::cout << "--------------------------------------------------------------------------------------------" << '\n' << '\n';;
        }

        if (vecType == 1){                                                              //SORTED
            std::cout << "Enter the length of your list: ";
            std::cin >> input_length;
            std::cout << '\n' << "--------------------------------------------------------------------------------------------" << '\n' << '\n';;

            Object.buildSorted(input_length);       // call function that creates the sorted vector passing in the original vector and the inputted length

            std::cout << "1 = Insertion Sort" << std::endl;
            std::cout << "2 = Quick Sort" << std::endl;
            std::cout << "3 = Merge Sort" << std::endl;
            std::cout << "4 = Radix Sort" << std::endl;                       //figure this out after all three other algorithms are complete
            std::cout << '\n';

            std::cout << "Which sorting algorithm do you want? ";
            std::cin >> sort_algorithm;
            std::cout << '\n' << '\n';


            if (sort_algorithm == 1){
                clock_t t;
                t = clock();

                Object.insertionSort(input_length);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The insertion sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 2){
                clock_t t;
                t = clock();

                int lo = 0;
                int hi = input_length - 1;                                          //might need to double check this value. might be input_length -1
                Object.quickSort(input_length, lo, hi);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The quick sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 3){
                clock_t t;
                t = clock();
                int *aux = new int[input_length];
                int lo = 0;
                int hi = input_length;
                Object.mergeSort(input_length, aux, lo, hi);
                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The merge sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 4){
                clock_t t;
                t = clock();

                Object.radixSort(input_length);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The radix sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

        }




        else if (vecType == 2) {                                              //PARTIALLY SORTED

            std::cout << "Enter the length of your list: ";
            std::cin >> input_length;
            std::cout << '\n' << "--------------------------------------------------------------------------------------------" << '\n' << '\n';;

            Object.buildPartiallySorted(input_length);

            std::cout << "1 = Insertion Sort" << std::endl;
            std::cout << "2 = Quick Sort" << std::endl;
            std::cout << "3 = Merge Sort" << std::endl;
            std::cout << "4 = Radix Sort" << std::endl;                       //figure this out after all three other algorithms are complete
            std::cout << '\n';

            std::cout << "Which sorting algorithm do you want? ";
            std::cin >> sort_algorithm;
            std::cout << '\n' << '\n';


            if (sort_algorithm == 1){
                clock_t t;
                t = clock();

                Object.insertionSort(input_length);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The insertion sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 2){
                clock_t t;
                t = clock();

                int lo = 0;
                int hi = input_length - 1;                                          //might need to double check this value. might be input_length -1 THIS IS THE ERROR
                Object.quickSort(input_length, lo, hi);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The quick sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 3){
                clock_t t;
                t = clock();
                int *aux = new int[input_length];
                int lo = 0;
                int hi = input_length;
                Object.mergeSort(input_length, aux, lo, hi);
                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The merge sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 4){
                clock_t t;
                t = clock();

                Object.radixSort(input_length);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The radix sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }
        }

        else if (vecType == 3){                                            //REVERSE SORTED
            std::cout << "Enter the length of your list: ";
            std::cin >> input_length;
            std::cout << '\n' << "--------------------------------------------------------------------------------------------" << '\n' << '\n';
            std::cout << "length: " << input_length << '\n';
            Object.buildReversed(input_length);       // call function that creates the sorted vector passing in the original vector and the inputted length

            std::cout << "1 = Insertion Sort" << std::endl;
            std::cout << "2 = Quick Sort" << std::endl;
            std::cout << "3 = Merge Sort" << std::endl;
            std::cout << "4 = Radix Sort" << std::endl;                       //figure this out after all three other algorithms are complete
            std::cout << '\n';

            std::cout << "Which sorting algorithm do you want? ";
            std::cin >> sort_algorithm;
            std::cout << '\n' << '\n';


            if (sort_algorithm == 1){
                clock_t t;
                t = clock();

                Object.insertionSort(input_length);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The radix sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 2){
                clock_t t;
                t = clock();

                int lo = 0;
                int hi = input_length - 1;                                          //might need to double check this value. might be input_length -1
                Object.quickSort(input_length, lo, hi);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The quick sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 3){
                clock_t t;
                t = clock();
                int *aux = new int[input_length];
                int lo = 0;
                int hi = input_length;
                Object.mergeSort(input_length, aux, lo, hi);
                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The merge sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 4){
                clock_t t;
                t = clock();

                Object.radixSort(input_length);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The radix sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }
        }

        else if (vecType == 4){                                                     //RANDOM SORTED
            std::cout << "Enter the length of your list: ";
            std::cin >> input_length;
            std::cout << '\n' << "--------------------------------------------------------------------------------------------" << '\n' << '\n';
            std::cout << "length: " << input_length << '\n';
            Object.buildRandom(input_length);       // call function that creates the sorted vector passing in the original vector and the inputted length

            std::cout << "1 = Insertion Sort" << std::endl;
            std::cout << "2 = Quick Sort" << std::endl;
            std::cout << "3 = Merge Sort" << std::endl;
            std::cout << "4 = Radix Sort" << std::endl;                       //figure this out after all three other algorithms are complete
            std::cout << '\n';

            std::cout << "Which sorting algorithm do you want? ";
            std::cin >> sort_algorithm;
            std::cout << '\n' << '\n';

            if (sort_algorithm == 1){
                clock_t t;
                t = clock();

                Object.insertionSort(input_length);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The insertion sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 2){
                clock_t t;
                t = clock();

                int lo = 0;
                int hi = input_length - 1;                                          //might need to double check this value. might be input_length -1
                Object.quickSort(input_length, lo, hi);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The quick sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 3){
                // merge sort
                clock_t t;
                t = clock();
                int *aux = new int[input_length];
                int lo = 0;
                int hi = input_length;
                Object.mergeSort(input_length, aux, lo, hi);
                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The merge sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            else if (sort_algorithm == 4){
                clock_t t;
                t = clock();

                Object.radixSort(input_length);

                t = clock() - t;

                Object.printList(input_length);
                std::cout << std::fixed << std::setprecision(4) << "The radix sort algorithm took " << ((double)t)/CLOCKS_PER_SEC << " seconds" << '\n' << '\n';
            }

            //Object.printList(input_length);
        }
        // clear the vector here at the end of the while loop
        Object.clearVector();
    }

    return 0;
} 
