#include "StringUtils.h"

using namespace std;

char* StringUtils::substring(const char* str, int start_index, int chars_count)
{
	char* substr = new char[chars_count + 1];
	for (int i = 0; i < chars_count; ++i)
	{
		substr[i] = str[start_index];
		++start_index;
	}
	substr[chars_count] = '\0';
	return substr;
}

int StringUtils::string_to_int(const char* number)
{
	int n;
	stringstream geek(number);
	geek >> n;
	return n;
}