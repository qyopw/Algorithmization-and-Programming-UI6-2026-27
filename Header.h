#pragma once //чтобы не было повторяющихся header.h

#include <iostream>         
#include <string>            
using namespace std;

// Общая часть
int HW1V8();
int HW2V8();
int HW3V8();
bool BackToMenu();

// Функции, которые могут пригодиться в будущем
bool selectionSort(int* arr, int n); //сортировка выбором
double maxim(double (*f)(float), double (*g)(float), float a, float b, float h); //поиск наим. расстояния между функциями f,g на [a, b] с шагом h
bool checkSimbolBlackLine(string word, string black_line); //проверка наличия символа в строке

// Шаблон удаления элемента по индексу 
template <typename T>
bool removeI_arr(T* arr, int i, int& n) {
    if (i < 0 || i >= n) {
        std::cout << "\n\t\tОшибка функции removeI_arr \n";
        return false;
    }
    for (int j = i; j < n - 1; j++) arr[j] = arr[j + 1]; //перестановка
    n--;
    return true;
}
/* Из-за неявного инстанцирования (не определён тип данных на вход функции) функцию нельзя определить в 
файле реализации, т.к. функция компилируется каждый раз при вызове в зависимости от входного типа данных.
Думаю стоит уточнить детали этой хероборы у препода.
*/
