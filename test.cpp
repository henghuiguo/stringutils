#include "stringutils.h"
#include <iostream>
#include <algorithm>

#define ASSERT(EXP) \
	if(!(EXP)) { \
		printf("\t#################### F A I L E D ####################\nASSERT: %s \n  => FAILED\n", #EXP); ; fflush(stdout); \
		return false; \
	}

bool test_stringutils() {
	{
		std::string s;
		cx::trim(s); ASSERT(s == "");
		s = " "; cx::trim(s); ASSERT(s == "");
		s = " 1 "; cx::trim(s); ASSERT(s == "1");
		s = " \r\n\t1\r\n\t "; cx::trim(s); ASSERT(s == "1"); s = " 1 \r\n\t1\r\n\t "; cx::trim(s); ASSERT(s == "1 \r\n\t1");
		s = "1 \r\n\t1\r\n\t "; cx::trim(s); ASSERT(s == "1 \r\n\t1");
		s = " 1 \r\n\t1\r\n\t 1 "; cx::trim(s); ASSERT(s == "1 \r\n\t1\r\n\t 1");

	}

	ASSERT(cx::trim_copy("") == "");
	ASSERT(cx::trim_copy(" ab") == "ab");
	ASSERT(cx::trim_copy(" ab      \t\r\n") == "ab");
	ASSERT(cx::trim_copy(" a b ") == "a b");

	ASSERT(cx::trim_copy("", "") == "");
	ASSERT(cx::trim_copy("", "  ") == "");
	ASSERT(cx::trim_copy(" ab", "  ") == "ab");
	ASSERT(cx::trim_copy(" ab", " ") == "ab");
	ASSERT(cx::trim_copy(" ab      \t\r\n", " \t\r\n") == "ab");
	ASSERT(cx::trim_copy(" a b ", " ") == "a b");

	{
		std::string s;
		cx::trim_start(s); ASSERT(s == "");
		s = " "; cx::trim_start(s); ASSERT(s == "");
		s = " 1 "; cx::trim_start(s); ASSERT(s == "1 ");
		s = " \r\n\t1\r\n\t "; cx::trim_start(s); ASSERT(s == "1\r\n\t ");
		s = " 1 \r\n\t1\r\n\t "; cx::trim_start(s); ASSERT(s == "1 \r\n\t1\r\n\t ");
		s = "1 \r\n\t1\r\n\t "; cx::trim_start(s); ASSERT(s == "1 \r\n\t1\r\n\t ");
		s = " 1 \r\n\t1\r\n\t 1 "; cx::trim_start(s); ASSERT(s == "1 \r\n\t1\r\n\t 1 ");
	}


	ASSERT(cx::trim_start_copy("  \r a b ") == "a b ");
	ASSERT(cx::trim_start_copy("  \r a b \r\n ") == "a b \r\n ");


	ASSERT(cx::trim_start_copy("  \r a b ", " \r") == "a b ");
	ASSERT(cx::trim_start_copy("  \r a b \r\n ", " \r ") == "a b \r\n ");

	{
		std::string s;
		cx::trim_end(s); ASSERT(s == "");
		s = " "; cx::trim_end(s); ASSERT(s == "");
		s = " 1 "; cx::trim_end(s); ASSERT(s == " 1");
		s = " \r\n\t1\r\n\t "; cx::trim_end(s); ASSERT(s == " \r\n\t1");
		s = " 1 \r\n\t1\r\n\t "; cx::trim_end(s); ASSERT(s == " 1 \r\n\t1");
		s = "1 \r\n\t1\r\n\t "; cx::trim_end(s); ASSERT(s == "1 \r\n\t1");
		s = " 1 \r\n\t1\r\n\t 1 "; cx::trim_end(s); ASSERT(s == " 1 \r\n\t1\r\n\t 1");
	}
	ASSERT(cx::trim_end_copy("  \r a b \r\n") == "  \r a b");
	ASSERT(cx::trim_end_copy("  \r a b \r\n", "\r\n ") == "  \r a b");

	ASSERT(cx::equals("", "") == true);
	ASSERT(cx::equals(L"", L"") == true);
	ASSERT(cx::equals("abc", "abc") == true);
	ASSERT(cx::equals(L"abc", L"abc") == true);
	ASSERT(cx::equals("ABC", "abc") == false);
	ASSERT(cx::equals(L"ABC", L"abc") == false);
	ASSERT(cx::equals("AbC", "abc", true) == true);
	ASSERT(cx::equals(L"AbC", L"abc", true) == true);
	ASSERT(cx::equals("ZhongWinABC", "ZhongWinabc") == false);
	ASSERT(cx::equals(L"ZhongWinABC", L"ZhongWinabc") == false);
	ASSERT(cx::equals("ZhongWinAbC", "ZhongWinabc", true) == true);
	ASSERT(cx::equals(L"ZhongWinAbC", L"ZhongWinabc", true) == true);

	ASSERT(cx::starts_with("", "") == true);
	ASSERT(cx::starts_with(L"", L"") == true);
	ASSERT(cx::starts_with("ABC", "") == true);
	ASSERT(cx::starts_with(L"ABC", L"") == true);
	ASSERT(cx::starts_with("ABC", "A") == true);
	ASSERT(cx::starts_with(L"ABC", L"A") == true);
	ASSERT(cx::starts_with("ABC", "a") == false);
	ASSERT(cx::starts_with(L"ABC", L"a") == false);
	ASSERT(cx::starts_with("ABC", "a", false) == false);
	ASSERT(cx::starts_with(L"ABC", L"a", false) == false);
	ASSERT(cx::starts_with("ABC", "a", true) == true);
	ASSERT(cx::starts_with(L"ABC", L"a", true) == true);
	ASSERT(cx::starts_with("ZhongWinABC", "ZhongWin") == true);
	ASSERT(cx::starts_with(L"ZhongWinABC", L"ZhongWin") == true);
	ASSERT(cx::starts_with("ZhongWinABC", "ZhongWin", true) == true);
	ASSERT(cx::starts_with(L"ZhongWinABC", L"ZhongWin", true) == true);

	ASSERT(cx::cstarts_with("", "") == true);
	ASSERT(cx::cstarts_with("ABC", "") == true);
	ASSERT(cx::cstarts_with("ABC", "A") == true);
	ASSERT(cx::cstarts_with("ABC", "a") == false);
	ASSERT(cx::cstarts_with("ABC", "a", false) == false);
	ASSERT(cx::cstarts_with("ABC", "a", true) == true);
	ASSERT(cx::cstarts_with("ZhongWinABC", "ZhongWin") == true);
	ASSERT(cx::cstarts_with("ZhongWinABC", "ZhongWin", true) == true);

	ASSERT(cx::ends_with("", "") == true);
	ASSERT(cx::ends_with(L"", L"") == true);
	ASSERT(cx::ends_with("ABC", "") == true);
	ASSERT(cx::ends_with(L"ABC", L"") == true);
	ASSERT(cx::ends_with("ABC", "C") == true);
	ASSERT(cx::ends_with(L"ABC", L"C") == true);
	ASSERT(cx::ends_with("ABC", "c") == false);
	ASSERT(cx::ends_with(L"ABC", L"c") == false);
	ASSERT(cx::ends_with("ABC", "c", false) == false);
	ASSERT(cx::ends_with(L"ABC", L"c", false) == false);
	ASSERT(cx::ends_with("ABC", "c", true) == true);
	ASSERT(cx::ends_with(L"ABC", L"c", true) == true);
	ASSERT(cx::ends_with("ABCZhongWin", "ZhongWin") == true);
	ASSERT(cx::ends_with(L"ABCZhongWin", L"ZhongWin") == true);
	ASSERT(cx::ends_with("ABCZhongWin", "ZhongWin", true) == true);
	ASSERT(cx::ends_with(L"ABCZhongWin", L"ZhongWin", true) == true);

	ASSERT(cx::cends_with("", "") == true);
	ASSERT(cx::cends_with("ABC", "") == true);
	ASSERT(cx::cends_with("ABC", "C") == true);
	ASSERT(cx::cends_with("ABC", "c") == false);
	ASSERT(cx::cends_with("ABC", "c", false) == false);
	ASSERT(cx::cends_with("ABC", "c", true) == true);
	ASSERT(cx::cends_with("ABCZhongWin", "ZhongWin") == true);
	ASSERT(cx::cends_with("ABCZhongWin", "ZhongWin", true) == true);

	ASSERT(cx::contains("ABC", "C") == true);
	ASSERT(cx::contains(L"ABC", L"C") == true);
	ASSERT(cx::contains("ABC", "C ") == false);
	ASSERT(cx::contains(L"ABC", L"C ") == false);
	ASSERT(cx::contains("ABC", "c") == false);
	ASSERT(cx::contains(L"ABC", L"c") == false);
	ASSERT(cx::contains("ABC", "c", false) == false);
	ASSERT(cx::contains(L"ABC", L"c", false) == false);
	ASSERT(cx::contains("ABC", "c", true) == true);
	ASSERT(cx::contains(L"ABC", L"c", true) == true);
	ASSERT(cx::contains("ABC", "c", false) == false);
	ASSERT(cx::contains("ABCDEF", "cd", true) == true);
	ASSERT(cx::contains("ABC DEF", "c d", true) == true);

	ASSERT(cx::ccontains("ABC", "C") == true);
	ASSERT(cx::ccontains("ABC", "C ") == false);
	ASSERT(cx::ccontains("ABC", "c") == false);
	ASSERT(cx::ccontains("ABC", "c", false) == false);
	ASSERT(cx::ccontains("ABC", "c", true) == true);
	ASSERT(cx::ccontains("ABC", "c", false) == false);
	ASSERT(cx::ccontains("ABCDEF", "cd", true) == true);
	ASSERT(cx::ccontains("ABC DEF", "c d", true) == true);
	{
		{
			std::string s;
			s = " "; cx::to_lower(s); ASSERT(s == " ");
			s = "ABC DEF"; cx::to_lower(s); ASSERT(s == "abc def");
			s = "ABC def"; cx::to_lower(s); ASSERT(s == "abc def");
			s = "ABC DEFZhongWin"; cx::to_lower(s); ASSERT(s == "abc defzhongwin");
		}

		{
			std::wstring s;
			s = L" "; cx::to_lower(s); ASSERT(s == L" ");
			s = L"ABC DEF"; cx::to_lower(s); ASSERT(s == L"abc def");
			s = L"ABC def"; cx::to_lower(s); ASSERT(s == L"abc def");
			s = L"ABC DEFZhongWin"; cx::to_lower(s); ASSERT(s == L"abc defzhongwin");
		}

	}

	ASSERT(cx::to_lower_copy("ABC DEF") == "abc def");
	ASSERT(cx::to_lower_copy(L"ABC DEF") == L"abc def");

	{
		{
			std::string s;
			s = " "; cx::to_upper(s); ASSERT(s == " ");
			s = "abc def"; cx::to_upper(s); ASSERT(s == "ABC DEF");
			s = "ABC def"; cx::to_upper(s); ASSERT(s == "ABC DEF");
			s = "abc defZhongWin"; cx::to_upper(s); ASSERT(s == "ABC DEFZHONGWIN");
		}

		{
			std::wstring s;
			s = L" "; cx::to_upper(s); ASSERT(s == L" ");
			s = L"abc def"; cx::to_upper(s); ASSERT(s == L"ABC DEF");
			s = L"abc DEF"; cx::to_upper(s); ASSERT(s == L"ABC DEF");
			s = L"abc DEFZhongWin"; cx::to_upper(s); ASSERT(s == L"ABC DEFZHONGWIN");
		}
	}

	ASSERT(cx::to_upper_copy("ABc DEf") == "ABC DEF");
	ASSERT(cx::to_upper_copy(L"ABc DEf") == L"ABC DEF");

	{
		std::vector<std::string> sArray;
		cx::split("1,2,3,4", ",", sArray, false);
		ASSERT(sArray[0] == "1");
		ASSERT(sArray[1] == "2");
		ASSERT(sArray[2] == "3");
		ASSERT(sArray[3] == "4");

		cx::split("1, 2,3,4", ",", sArray, false);
		ASSERT(sArray[1] != "2");

		cx::split("1, 2\r\n\t ,3,4", ",", sArray, false, true);
		ASSERT(sArray[1] == "2");

		cx::split(",1,2,3,4", ",", sArray, false);
		ASSERT(sArray[0] == "");
		ASSERT(sArray[1] == "1");

		cx::split("1,,2,3,4", ",", sArray, false);
		ASSERT(sArray[1] == "");

		cx::split("1,,2,3,4", ",", sArray, true);
		ASSERT(sArray[1] == "2");
	}

	{
		std::vector<std::wstring> sArray;
		cx::split(L"1,2,3,4", L",", sArray, false);
		ASSERT(sArray[0] == L"1");
		ASSERT(sArray[1] == L"2");
		ASSERT(sArray[2] == L"3");
		ASSERT(sArray[3] == L"4");

		cx::split(L"1, 2,3,4", L",", sArray, false);
		ASSERT(sArray[1] != L"2");

		cx::split(L"1, 2\r\n\t ,3,4", L",", sArray, false, true);
		ASSERT(sArray[1] == L"2");

		cx::split(L",1,2,3,4", L",", sArray, false);
		ASSERT(sArray[0] == L"");
		ASSERT(sArray[1] == L"1");

		cx::split(L"1,,2,3,4", L",", sArray, false);
		ASSERT(sArray[1] == L"");

		cx::split(L"1,,2,3,4", L",", sArray, true);
		ASSERT(sArray[1] == L"2");
	}

	{
		ASSERT(cx::format_to_buffer(NULL, "%s", "abc") == NULL);


		char buffer[200];
		ASSERT(std::string("abc") == cx::format_to_buffer(buffer, "%s", "abc"));
		ASSERT(std::string("abcdef") == cx::format_to_buffer_append(buffer, "%s", "def"));

	}
	return true;
}

int main()
{
	if (!test_stringutils()) return 1;

	printf("All tests passed!\n");
	return 0;
}
