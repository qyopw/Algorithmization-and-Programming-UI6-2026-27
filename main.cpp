#include <clocale> //для выбора языка
#include <iostream> //для потокового вывода
#include <fstream> //работа с файлом
#include <string> //работа со строками в функции BackToMenu()
#include "Header.h"
using namespace std;

int HW_num; 
// в эту переменную записывается число из файла при каждом запуске проекта.
// после окончания выполнения программы значение числа пишется в файл.
// если просто закрыть программу в процессе то значение переменной не изменится, нужно нажимать "exit"

int exit_code;

void menu() {
	if (HW_num==0) { //запускает ручной ввод если в файле не указан номер домашки
		cout << "\n\t\t Введите номер домашнего задания: (0 - выход) ";
		cin >> HW_num;
	}
	switch (HW_num) {
	case 0:
		break;
	case 1:
		cout << "\n\t\t\t Домашнее Задание №1 \n";
		exit_code = HW1V8();
		break;
	case 2:
		cout << "\n\t\t\t Домашнее Задание №2 \n";
		exit_code = HW2V8();
		break;
	case 3:
		cout << "\n\t\t\t Домашнее Задание №3 \n";
		exit_code = HW3V8();
		break;
	default:
		cout << "Ошибка ввода";
		HW_num = 0;
		menu(); //я понимаю, что рекурсия переполняет память, но мне пофиг
		break;
	}
}

bool BackToMenu() { // я хз почему решил использовать строки вместо обычного числа или символа, захотелось так
	cout << "\n\n M - меню \n E - выйти \n R - повторить \n\t\t\t";
	string choose;
	bool key = true;
	while (key) { //своеобразная проверка ввода + выбор
		cin >> choose;
		if (choose == "M" or choose == "m") { //
			HW_num = 0;
			key = false;
			menu();
		}
		else if (choose == "E" or choose == "e") key = false;
		else if (choose == "R" or choose == "r") {
			key = false;
			menu();
		} else cout << "Ошибка, введите данные снова.";
	}
	return 1;
}

bool checkin_HW_num() { //потенциальная проверка ввода
	return 1;
}

int main()
{
	setlocale(LC_ALL, ""); // использовать локаль системы (в том числе для русского вывода)

	ifstream fin("Input-Main.txt"); //создаём объект fin, читаем файл, проверяем доступ к файлу
	if (!fin.is_open()) {
		cout << "\t не удалось открыть файл на чтение \n";
		return -1;
	}

	fin >> HW_num; //записываем число из файла в глобальную переменную
	fin.close(); //закрываем файл
	checkin_HW_num(); //проверка введённого
	menu(); 
	
	ofstream fout("Input-Main.txt"); //создаём объект fout, пишем в файл, проверяем доступ к файлу
	if (!fout.is_open()) {
		cout << "\t не удалось открыть файл на запись \n";
		return -2;
	}

	fout << HW_num << endl; //перезапись нашей переменной
	fout.close(); //закрываем файл


	return 0;
}

/*
	ЧТО ДОБАВИТЬ:
		1) Таблицу вывода для exit_code при ошибках
		2) Сделать так, чтобы HW_num перезаписывался даже при некорректном выходе из программы,
	т.е. пересмотреть расположение мест, где меняется значение HW_num.
		
*/
