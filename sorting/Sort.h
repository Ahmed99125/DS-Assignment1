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
    void mergeSort(vector <T> &data, int l, int r, bool (*func) (const T&, const T&));
    void quickSort(vector <T> &data, int l, int r, bool (*func) (const T&, const T&));

    void merge(vector <T> &data, int l, int mid, int r, bool (*func) (const T&, const T&));
    int partition(vector <T> &data, int l, int r, bool (*func) (const T&, const T&));
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
    else if (algo == "mergesort") {
        file << "Algorithm: Merge Sort" << endl;
        mergeSort(data, 0, data.size()-1, func);
    }
    else if (algo == "quicksort") {
        file << "Algorithm: Quick Sort" << endl;
        quickSort(data, 0, data.size()-1, func);
    }

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

template <typename T>
void Sort<T>::mergeSort(vector <T> &data, int l, int r, bool (*func) (const T&, const T&)) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(data, mid+1, r, func);
    mergeSort(data, l, mid, func);
    merge(data, l, mid, r, func);
}

template <typename T>
void Sort<T>::merge(vector <T> &data, int l, int mid, int r, bool (*func) (const T&, const T&)) {
    vector <T> leftArr, rightArr;

    for (int i = l; i < mid+1; i++)
        leftArr.push_back(data[i]);
    for (int i = mid+1; i <= r; i++)
        rightArr.push_back(data[i]);

    int leftIdx = 0, rightIdx = 0, mergeIdx = l;

    while (leftIdx < leftArr.size() && rightIdx < rightArr.size()) {
        if (func(leftArr[leftIdx], rightArr[rightIdx])) {
            data[mergeIdx] = leftArr[leftIdx];
            leftIdx++;
        }
        else {
            data[mergeIdx] = rightArr[rightIdx];
            rightIdx++;
        }
        mergeIdx++;
    }

    while (leftIdx < leftArr.size())
        data[mergeIdx++] = leftArr[leftIdx++];

    while (rightIdx < rightArr.size())
        data[mergeIdx++] = rightArr[rightIdx++];
}

template <typename T>
void Sort<T>::quickSort(vector <T> &data, int l, int r, bool (*func) (const T&, const T&)) {
    if (l >= r)
        return;
    int pivot = partition(data, l, r, func);
    quickSort(data, pivot+1, r, func);
    quickSort(data, l, pivot-1, func);
}

template <typename T>
int Sort<T>::partition(vector <T> &data, int l, int r, bool (*func) (const T&, const T&)) {
    int pivot = r, idx = l;
    for (int i = l; i <= r; i++) {
        if (func(data[i], data[pivot])) {
            swap(data[i], data[idx]);
            idx++;
        }
    }
    swap(data[idx], data[r]);
    return idx;
}

#endif //SORTING_SORT_H
