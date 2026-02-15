#pragma once
#include <stdio.h>
#include <stdlib.h>

void heapsort(int* a, int n);

void AdjustDown(int* a, int n, int parent);

void AdjustUp(int* a, int child);

void Swap(int* p1, int* p2);

void InsertSort(int* a, int n);

void PrintArr(int* a, int n);


//void SelectSort(int* a, int n);
void SelectSort(int* a, int n);