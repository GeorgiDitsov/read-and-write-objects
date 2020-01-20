#include <iostream>

class Date
{
	private:
		int m_Day, m_Month, m_Year;

	public:
		Date() : m_Day(), m_Month(), m_Year() {};
		Date(int day, int month, int year);
		int Getday() { return m_Day; };
		void Setday(int day) { m_Day = day; };
		int Getmonth() { return m_Month; };
		void Setmonth(int month) { m_Month = month; };
		int Getyear() { return m_Year; };
		void Setyear(int year) { m_Year = year; };
		friend std::ostream& operator<<(std::ostream& os, const Date& date);
		friend void operator>>(const char* str, Date& date);
		void write_in_file(std::ostream& file);
		void read_from_file(std::istream& file);
};
