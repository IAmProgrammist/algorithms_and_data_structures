#include <lab3/sorts.h>

void heapSort(int* data, int size, int* comps) {
    
    // Создаём кучу
    for (int i = 1; INC_COMPARES(comps) && i < size; i++) {
        int currentIndex = i;
        int parentIndex = (currentIndex - 1) / 2;

        while (INC_COMPARES(comps) && currentIndex != 0 && INC_COMPARES(comps) && data[parentIndex] < data[currentIndex]) {
            swap(data + parentIndex, data + currentIndex);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }    
    }

    // Удаляем из кучи элементы
    for (int i = 0; INC_COMPARES(comps) && i < size - 1; i++) {
        swap(data, data + size - 1 - i);

        int currentIndex = 0;
        int heapSize = size - i - 1;
        while (1) {
            int leftChildIndex = 2 * currentIndex + 1; 
            int rightChildIndex = 2 * currentIndex + 2;

            if (INC_COMPARES(comps) && leftChildIndex < heapSize && INC_COMPARES(comps) && rightChildIndex < heapSize) {
                if (INC_COMPARES(comps) && data[currentIndex] < data[leftChildIndex] && 
                    INC_COMPARES(comps) && data[leftChildIndex] > data[rightChildIndex]) {
                    swap(data + leftChildIndex, data + currentIndex);
                    currentIndex = leftChildIndex;
                } else if (INC_COMPARES(comps) && data[currentIndex] < data[rightChildIndex] && 
                           INC_COMPARES(comps) && data[rightChildIndex] > data[leftChildIndex]) {
                    swap(data + rightChildIndex, data + currentIndex);
                    currentIndex = rightChildIndex;
                } else break;
            } else if (INC_COMPARES(comps) && leftChildIndex < heapSize && INC_COMPARES(comps) && data[currentIndex] < data[leftChildIndex]) {
                swap(data + leftChildIndex, data + currentIndex);
                break;
            } else if (INC_COMPARES(comps) && rightChildIndex < heapSize && INC_COMPARES(comps) && data[rightChildIndex] > data[rightChildIndex]) {
                swap(data + rightChildIndex, data + currentIndex);
                break;
            } else break;
        }
    }
}