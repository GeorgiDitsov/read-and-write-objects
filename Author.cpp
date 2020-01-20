#include "Author.h"

using namespace std;

Author::Author(long id, const char* first_name, const char* last_name)
{
	m_Id = id;
	strcpy_s(m_First_name, first_name);
	strcpy_s(m_Last_name, last_name);
}

ostream& operator<<(ostream& os, const Author& author)
{
	os << "Id: " << author.m_Id << ", Full name: " << author.m_First_name << ' ' << author.m_Last_name << endl;
	return os;
}

istream& operator>>(istream& is, Author& author)
{
	is >> author.m_Id >> author.m_First_name >> author.m_Last_name;
	return is;
}

void Author::write_in_file(ostream& file)
{
	file.write((char*)&m_Id, sizeof(m_Id));
	file.write((char*)&m_First_name, sizeof(m_First_name));
	file.write((char*)&m_Last_name, sizeof(m_Last_name));
}

void Author::read_from_file(istream& file)
{
	file.read((char*)&m_Id, sizeof(m_Id));
	file.read((char*)&m_First_name, sizeof(m_First_name));
	file.read((char*)&m_Last_name, sizeof(m_Last_name));
}
