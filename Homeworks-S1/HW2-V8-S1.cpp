#include <iostream> //для потокового вывода
#include <fstream> //работа с файлом
#include <string> //работа со строками
#include <algorithm> //использовал swap в функции selectionSort
#include <sstream> //istringstream - считал из строки words по-отельности слова в word[]
#include <cmath> //использовал тригонометрические функции в f(x) и g(x)
#include "../Header.h"
using namespace std;

bool selectionSort(int* arr, int n) { 
	if (n <= 0) {
		cout << "Ошибка функции selectionSort" << endl;
		return false;
	}
	int min_i;
	for (int i = 0; i < n - 1; i++) {
		min_i = i; // индекс минимума в arr, перед сортировкой - первый элемент
		for (int j = i + 1; j < n; j++) { //второй счётчик
			if (arr[j] < arr[min_i]) min_i = j; // перезапись минимального индекса (поиск минимума)
		}
		if (min_i != i) swap(arr[i], arr[min_i]); // замена
	}
	return true;
}

bool checkSymbolBlackLine(string word, string black_line) {
	int black_length = black_line.length(), buf;
	buf = word.length(); //чтобы на каждом символе слова не вызывать .length(), не уверен что она тут нужна
	for (int j = 0; j < buf; j++) { 
		for (int k = 0; k < black_length; k++) {
			if (word[j] == black_line[k]) return true; //при первом совпадении сразу вывод функции
		}
	}
	return false;
}

int count_words(string& line) { //получает строку - вовзращает количество слов в ней
	string word;
	istringstream words(line);
	int count = 0;
	while (words >> word) count++;
	return count;
}

double f(float x) { return sin(x) / x; } //функция f

double g(float x) { return tan(x+1)/(x+1); } //функция g

int HW2V8()
{
	ifstream fin("Homeworks-S1/input-hw2.txt"); //создаём объект f, читаем файл, проверяем открылся ли файл
	if (!fin.is_open()) {
		cout << "\t не удалось открыть файл \n";
		return -1;
	}
	

	// ЧАСТЬ 1


	int n = 0, buf;
	while (fin >> buf) n++; //подсчёт количества символов

	fin.clear(); //возвращает потоку чтения файла состояние goodbit - первоначальное (файл не считается прочитанным)
	fin.seekg(0); //возвращаемся в начало файла
	int* arr = new int[n]; //динамический массив размера n

	for (int i = 0; i < n; i++) fin >> arr[i]; //заполним массив

	cout << "Дикий массив: " << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << " "; //выведем массив

	if (!selectionSort(arr, n)) return -2; //Сортировка

	cout << "\n\nМассив сейчас: " << endl;
	for (int i = 0; i < n; i++) cout << arr[i] << " "; //выведем массив
	cout << endl;

	delete[] arr; //чистка


	// ЧАСТЬ 2


	string line1, line2; //создадим и запишем строку из файла
	getline(fin, line1); 
	if (!getline(fin, line2)) {
		cout << "\n\tОшибка чтения строки, убедитесь что в файле более 1 строки\n";
		return -3;
	}
	 
	
	cout << "\nВведённая строка: \n" << line2 << "\n\n";

	istringstream words(line2); //позволяет применять к строке операции чтения, как из файла (создаёт поток ввода)

	int word_num = count_words(line2); //СКОЛЬКО ВСЕГО СЛОВ

	string* word= new string[word_num];
	for (int i = 0; i < word_num; i++) words >> word[i]; //заполняем массив словами
	/* ПРИМ.: в массиве будет только первые word_num слов строки
	строки после 2 не читаются вовсе, в словах может быть любое количество символов */

	cout << "\t ДИКИЙ СПИСОК" << endl;
	for (int i = 0; i < word_num; i++) cout << "Слово " << i + 1 << ": " << word[i] << endl; //вывод всех слов с нумерацией
	
	
	string black_line = "AaBbEe"; //ЧЁРНЫЙ СПИСОК


	//проверяем все слова, удаляем из списка те, что имеют совпадающие символы со списком выше
	for (int i = 0; i < word_num;) {
		if (checkSymbolBlackLine(word[i], black_line)) removeI_arr(word, i, word_num);
		else i++; //если слово удаляется, то следующее будет иметь тот же индекс из-за смещения
	}

	cout << "\n\t СПИСОК СЕЙЧАС" << endl;
	for (int i = 0; i < word_num; i++) cout << "Слово " << i + 1 << ": " << word[i] << endl; //вывод после удаления плохих слов

	delete[] word;
	

	// ЧАСТЬ 3

	float a, b, h;
	a = 0.5;
	b = 1;
	h = 0.01;
	cout << "\nМаксимальное расстояние на отрезке [" << a << ", " << b << "] с шагом " << h << " равняется " << maxim(f, g, a, b, h) << endl;
	
	fin.close();
	BackToMenu();
	return 1;
}
 /*
	ЧТО ДОБАВИТЬ: 
		1) Понять почему в line1 записывается " ", строка 60.
		2) поэкспериментировать с вводом
		3) сделать так, чтобы black_line вводилась с файла (хз зачем)
		4) вводить a, b, h с файла
 */

