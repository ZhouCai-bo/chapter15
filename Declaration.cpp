#include"Declaration.h"

namespace Q1
{
	bool Tv::volup()
	{
		if (volume < MaxVal)
		{
			volume++;
			return true;
		}
		return false;
	}
	bool Tv::voldown()
	{
		if (volume > MinVal)
		{
			volume--;
			return true;
		}
		return false;

	}
	void Tv::chanup()
	{
		if (channel < maxchannel)
		{
			channel++;
		}
		else
			channel = 1;
	}
	void Tv::chandown()
	{
		if (channel > 1)
		{
			channel--;
		}
		else
			channel = maxchannel;
	}

	void Tv::settings() const
	{
		cout << "Tv is " << (state == Off ? "Off" : "On" )<< endl;
		if (state == On)
		{
			cout << "Volume setting= " << volume << endl;
			cout << "Channel settinng= " << channel << endl;
			cout << "Mode= " << (mode == Antenna ? "Antenna" : "Cable") << endl;
			cout << "Input= " << (input == TV ? "TV" : "DVD") << endl;
		}
	}
	void Tv::set_rmode(Remote &r)
	{
		if (state == On)
		{
			r.rmode ^= 1;
		}
	}
}

namespace Q2
{
	double hmean(double a, double b)
	{
		if (a == -b)
			throw bad_hmean();
		return 2.0*a*b / (a + b);
	}
	double gmean(double a, double b)
	{
		if (a < 0 || b < 0)
			throw bad_gmean();
		return sqrt(a*b);
	}
}

namespace Q3
{
	double hmean(double a, double b)
	{
		if (a == -b)
			throw bad_hmean(a, b);
		return 2.0*a*b / (a + b);
	}
	double gmean(double a, double b)
	{
		if (a < 0 || b < 0)
			throw bad_gmean(a, b);
		return sqrt(a*b);
	}
}
