#include <clocale> //для выбора языка
#include <iostream> //для потокового вывода
#include <fstream> //работа с файлом
#include <string> //работа со строками в функции BackToMenu()
#include "Header.h"
using namespace std;


int status;
// в эту переменную записывается число из файла при каждом запуске проекта.
// после окончания выполнения программы значение числа пишется в файл.
// если просто закрыть программу в процессе то значение переменной не изменится, нужно нажимать "exit"

int exit_code;

void menu() {
	if (status==0) { //запускает ручной ввод если в файле не указан номер домашки
		cout << "\n\t\t Введите номер домашнего задания: (0 - выход, 11-13 - лабы) ";
		cin >> status;
	}
	switch (status) {
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
	case 11:
		cout << "\n\t\t\t Лаба №1 \n";
		exit_code = LB1V8();
		break;
	case 12:
		cout << "\n\t\t\t Лаба №2 \n";
		exit_code = LB2V8();
		break;
	case 13:
		cout << "\n\t\t\t Лаба №3 \n";
		exit_code = LB3V8();
		break;
	default:
		cout << "Ошибка ввода";
		status = 0;
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
		if (choose == "M" || choose == "m") { //
			status = 0;
			key = false;
			menu();
		}
		else if (choose == "E" || choose == "e") key = false;
		else if (choose == "R" || choose == "r") {
			key = false;
			menu();
		} else cout << "Ошибка, введите данные снова.";
	}
	return 1;
}

bool checkin_status() { //потенциальная проверка ввода
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

	fin >> status; //записываем число из файла в глобальную переменную
	fin.close(); //закрываем файл
	checkin_status(); //проверка введённого
	menu(); 
	
	ofstream fout("Input-Main.txt"); //создаём объект fout, пишем в файл, проверяем доступ к файлу
	if (!fout.is_open()) {
		cout << "\t не удалось открыть файл на запись \n";
		return -2;
	}

	fout << status << endl; //перезапись нашей переменной
	fout.close(); //закрываем файл


	return 0;
}

/*
	ЧТО ДОБАВИТЬ:
		1) Таблицу вывода для exit_code при ошибках
		2) Сделать так, чтобы HW_num перезаписывался даже при некорректном выходе из программы,
	т.е. пересмотреть расположение мест, где меняется значение HW_num.
		
*/
