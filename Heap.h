#pragma once
#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

template<class T>
class Heap{
private:
    vector<string> heap;
    int end;
public:

    Heap(vector<T> words){
        heap = words;
        buildMaxHeap();
    }

    // get parent of node i
    int parent(int i){
        return floor(i/2);
    }
    
    // get left child of node i
    int left(int i){
        return 2*i;
    }
    // get right child of node i
    int right(int i){
        return 2*i + 1;
    }

    // get value at node i
    string getItem(int i){
        return heap[i-1];
    }

    // swap 2 nodes
    void swap(int a, int b){
        //change back to 0-based indexing
        a--;
        b--;

        //swap
        string temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp; 
    }

    // heapify node i
    void maxHeapify(int i){
        int l = left(i);
        int r = right(i);
        int largest = i;
        if(l <= end && getItem(l) > getItem(largest)){
            largest = l;
        }
        if(r <= end && getItem(r) > getItem(largest)){
            largest = r;
        }
        if(largest != i){
            swap(largest, i);
            maxHeapify(largest);
        }
    }

    // modify vector to comply with heap properties
    void buildMaxHeap(){
        end = heap.size();
        for(int i = parent(end); i >= 1; i--){
            maxHeapify(i);
        }
    }

    // sort heap using heap sort
    vector<T> heapSort(){

        for(int i = heap.size(); i > 1; i--){

            swap(1, i);
            end--;
            maxHeapify(1);
        }
        return heap;
    }
};

#endif