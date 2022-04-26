#include <iostream>
#include <algorithm>
#include "Algs.h"
#include "time.h"
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>


void Sorting::buildSorted(int length) {
    for(unsigned int i = 0; i < length; i++) {
        this->vec.push_back(i);
    }
}

void Sorting::buildPartiallySorted(int length) {

    for(unsigned int i = 0; i < length; i++) {
        this->vec.push_back(i);
    }

    std::random_shuffle(this->vec.begin(), this->vec.end());

    //this creates a partially sorted vector with the middle third sorted and the first and last thirds unsorted
    std::sort(this->vec.begin() + (this->vec.size() / 3), this->vec.end() - (this->vec.size() / 3));

}

void Sorting::buildReversed(int length) {
    for(int i = (length - 1); i >= 0; i--) {
        this->vec.push_back(i);
    }

    // this loop outputs the current vector if we want to check what it looks like before being sorted
    /*for(unsigned int i = 0; i < length; i++) {
        std::cout << this->vec[i] << ' ';
    }
    std::cout << '\n';*/
}

void Sorting::buildRandom(int length) {

    for(int i = (length - 1); i >= 0; i--) {
        this->vec.push_back(i);
    }

    std::random_shuffle(this->vec.begin(), this->vec.end());

}

void Sorting::insertionSort(int length) {
    int temp;
    unsigned int i, j;


    for(i = 0; i < length; i++) {
        for(j = i; j > 0; j--) {
            if (this->vec[j] < this->vec[j - 1]) {
                temp = this->vec[j];
                this->vec[j] = this->vec[j - 1];
                this->vec[j - 1] = temp;
            }
            else {
                break;
            }
        }
    }
}

void Sorting::quickSort(int length, int lo, int hi) {

    if (hi <= lo){
        return;
    }

    int p = partition(lo, hi);

    quickSort(length, lo, p - 1);

    quickSort(length, p + 1, hi);


}

int Sorting::partition(int lo, int hi){

    int i = lo;
    int j = hi + 1;

    while(1){

        while(this->vec[++i] < this->vec[lo]){
            if(i == hi){
                break;
            }
        }

        while(this->vec[lo] < this->vec[--j]){
            if(j == lo){
                break;
            }
        }

        if(i >= j){
            break;
        }

        std::swap(this->vec[i], this->vec[j]);

    }

    std::swap(this->vec[lo], this->vec[j]);

    return j;
}




void Sorting::mergeSort(int length, int *aux, int lo, int hi) {
    if (hi <= lo){
        return;
    }
    int mid = lo + (hi - lo) / 2;
    mergeSort(length, aux, lo, mid);
    mergeSort(length, aux, mid+1, hi);
    merge(length, aux, lo, mid, hi);
}

void Sorting::merge(int length, int *aux, int lo, int mid, int hi){
    int a[length];
    for (int l = 0; l < length; l++) {
        a[l] = this->vec[l];
    }
    std::memcpy(aux + lo, a + lo , (hi-lo+1) * sizeof(int));
    int i = lo, j = mid + 1;
    for (int k = lo ; k <= hi; k++){
        if (i > mid){
            this->vec[k] = aux[j++];
        }
        else if (j > hi) {
            this->vec[k] = aux[i++];
        }
        else if (aux[j] < aux[i]) {
            this->vec[k] = aux[j++];
        }
        else{
            this->vec[k] = aux[i++];
        }
    }
}



void Sorting::radixSort(int length){
    int i, j, max=1, total, digit, counter[10], prefix[10], output[length], place, intlen;
    std::stringstream ss;
    std::string integer;
    char digitS;
    //J counts position in integer
    for(j=0;j<max;j++){
        for(i=0;i<10;i++){
            counter[i] = 0;
        }
        for(i=0;i<length;i++){
            //turns int to string
            ss.str("");
            ss<<this->vec[i];
            integer = ss.str();
            //std::cout<<"int: "<<integer<<" | ";
            //define max
            if(integer.length()>max){
                //std::cout<<" | length: "<<integer.length()<<"\n";
                max = integer.length();
            }
            if(integer.length()<max && integer.length()<j+1){
                digit = 0;
            } else {
                //focuses on specific digit
                digitS = integer[integer.length()-j-1];
                //std::cout<<"len: "<<integer.length()-max<<" | S: "<<digitS;
                digit = (int)digitS-48;
            }
            //std::cout<<"digit: "<< digit<<"\n";
            //increments counter array
            counter[digit]++;

        }
        total = 0;
        for(i=0;i<10;i++){
            //std::cout<<"counter: "<<counter[i];
            total += counter[i];
            prefix[i] = total;
            //std::cout<<" | prefix: "<< total<< "\n";
        }
        for(i=length-1;i>=0;i--){
            ss.str("");
            //turns int to string
            ss<<this->vec[i];
            integer = ss.str();
            //focuses on specific digit
            if(integer.length()<max && integer.length()<j+1){
                digit = 0;
            } else {
                //focuses on specific digit
                digitS = integer[integer.length()-j-1];
                //std::cout<<"len: "<<integer.length()-max<<" | S: "<<digitS;
                digit = (int)digitS-48;
            }
            prefix[digit]--;
            place = prefix[digit];
            output[place] = this->vec[i];
        }
        for(i=0;i<length;i++){
            this->vec[i] = output[i];
        }
        //this->printList(length);
        //std::cout<<"\n";
    }
}





void Sorting::printList(int length) {
    for(unsigned int i = 0; i < length; i++) {
        std::cout << this->vec[i] << ' ';
    }
    std::cout << '\n' << '\n';
}

void Sorting::clearVector() {
    this->vec.clear();
}
