#include <iostream>
#include <string>
using namespace std;

class CPU
{
	string name;
public:
	CPU()
	{
		name = nullptr;
	}
	CPU(const char* n)
	{
		name = n;
	}
	void Show()
	{
		cout << "CPU: " << name << endl << endl;
	}
};

class GPU
{
	string name;
public:
	GPU()
	{
		name = nullptr;
	}
	GPU(const char* n)
	{
		name = n;
	}
	void Show()
	{
		cout << "GPU: " << name << endl << endl;
	}

};

class Mouse
{
	string name;
public:
	Mouse()
	{
		name = nullptr;
	}
	Mouse(const char* n)
	{
		name = n;
	}
	void Show()
	{
		cout << "Mouse: " << name << endl << endl;
	}
};

class Display
{
	string def;
public:
	Display()
	{
		def = nullptr;
	}
	Display(const char* n)
	{
		def = n;
	}
	void Show()
	{
		cout << "Display definition: " << def << endl << endl;
	}
};

class RAM
{
	string name;
public:
	RAM()
	{
		name = nullptr;
	}
	RAM(const char* n)
	{
		name = n;
	}
	void Show()
	{
		cout << "RAM: " << name << endl << endl;
	}
};

class SSD
{
	string name;
public:
	SSD()
	{
		name = nullptr;
	}
	SSD(const char* n)
	{
		name = n;
	}
	void Show()
	{
		cout << "SSD: " << name << endl << endl;
	}
};

class Laptop
{
	string name;
	Mouse* mouse; //агрегирование
	CPU cpu; //композиция
	GPU gpu; //композиция
	Display dis; //композиция
	RAM* ram; //агрегирование
	SSD* ssd; //агрегирование
	friend class Print; //дружба
public:
	Laptop(const char* n, Mouse* m, Display d, CPU c, GPU g, RAM* r, SSD* s) :mouse(m), dis(d), cpu(c), gpu(g), ram(r), ssd(s)
	{
		name = n;
	}
};



class Print
{
public:
	void Output(Laptop& obj)
	{
		cout << obj.name << endl << endl;
		obj.dis.Show();
		obj.cpu.Show();
		obj.gpu.Show();
		obj.ram->Show();
		obj.ssd->Show();
		obj.mouse->Show();
	}
};





int main() 
{
	CPU a1{ "Ryzen 7 5700x" };
	GPU a2{ "RTX 3060 TI" };
	Mouse a3{ "Bloody P30 pro" };
	Display a4{ "1920x1080" };
	RAM a5{ "Kingston FURY Beast 3200Mhz" };
	SSD a6{ "Kingston 500Gb" };
	Print a;

	Laptop b{ "Acer", &a3, a4, a1, a2, &a5,&a6 };

	a.Output(b);



}

