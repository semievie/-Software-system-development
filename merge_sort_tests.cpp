#include <cassert>
#include <vector>
#include <iostream>
#include "merge_sort.h"

void test_empty_array() {
    MergeSort ms;
    std::vector<int> arr;
    ms.sort(arr);
    assert(arr.empty());
}

void test_single_element() {
    MergeSort ms;
    std::vector<int> arr = { 42 };
    ms.sort(arr);
    assert(arr[0] == 42);
}

void test_sorted_array() {
    MergeSort ms;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    ms.sort(arr);
    assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
}

void test_reverse_array() {
    MergeSort ms;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    ms.sort(arr);
    assert((arr == std::vector<int>{1, 2, 3, 4, 5}));
}

void test_random_array() {
    MergeSort ms;
    std::vector<int> arr = { 3, -1, 7, 3, 0 };
    ms.sort(arr);
    assert((arr == std::vector<int>{-1, 0, 3, 3, 7}));
}

void test_duplicates() {
    MergeSort ms;
    std::vector<int> arr = { 2, 2, 2, 2 };
    ms.sort(arr);
    assert((arr == std::vector<int>{2, 2, 2, 2}));
}

void runMergeSortTests() {
    test_empty_array();
    test_single_element();
    test_sorted_array();
    test_reverse_array();
    test_duplicates();

    std::cout << "Все тесты MergeSort успешно пройдены!" << std::endl;
}