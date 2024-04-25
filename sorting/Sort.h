//
// Created by at991 on 4/23/2024.
//

#ifndef SORTING_SORT_H
#define SORTING_SORT_H

#include <vector>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

template <typename T>
class Sort {
private:
    ofstream file;
public:
    Sort(string file_name) {
        file.open("../" + file_name + ".txt");
    };
    void sort(vector <T> &data, string algo, bool (*func) (const T&, const T&));
    void bubbleSort(vector <T> &data, bool (*func) (const T&, const T&));
    void selectionSort(vector <T> &data, bool (*func) (const T&, const T&));
    void insertionSort(vector <T> &data, bool (*func) (const T&, const T&));
    void shellSort(vector <T> &data, bool (*func) (const T&, const T&));
//    void mergeSort(vector <T> &data, bool (*func) (const T&, const T&));
//    void quickSort(vector <T> &data, bool (*func) (const T&, const T&));
};

template <typename T>
void Sort<T>::sort(vector <T> &data, string algo, bool (*func) (const T&, const T&)) {
    auto start = chrono::high_resolution_clock::now();

    if (algo == "bubblesort") {
        file << "Algorithm: Bubble Sort" << endl;
        bubbleSort(data, func);
    }
    else if (algo == "selectionsort") {
        file << "Algorithm: Selection Sort" << endl;
        selectionSort(data, func);
    }
    else if (algo == "insertionsort") {
        file << "Algorithm: Insertion Sort" << endl;
        insertionSort(data, func);
    }
    else if (algo == "shellsort") {
        file << "Algorithm: Shell Sort" << endl;
        shellSort(data, func);
    }
//    else if (algo == "mergesort") {
//        file << "Algorithm: Merge Sort" << endl;
//        mergeSort(data, func);
//    }
//    else if (algo == "quicksort") {
//        file << "Algorithm: Quick Sort" << endl;
//        quickSort(data, func);
//    }

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);



    file << "Running Time: " << duration.count() << " milliseconds" << endl;

    for (auto i : data) {
        file << i << endl;
    }
}

template <typename T>
void Sort<T>::bubbleSort(vector <T> &data, bool (*func) (const T&, const T&)) {
    for (int i = 0; i < data.size(); i++) {
        bool flag = false;
        for (int j = 1; j < data.size() - i; j++) {
            if (func(data[j], data[j-1])) {
                swap(data[j-1], data[j]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

template <typename T>
void Sort<T>::selectionSort(vector <T> &data, bool (*func) (const T&, const T&)) {
    for (int i = 0; i < data.size() - 1; i++) {
        int tmp = i;
        for (int j = i+1; j < data.size(); j++) {
            if (func(data[j], data[i]))
                tmp = j;
        }
        swap(data[i], data[tmp]);
    }
}

template <typename T>
void Sort<T>::insertionSort(vector <T> &data, bool (*func) (const T&, const T&)) {
    for (int i = 1; i < data.size(); i++) {
        T tmp = data[i];
        int j = i;
        while (j >= 1 && func(tmp, data[j-1])) {
            data[j] = data[j-1];
            j--;
        }
        data[j] = tmp;
    }
}

template <typename T>
void Sort<T>::shellSort(vector <T> &data, bool (*func) (const T&, const T&)) {
    for (int gap = data.size() - 1; gap > 0; gap /= 2) {
        for (int i = gap; i < data.size(); i++) {
            T tmp = data[i];
            int j = i;
            while (j >= gap && func(tmp, data[j-gap])) {
                data[j] = data[j-gap];
                j -= gap;
            }
            data[j] = tmp;
        }
    }
}

#endif //SORTING_SORT_H
