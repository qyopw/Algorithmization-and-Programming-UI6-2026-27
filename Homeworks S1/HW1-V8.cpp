#include <cmath> //для pow, tan, acos
#include <iostream> //для потокового вывода
#include <fstream> //для ifstream (чтения файла)
#include <algorithm> //для max
#include "Header.h"
using namespace std;



 
//проверка ввода
bool checkin_xyz(float x, float y, float z) {
	if (x == 30 && y == 5 && z == 2005) cout << "\t Пасхалка! \n";
	// Я ХЗ ЧТО ТУТ ПИСАТЬ ЧЕСТНО ГОВОРЯ
	return true; 
}

float equation(float x, float y, float z) {
	float g = max(x, max(y, z)) + pow(y, 2) * z; //какого чёрта нельзя было сделать ф-ию max с 3+ аргументами
	return g;
}

double f(double x) { //это сделано чтобы функцию можно было менять
	return pow(tan(x), 2);
}

double square(double a, double b, int n) { //функция поиска площади под кривой f
	double h = (b - a) / n, sum = (f(a) + f(b)) / 2;
	for (int i = 0; i <= n - 1; i++) {
		sum += f(a + i*h);
	}
	return h * sum;
}

int HW1V8()
{
	ifstream f("Homeworks S1/input-hw1.txt"); // путь относительно корня проекта
	if (!f.is_open()) {
		cout << "\t не удалось открыть файл \n";
		return -1;
	}

	//вроде их не нужно делать глобальными
	float x, y, z; 
	int n;

	f >> x >> y >> z >> n; //читаем 
	if (!checkin_xyz(x, y, z)) return -2; //проверка ввода
	cout << " X = " << x << " Y = " << y << " Z = " << z << " n = " << n << endl; //показ введённых чисел

	cout << "\t\t Итог вычислений: " << equation(x, y, z) << endl; //ответ на Часть 2

	double pi = acos(-1);
	double a = pi / 4, b = pi / 3; //зашил отрезок интегрирования прям в программу

	cout << "\t\t Итого площадь: " << square(a, b, n) << endl;


	f.close();
	BackToMenu(); 
	return 1;
}

/*
	ЧТО ДОБАВИТЬ:
		1) Проверку ввода чисел
		2) Комментарии в текстовом файле
		3) Фильтр для мусора в текстовом файле
		4) Если ввод провалился - попросить внести данные с клавиатуры
		5) Перезаписать текстовый файл, если там есть мусор/неверные данные (при наличии введённых с клавиатуры)
*/
