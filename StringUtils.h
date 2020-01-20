#include <sstream>
#include <string>

class StringUtils
{
	private:
		StringUtils();

	public:
		static char* substring(const char* str, int start_index, int chars_count);
		static int string_to_int(const char* number);
};

