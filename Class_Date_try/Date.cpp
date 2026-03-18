#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}


Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if(_year == d._year){
		if (_month < d._month)
		{
			return true;
		}
		else if(_month==d._month){
			
			return _day < d._day;
		}
	}

	return false;
}



bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator>(const Date& d)
{
	return !(*this < d) && *this != d;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}


bool Date::operator<=(const Date& d)
{
	return !(*this > d);

}

bool Date::operator>=(const Date& d)
{
	return !(*this < d);
}

Date& Date::operator=(const Date& d){
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13) {
			_year++;
			_month = 1;
		}
	}
	return *this;
}
Date Date::operator+(int day) {
	Date tmp=*this;
	tmp += day;//加等函数复用

	/*tmp._day += day;
	while (tmp._day > GetMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= GetMonthDay(tmp._year, tmp._month);
		++tmp._month;
		if (tmp._month == 13)
		{
			tmp._year++;
			tmp._month = 1;
		}
	}*/
	//注释部分等价于tmp+=dady
	return tmp;

}

//日期减去天数

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day < 1)
	{
		--_month;
		if (_month < 1)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);

	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;//减等函数的复用


	return tmp;
}

int Date::operator-(const Date& d)
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}

//前置++
Date Date::operator++(int)
{
	Date tmp = *this;
	tmp += 1;
	return tmp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	tmp -= 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

ostream& operator<<(ostream& out,const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日";
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请依次输入年月日:>";
		in >> d._year >> d._month >> d._day;
		
		break;
	}
	return in;
}