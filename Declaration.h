#ifndef DECLARATION_H
#define DECLARATION_H

#include<iostream>

using namespace std;

namespace Q1
{
	class Tv
	{
	private:
		int state;
		int volume;
		int maxchannel;
		int channel;
		int mode;
		int input;
	public:
		friend class Remote;
		enum{ Off, On };
		enum{MinVal,MaxVal=20};
		enum{Antenna,Cable};
		enum{ TV, DVD };

		Tv(int s = Off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(Cable), input(TV){}
		void onoff(){ state ^= 1; }
		bool ison() const{ return state == On; }
		bool volup();
		bool voldown();
		void chanup();
		void chandown();
		void set_mode(){ mode ^= 1; }
		void set_input(){ input ^= 1; }
		void settings() const;
		void set_rmode(Remote &r);
	};

	class Remote
	{
	private:
		friend class Tv;
		int mode;
		int rmode;
	public:
		enum{Normal,Interaction};
		Remote(int m = Tv::TV, int rm = Normal) :mode(m), rmode(rm){}
		bool volup(Tv &t){ return t.volup(); }
		bool voldown(Tv &t){ return t.voldown(); }
		void onoff(Tv &t){ t.onoff(); }
		void chanup(Tv &t){ t.chanup(); }
		void chandown(Tv &t){ t.chandown(); }
		void set_chan(Tv &t, int c){ t.channel = c; }
		void set_mode(Tv &t){ t.set_mode(); }
		void set_input(Tv &t){ t.set_input(); }
		void r_mode(){ cout << "Remote mode: " << (rmode == Normal ? "Normal" : "Interaction") << endl; }
	};
}

namespace Q2
{
	double hmean(double, double);
	double gmean(double, double);

	class bad_gmean :logic_error
	{
	public:
		bad_gmean() :logic_error(""){}
		char * what(){ return "gmean() arguments should be >=0"; }
	};

	class bad_hmean :logic_error
	{
	public:
		bad_hmean() :logic_error(""){}
		char * what(){ return "invalid arguments: a=-b"; }
	};
}

namespace Q3
{
	double hmean(double, double);
	double gmean(double, double);

	class myExc :logic_error
	{
	protected:
		double a;
		double b;
	public:
		myExc(double x, double y) :logic_error(""), a(x), b(y){}
		virtual void show() = 0;
	};
	//此处不能省略public，或者使用私有继承，因为私有继承得到的是has-a关系，也就是说派生类“并不是”一个基类
	//这就导致在main中捕获异常的时候捕获不到派生类异常
	class bad_gmean :public myExc
	{
	public:
		bad_gmean(double a, double b) :myExc(a, b){}
		void show(){ cout << "gmean( " << a << " , " << b << " ): invalid arguments: a < 0 or b < 0\n"; }
	};

	class bad_hmean :public myExc
	{
	public:
		bad_hmean(double a, double b) :myExc(a, b){}
		void show(){ cout << "hmean( " << a << " , " << b << " ): invalid arguments: a = -b\n"; }
	};
}

namespace Q4
{
}

#endif
