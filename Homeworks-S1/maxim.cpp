#include <algorithm> //использовал swap 
#include <cmath> //чтобы творить волшебство вне Хогварда
#include "../Header.h"
using namespace std;

// ВХОД: *f, *g - указатели на функции; a,b - границы отрезка поиска; h - шаг проверки
double maxim(double (*f)(float), double (*g)(float), float a, float b, float h) { 

	if (a > b) swap(a, b); //a - начало отрезка
	if (a == b) return abs(f(a) - f(b)); //на лоха меня не возьмёшь
	double max=0, buf;

	while (a<=b) {
		buf = abs(f(a) - f(b));
		if (max < buf) max = buf;
		a += h;
	}

	return max;
}

// нужно проверить условия домашки, а то тут зачем-то на входе функция g, которая нигде не используется.






