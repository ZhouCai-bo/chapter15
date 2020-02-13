
#include"Declaration.h"

void ansOne();
void ansTwo();
void ansThree();
void ansFour();

int main()
{
	cout << "Question number -->";
	int choice = 0;
	cin >> choice;
	cin.get();
	switch (choice)
	{
	case 1:ansOne(); break;
	case 2:ansTwo(); break;
	case 3:ansThree(); break;
	case 4:ansFour(); break;
	}
	system("pause");
	return 0;
}

void ansOne()
{
	using namespace Q1;
	Tv s42;
	cout << "Initial settings for 42\"TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\"TV:\n";
	s42.chanup();
	cout << "\nAdjusted settings for 42\"TV:\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n42\"settings after using remote:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\"settings:\n";
	s58.settings();
	cout << "Remote grey mode:\n";
	grey.r_mode();
	cout << "Remote mode after setted by s58\n";
	s58.set_rmode(grey);
	grey.r_mode();
}

void ansTwo()
{
	using namespace Q2;
	double x, y;
	cout << "Enter two numbers: ";

	while (cin >> x >> y)
	{
		try
		{
			double a = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << a << endl;
			double b = gmean(x, y);
			cout << "Geometric mean of " << x << " and " << y << " is " << b << endl;
			cout << "Enter next set of numbers<q to quit>: ";
		}
		catch (bad_hmean &b)
		{
			cout << b.what() << endl;
			cout << "Try again.\n";
			continue;
		}
		catch (bad_gmean &b)
		{
			cout << b.what() << endl;
			cout << "Sorry, you dont get to play more.\n";
			break;
		}
	}
	cout << "Bye!\n";
	
}

void ansThree()
{
	using namespace Q3;
	double x, y;
	cout << "Enter two numbers: ";

	while (cin >> x >> y)
	{
		try
		{
			double a = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << a << endl;
			double b = gmean(x, y);
			cout << "Geometric mean of " << x << " and " << y << " is " << b << endl;
			cout << "Enter next set of numbers<q to quit>: ";
		}
		catch (myExc &b)
		{
			b.show();
			cout << "Exception type: " << typeid(b).name() << endl;
			cout << "Try again.\n";
			cout << "Enter next set of numbers<q to quit>: ";
			continue;
		}
	}
	cout << "Bye!\n";
}

void ansFour()
{
}
