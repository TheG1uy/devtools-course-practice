// Copyright 2019 Kumbrasev Pavel

#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_
#define MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_

#include <vector>
#include <algorithm

template <typename ValueType>
class Heap {
public:
    Heap() = default;
    Heap(const Heap&) = default;
    Heap(Heap&&) = default;

    std::vector<ValueType> HeapSort(std::vector<ValueType>& unsorted_arr);
    void Insert(ValueType);
    ValueType Remove();
    size_t GetSize();

 private:
    std::vector<ValueType> vec;
    void BubbleUp();
    void BubbleDown();
    void swap(size_t child, size_t parent);
    size_t GetLeftChild(size_t parent);
    size_t GetRightChild(size_t parent);
    size_t GetParent(size_t child);
};

template <typename ValueType>
size_t Heap<ValueType>::GetSize(){
    return vec.size();
}

template <typename ValueType>
void Heap<ValueType>::swap(size_t child, size_t parent) {
    std::swap(vec[child], vec[parent]);
}

template <typename ValueType>
size_t Heap<ValueType>::GetParent(size_t child) {
    if (child % 2 == 0)
       return (child / 2 ) - 1;
    else 
       return child / 2;
  
}

template <typename ValueType>
size_t Heap<ValueType>GetLeftChild(size_t parent){
    return 2 * parent + 1;
}

template <typename ValueType>
size_t Heap<ValueType>::GetRightChild(size_t parent){
    return 2 * parent + 2;
}

template <typename ValueType>
void Heap<ValueType>::Insert(ValueType value) {
    vec.push_back(value);
    BubbleUp();
}

template <typename ValueType>
void Heap<ValueType>::BubbleUp() {
    size_t child = vec.size() - 1;
    size_t parent = GetParent(child);
  
    while (vec[child] > vec[parent] && child >=0 && parent >= 0) {
        swap(child, parent);
        child = parent;
        parent = getParent(child);
    }
}


template <typename ValueType>
ValueType Heap<ValueType>::Remove() {
    size_t child = vec.size() - 1;
    swap(child, 0);  
    ValueType value = vec.back();
    vec.pop_back();  
    BubbleDown();
    return value;
}


template <typename ValueType>
void Heap<ValueType>::BubbleDown() {
    size_t parent = 0;

    while (true) {
        size_t left = GetLeftChild(parent);
        size_t right = GetRightChild(parent);
        size_t length = vec.size();
        size_t largest = parent;

        if ((left < length) && (vec[left] > vec[largest]))
            largest = left;
        if ((right < length) && (vec[right] > vec[largest]))
            largest = right;
        if (largest != parent) {
            swap(largest, parent);
            parent = largest;
        }
        else break;
    }
}

template <typename ValueType>
std::vector<ValueType> Heap<ValueType>::HeapSort(std::vector<ValueType>& unsorted_arr) {
    vec.clear();
    for (auto elem : unsorted_arr)
        Insert(elem);
    return vec;
}

#endif  // MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_