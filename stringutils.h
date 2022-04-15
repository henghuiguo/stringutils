///////////////////////////////////////////////////////////////////////////////////////
// MIT License
// 
// Copyright (c) 2022 Henghui Guo
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
///////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <vector>
#include <list>
#include <stdarg.h>

/** namespace cx */
namespace cx {

	bool cstarts_with(const char* src, const char* dst, bool ignoreCase = false);
	bool cends_with(const char* src, const char* dst, bool ignoreCase = false);
	bool ccontains(const char* src, const char* dst, bool ignoreCase = false);

	/**
	 * @brief Trim the input string.
	 * @param src Source string for trimming.
	 */
	void trim(std::string& src);

	/**
	 * @brief Trim the input string.
	 * @param src Source string for trimming.
	 */
	void trim(std::wstring& src);

	/**
	 * @brief Trim string to another one.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 */
	void trim(const std::string& src, std::string& dst);

	/**
	 * @brief Trim string to another one.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 */
	void trim(const std::wstring& src, std::wstring& dst);

	/**
	 * @brief Trim string to another one.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 * @param trimChars Chars list for trimming.
	 */
	void trim(const std::string& src, std::string& dst, const std::string& trimChars);

	/**
	 * @brief Trim string to another one.
	 * @param src Source string.
	 * @param dst Target string.
	 * @param trimChars Chars list for trimming.
	 */
	void trim(const std::wstring& src, std::wstring& dst, const std::wstring& trimChars);

	/**
	 * @brief Trim string and return to caller.
	 * @param src Source string for trimming.
	 * @return Trimmed string.
	 */
	std::string trim_copy(const std::string& src);

	/**
	 * @brief Trim string and return to caller.
	 * @param src Source string for trimming.
	 * @return Trimmed string.
	 */
	std::wstring trim_copy(const std::wstring& src);

	/**
	 * @brief Trim string and return to caller.
	 * @param src Source string for trimming.
	 * @param trimChars Chars list for trimming.
	 * @return Trimmed string.
	 */
	std::string trim_copy(const std::string& src, const std::string& trimChars);

	/**
	 * @brief Trim string and return to caller.
	 * @param src Source string for trimming.
	 * @param trimChars Chars list for trimming.
	 * @return Trimmed string.
	 */
	std::wstring trim_copy(const std::wstring& src, const std::wstring& trimChars);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 */
	void trim_start(std::string& src);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 */
	void trim_start(std::wstring& src);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 */
	void trim_start(const std::string& src, std::string& dst);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 */
	void trim_start(const std::wstring& src, std::wstring& dst);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 * @param trimChars Chars list for trimming.
	 */
	void trim_start(const std::string& src, std::string& dst, const std::string& trimChars);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 * @param trimChars Chars list for trimming.
	 */
	void trim_start(const std::wstring& src, std::wstring& dst, const std::wstring& trimChars);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param trimChars Chars list for trimming.
	 */
	std::string trim_start_copy(const std::string& src);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param trimChars Chars list for trimming.
	 */
	std::wstring trim_start_copy(const std::wstring& src);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param trimChars Chars list for trimming.
	 */
	std::string trim_start_copy(const std::string& src, const std::string& trimChars);

	/**
	 * @brief Removes all the leading white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param trimChars Chars list for trimming.
	 */
	std::wstring trim_start_copy(const std::wstring& src, const std::wstring& trimChars);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 */
	void trim_end(std::string& src);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 */
	void trim_end(std::wstring& src);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 */
	void trim_end(std::string& src);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 */
	void trim_end(const std::string& src, std::string& dst);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 */
	void trim_end(const std::wstring& src, std::wstring& dst);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 */
	void trim_end(const std::string& src, std::string& dst, const std::string& trimChars);
		
	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param dst Target string.
	 * @param trimChars Chars list for trimming.
	 */
	void trim_end(const std::wstring& src, std::wstring& dst, const std::wstring& trimChars);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @return Target string.
	 */
	std::string trim_end_copy(const std::string& src);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @return Target string.
	 */
	std::wstring trim_end_copy(const std::wstring& src);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param trimChars Chars list for trimming.
	 * @return Target string.
	 */
	std::string trim_end_copy(const std::string& src, const std::string& trimChars);

	/**
	 * @brief Removes all the trailing white-space characters from the input string.
	 * @param src Source string for trimming.
	 * @param trimChars Chars list for trimming.
	 * @return Target string.
	 */
	std::wstring trim_end_copy(const std::wstring& src, const std::wstring& trimChars);

	/**
	 * @brief Determines whether the first string and the second string have the same value.
	 * @param src First string.
	 * @param dst Second string.
	 * @param ignoreCase true to ignore case during the comparison; otherwise, false.
	 * @return Whether the first string and the second string have the same value.
	 */
	bool equals(const std::string& src, const std::string& dst, bool ignoreCase = false);

	/**
	 * @brief Determines whether the first string and the second string have the same value.
	 * @param src First string.
	 * @param dst Second string.
	 * @param ignoreCase true to ignore case during the comparison; otherwise, false.
	 * @return Whether the first string and the second string have the same value.
	 */
	bool equals(const std::wstring& src, const std::wstring& dst, bool ignoreCase = false);

	/**
	 * @brief Determines whether the first string starts with the second string.
	 * @param src First string.
	 * @param dst Second string.
	 * @param ignoreCase true to ignore case during the comparison; otherwise, false.
	 * @return Whether the first string starts with the second string.
	 */
	bool starts_with(const std::string& src, const std::string& dst, bool ignoreCase = false);

	/**
	 * @brief Determines whether the first string starts with the second string.
	 * @param src First string.
	 * @param dst Second string.
	 * @param ignoreCase true to ignore case during the comparison; otherwise, false.
	 * @return Whether the first string starts with the second string.
	 */
	bool starts_with(const std::wstring& src, const std::wstring& dst, bool ignoreCase = false);

	/**
	 * @brief Determines whether the end of first string matches the second string.
	 * @param src First string.
	 * @param dst Second string.
	 * @param ignoreCase true to ignore case during the comparison; otherwise, false.
	 * @return Whether the end of first string matches the second string.
	 */
	bool ends_with(const std::string& src, const std::string& dst, bool ignoreCase = false);

	/**
	 * @brief Determines whether the end of first string matches the second string.
	 * @param src First string.
	 * @param dst Second string.
	 * @param ignoreCase true to ignore case during the comparison; otherwise, false.
	 * @return Whether the end of first string matches the second string.
	 */
	bool ends_with(const std::wstring& src, const std::wstring& dst, bool ignoreCase = false);

	/**
	 * @brief Returns a value indicating whether the second string occurs within the first string.
	 * @param src First string.
	 * @param dst Second string.
	 * @param ignoreCase true to ignore case during the comparison; otherwise, false.
	 * @return true if the second string occurs within the first string, or if the second string is the empty string (""); otherwise, false.
	 */
	bool contains(const std::string& src, const std::string& dst, bool ignoreCase = false);

	/**
	 * @brief Returns a value indicating whether the second string occurs within the first string.
	 * @param src First string.
	 * @param dst Second string.
	 * @param ignoreCase true to ignore case during the comparison; otherwise, false.
	 * @return true if the second string occurs within the first string, or if the second string is the empty string (""); otherwise, false.
	 */
	bool contains(const std::wstring& src, const std::wstring& dst, bool ignoreCase = false);

	/**
	 * @brief Convert the string to lowercase.
	 * @param src The string to convert.
	 */
	void to_lower(std::string& src);

	/**
	 * @brief Convert the string to lowercase.
	 * @param src The string to convert.
	 */
	void to_lower(std::wstring& src);

	/**
	 * @brief Convert the first string to lowercase and save to the second one.
	 * @param src The string to convert.
	 * @param dst The string to save the result.
	 */
	void to_lower(const std::string& src, std::string& dst);

	/**
	 * @brief Convert the first string to lowercase and save to the second one.
	 * @param src The string to convert.
	 * @param dst The string to save the result.
	 */
	void to_lower(const std::wstring& src, std::wstring& dst);

	/**
	 * @brief Return a copy of the input string converted to lowercase.
	 * @param src The string to convert.
	 * @return The converted string.
	 */
	std::string to_lower_copy(const std::string& src);

	/**
	 * @brief Return a copy of the input string converted to lowercase.
	 * @param src The string to convert.
	 * @return The converted string.
	 */
	std::wstring to_lower_copy(const std::wstring& src);

	/**
	 * @brief Convert the string to uppercase.
	 * @param src The string to convert.
	 */
	void to_upper(std::string& src);

	/**
	 * @brief Convert the string to uppercase.
	 * @param src The string to convert.
	 */
	void to_upper(std::wstring& src);

	/**
	 * @brief Convert the first string to uppercase and save to the second one.
	 * @param src The string to convert.
	 * @param dst The string to save the result.
	 */
	void to_upper(const std::string& src, std::string& dst);

	/**
	 * @brief Convert the first string to uppercase and save to the second one.
	 * @param src The string to convert.
	 * @param dst The string to save the result.
	 */
	void to_upper(const std::wstring& src, std::wstring& dst);

	/**
	 * @brief Return a copy of the input string converted to uppercase.
	 * @param src The string to convert.
	 * @return The converted string.
	 */
	std::string to_upper_copy(const std::string& src);

	/**
	 * @brief Return a copy of the input string converted to uppercase.
	 * @param src The string to convert.
	 * @return The converted string.
	 */
	std::wstring to_upper_copy(const std::wstring& src);

	/**
	 * @brief Splits a string into a maximum number substrings based on the provided character separator.
	 * @param s Input string.
	 * @param sep Character separators.
	 * @param strArray Container for saving substrings. 
	 * @param excludeEmpty Empty substrings would be removed if true, otherwise empty substrings are included.
	 * @param trimStr Every substring will be trimmed if true, otherwise substrings will keep as they are.
	 */
	void split(const std::string& s, const std::string& sep, std::vector<std::string>& strArray, bool excludeEmpty = false, bool trimStr = false);

	/**
	 * @brief Splits a string into a maximum number substrings based on the provided character separator.
	 * @param s Input string.
	 * @param sep Character separators.
	 * @param strArray Container for saving substrings.
	 * @param excludeEmpty Empty substrings would be removed if true, otherwise empty substrings are included.
	 * @param trimStr Every substring will be trimmed if true, otherwise substrings will keep as they are.
	 */
	void split(const std::wstring& s, const std::wstring& sep, std::vector<std::wstring>& strArray, bool excludeEmpty = false, bool trimStr = false);

	/**
	 * @brief Splits a string into a maximum number substrings based on the provided character separator.
	 * @param s Input string.
	 * @param sep Character separators.
	 * @param strArray Container for saving substrings.
	 * @param excludeEmpty Empty substrings would be removed if true, otherwise empty substrings are included.
	 * @param trimStr Every substring will be trimmed if true, otherwise substrings will keep as they are.
	 */
	void split(const std::string& s, const std::string& sep, std::list<std::string>& strList, bool excludeEmpty = false, bool trimStr = false);

	/**
	 * @brief Splits a string into a maximum number substrings based on the provided character separator.
	 * @param s Input string.
	 * @param sep Character separators.
	 * @param strArray Container for saving substrings.
	 * @param excludeEmpty Empty substrings would be removed if true, otherwise empty substrings are included.
	 * @param trimStr Every substring will be trimmed if true, otherwise substrings will keep as they are.
	 */
	void split(const std::wstring& s, const std::wstring& sep, std::list<std::wstring>& strList, bool excludeEmpty = false, bool trimStr = false);

	/**
	 * @brief Format arguments to string.
	 * @param fmt Format.
	 * @param args Argument list.
	 * @param dstStr Result string.
	 */
	void format_args(const char* fmt, va_list args, std::string& dstStr);

	/**
	 * @brief Format arguments to string and return to invoker.
	 * @param fmt Format.
	 * @param args Argument list.
	 * @return Result string.
	 */
	std::string format_args(const char* fmt, va_list args);

	/**
	 * @brief Format arguments to string and return to invoker.
	 * @param fmt Format.
	 * @return Result string.
	 */
	std::string format(const char* fmt, ...);

	/**
	 * @brief Format arguments to string which is saved to a buffer.
	 * @param fmt Format.
	 * @param args Argument list.
	 * @return Buffer pointer of user input.
	 */
	char* format_args_to_buffer(char* buffer, const char* fmt, va_list args);

	/**
	 * @brief Format arguments to string which is saved to a buffer.
	 * @param fmt Format.
	 * @return Buffer pointer of user input.
	 */
	char* format_to_buffer(char* buffer, const char* fmt, ...);

	/**
	 * @brief Format arguments to string which is appended to a buffer.
	 * @param fmt Format.
	 * @param args Argument list.
	 * @return Buffer pointer of user input.
	 */
	char* format_to_buffer_append(char* buffer, const char* fmt, ...);
}