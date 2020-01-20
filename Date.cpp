#include "Date.h"
#include "StringUtils.h"

using namespace std;

Date::Date(int day, int month, int year)
{
	m_Day = day;
	m_Month = month;
	m_Year = year;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.m_Day << "/" << date.m_Month << "/" << date.m_Year;
	return os;
}

void operator>>(const char* str, Date& date)
{
	char* day = StringUtils::substring(str, 0, 2);
	char* month = StringUtils::substring(str, 3, 2);
	char* year = StringUtils::substring(str, 6, 4);
	date.m_Day = StringUtils::string_to_int(day);
	date.m_Month = StringUtils::string_to_int(month);
	date.m_Year = StringUtils::string_to_int(year);
	delete[] day, month, year;
}

void Date::write_in_file(ostream& file)
{
	file.write((char*)&m_Day, sizeof(m_Day));
	file.write((char*)&m_Month, sizeof(m_Month));
	file.write((char*)&m_Year, sizeof(m_Year));
}

void Date::read_from_file(istream& file)
{
	file.read((char*)&m_Day, sizeof(m_Day));
	file.read((char*)&m_Month, sizeof(m_Month));
	file.read((char*)&m_Year, sizeof(m_Year));
}