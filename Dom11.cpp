#include "Dom11.h"

Figure::Figure(){
	colour[0] = '\0';
	square =0;
	n = 0;
}
Figure::Figure(std::string c, double s, int n0) {
	colour = c;
	square = s;
	n = n0;
}
void Figure::get() {
	std::cout << "Введите цвет и площадь фигуры и количество вершин: " << std::endl;
	std::cin >> colour >> square >> n;
}
void Figure::show() {
	std::cout << "Цвет: " << colour << std::endl << "Площадь: " << square << std::endl << "Количество вершин:" << n << std::endl;
}



Chet::Chet():Figure() {
	vipuclost = 1;
}
Chet::Chet(std::string c, double s, int n0, bool v):Figure(c, s, n0) {
	vipuclost = v;
}
void Chet::get() {
	Figure::get();
	std::cout << "Является ли четырехугольник выпуклым?(1/0): " << std::endl;
	std::cin >> vipuclost;
}
void Chet::show() {
	Figure::show();
	if (vipuclost) {
		std::cout << "Четырехугольник выпуклый" << std::endl;
	}
	else {
		std::cout << "Четырехугольник невыпуклый" << std::endl;
	}
}


Romb::Romb() :Chet() {
	d1 = 0;
}
Romb::Romb(std::string c, double s, int n0, bool v, double d0) : Chet(c, s,  n0, v) {
	d1 = d0;
}
void Romb::get() {
	Chet::get();
	std::cout << "Введите длину одной из диагоналей ромба: " << std::endl;
	std::cin >> d1;
}
void Romb::show() {
	Chet::show();
	std::cout << "Диагонали ромба: " << std::endl << "d1= " << d1 << " " << "d2= " << square * 2 / d1 << std::endl;
	std::cout << "Длина стороны ромба: " << std::endl << "a= " << sqrt(pow(d1 / 2, 2) + pow(square / d1, 2)) << std::endl;
	std::cout << " Углы: " << std::endl << "alpha= " << acos(1 - (pow(d1 / 2, 2) / (2 * pow(sqrt(pow(d1 / 2, 2) + pow(square / d1, 2)), 2)))) << " " << "beta " << acos(1 - (pow(square / d1, 2) / (2 * pow(sqrt(pow(d1 / 2, 2) + pow(square / d1, 2)), 2)))) << std::endl;
}



Pryam::Pryam() :Chet() {
	a = 0;
}
Pryam::Pryam(std::string c, double s, int n0, bool v, double a0) : Chet(c, s, n0, v) {
	a = a0;
}
void Pryam::get() {
	Chet::get();
	std::cout << "Введите длину одной из диагоналей прямоугольника: " << std::endl;
	std::cin >> a;
}
void Pryam::show() {
	Chet::show();
	std::cout << "Стороны прям: " << std::endl << "a= " << a << " " << "b= " << square / a << std::endl;
	std::cout << "Диагональ: " << std::endl << "d= " << sqrt(pow(a, 2) + pow(square / a, 2)) << std::endl;
	std::cout << " Угол между диагоналями: " << std::endl << "alpha= " << asin(2 * square / (pow(sqrt(pow(a, 2) + pow(square / a, 2)), 2))) << std::endl;
}