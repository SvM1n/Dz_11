#ifndef DOM11_H
#define DOM11_H
#include <iostream>
#include <string>
#include <math.h>
class Figure {
	protected:
		std::string colour;
		double square;
		int n;
	public:
		Figure();
		Figure(std::string c, double s, int n0);
		void get();
		void show();
};
class Chet :public Figure {
	protected:
		bool vipuclost;
		bool parallelnost;
	public:
		Chet();
		Chet(std::string c, double s, int n0, bool v);
		void get();
		void show();
};

class Romb:public Chet {
private:
	double d1;
public:
	Romb();
	Romb(std::string c, double s, int n0, bool v, double d0);
	void get();
	void show();

};

class Pryam :public Chet {
private:
	double a;
public:
	Pryam();
	Pryam(std::string c, double s, int n0, bool v, double a0);
	void get();
	void show();

};

#endif
