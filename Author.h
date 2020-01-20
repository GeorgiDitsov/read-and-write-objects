#include <iostream>
#include <fstream>
#include <vector>

class Author
{
	private:
		long m_Id;
		char m_First_name[100];
		char m_Last_name[100];

	public:
		Author() : m_Id(), m_First_name(), m_Last_name() {};
		Author(long id, const char* first_name, const char* last_name);
		long Getid() { return m_Id; };
		void Setid(long id) { m_Id = id; };
		char* Getfirst_name() { return m_First_name; };
		void Setfirst_name(char* first_name) { strcpy_s(m_First_name, first_name); };
		char* Getlast_name() { return m_Last_name; };
		void Setlast_name(char* last_name) { strcpy_s(m_Last_name, last_name); };
		friend std::ostream& operator<<(std::ostream& os, const Author& author);
		friend std::istream& operator>>(std::istream& is, Author& author);
		void write_in_file(std::ostream& file);
		void read_from_file(std::istream& file);
};
