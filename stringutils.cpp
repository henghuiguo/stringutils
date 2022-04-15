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

#include <string.h>
#include <algorithm>
#include <iterator>
#include <locale>
#include "stringutils.h"

namespace cx {
	//////////////////////////////////////////////////////////////////////////
#define CX_TRIM_CHARS "\t\n\v\f\r "
#define CX_WTRIM_CHARS L"\t\n\v\f\r "

	static std::string CxTrimChars = CX_TRIM_CHARS;
	static std::wstring CxWTrimChars = CX_WTRIM_CHARS;

	class StringTrimHelper {
	public:
		template<typename TStr>
		static void trim(TStr& src, const TStr& chars) {
			trim_start(src, chars);
			trim_end(src, chars);
		}

		template<typename TStr>
		static void trim_copy(const TStr& src, TStr& dst, const TStr& chars) {
			dst = src;
			trim(dst, chars);
		}

		template<typename TStr>
		static TStr trim_copy(const TStr& src, const TStr& chars) {
			TStr dst;
			trim_copy(src, dst, chars);
			return dst;
		}

		template<typename TStr>
		static void trim_start(TStr& src, const TStr& chars) {
			src.erase(0, src.find_first_not_of(chars));
		}

		template<typename TStr>
		static void trim_start_copy(const TStr& src, TStr& dst, const TStr& chars) {
			dst = src;
			trim_start(dst, chars);
		}

		template<typename TStr>
		static TStr trim_start_copy(const TStr& src, const TStr& chars) {
			TStr dst;
			trim_start_copy(src, dst, chars);
			return dst;
		}

		template<typename TStr>
		static void trim_end(TStr& src, const TStr& chars) {
			src.erase(src.find_last_not_of(chars) + 1);
		}

		template<typename TStr>
		static void trim_end_copy(const TStr& src, TStr& dst, const TStr& chars) {
			dst = src;
			trim_end(dst, chars);
		}

		template<typename TStr>
		static TStr trim_end_copy(const TStr& src, const TStr& chars) {
			TStr dst;
			trim_end_copy(src, dst, chars);
			return dst;
		}
	};

	class StringCompareHelper {
	public:
		struct IsEqual
		{
			template<typename _TChar>
			bool operator()(const _TChar& c1, const _TChar& c2) const {
				return c1 == c2;
			}
		};

		struct IsIEqual
		{
			IsIEqual() { _Loc = std::locale(); }

			template<typename _TChar>
			bool operator()(const _TChar& c1, const _TChar& c2) const {
				return std::toupper<_TChar>(c1, _Loc) == std::toupper<_TChar>(c2, _Loc);
			}

		private:
			std::locale _Loc;
		};

		template<typename TStr>
		static bool equals(const TStr& src, const TStr& dst, bool ignoreCase /*= false*/)
		{
			if (src.size() != dst.size()) return false;

			if (ignoreCase)
				return std::equal(dst.begin(), dst.end(), src.begin(), IsIEqual());
			else
				return std::equal(dst.begin(), dst.end(), src.begin());
		}

		template<typename TStr>
		static bool starts_with(const TStr& src, const TStr& dst, bool ignoreCase /*= false*/)
		{
			if (src.size() < dst.size()) return false;

			if (ignoreCase)
				return std::equal(dst.begin(), dst.end(), src.begin(), IsIEqual());
			else
				return std::equal(dst.begin(), dst.end(), src.begin());
		}

		static bool StartsWithC(const char* src, const char* dst, bool ignoreCase /*= false*/)
		{
			if (src == NULL || dst == NULL) return false;
			size_t srcLen = strlen(src);
			size_t dstLen = strlen(dst);
			if (srcLen < dstLen) return false;

			if (ignoreCase)
				return std::equal(dst, dst + dstLen, src, StringCompareHelper::IsIEqual());
			else
				return std::equal(dst, dst + dstLen, src);
		}

		template<typename TStr>
		static bool ends_with(const TStr& src, const TStr& dst, bool ignoreCase /*= false*/)
		{
			if (src.size() < dst.size()) return false;

			if (ignoreCase)
				return std::equal(dst.rbegin(), dst.rend(), src.rbegin(), StringCompareHelper::IsIEqual());
			else
				return std::equal(dst.rbegin(), dst.rend(), src.rbegin());
		}

		static bool EndsWithC(const char* src, const char* dst, bool ignoreCase /*= false*/)
		{
			if (src == NULL || dst == NULL) return false;
			size_t srcLen = strlen(src);
			size_t dstLen = strlen(dst);
			if (srcLen < dstLen) return false;

			if (ignoreCase)
				return std::equal(src + srcLen - dstLen, src + srcLen, dst, IsIEqual());
			else
				return std::equal(src + srcLen - dstLen, src + srcLen, dst);
		}

		template<typename TStr>
		static bool contains(const TStr& src, const TStr& dst, bool ignoreCase /*= false*/)
		{
			if (ignoreCase)
				return std::search(src.begin(), src.end(), dst.begin(), dst.end(), IsIEqual()) != src.end();
			else
				return std::search(src.begin(), src.end(), dst.begin(), dst.end()) != src.end();
		}

		static bool ContainsC(const char* src, const char* dst, bool ignoreCase /*= false*/)
		{
			if (src == NULL || dst == NULL) return false;
			size_t srcLen = strlen(src);
			size_t dstLen = strlen(dst);
			if (srcLen < dstLen) return false;

			if (ignoreCase)
				return std::search(src, src + srcLen, dst, dst + dstLen, IsIEqual()) != (src + srcLen);
			else
				return std::search(src, src + srcLen, dst, dst + dstLen) != (src + srcLen);
		}
	};

	class StringCaseHelper {
	public:
		struct ToLowerCvter
		{
			ToLowerCvter() { _Loc = std::locale(); }

			template<typename _TChar>
			_TChar operator()(const _TChar& c) const {
				return std::tolower(c, _Loc);
			}

		private:
			std::locale _Loc;
		};

		struct ToUpperCvter
		{
			ToUpperCvter() { _Loc = std::locale(); }

			template<typename _TChar>
			_TChar operator()(const _TChar& c) const {
				return std::toupper(c, _Loc);
			}

		private:
			std::locale _Loc;
		};

		template<typename TStr>
		static void to_lower(TStr& s) {
			std::transform(s.begin(), s.end(), s.begin(), ToLowerCvter());
		}

		template<typename TStr>
		static void to_lower_copy(const TStr& src, TStr& dst) {
			dst.resize(src.size());
			std::transform(src.begin(), src.end(), dst.begin(), ToLowerCvter());
		}

		template<typename TStr>
		static TStr to_lower_copy(const TStr& src) {
			TStr dst;
			to_lower_copy(src, dst);
			return dst;
		}

		template<typename TStr>
		static void to_upper(TStr& s) {
			std::transform(s.begin(), s.end(), s.begin(), ToUpperCvter());
		}

		template<typename TStr>
		static void to_upper_copy(const TStr& src, TStr& dst) {
			dst.resize(src.size());
			std::transform(src.begin(), src.end(), dst.begin(), ToUpperCvter());
		}

		template<typename TStr>
		static TStr to_upper_copy(const TStr& src) {
			TStr dst;
			to_upper_copy(src, dst);
			return dst;
		}
	};

	//////////////////////////////////////////////////////////////////////////
	bool cstarts_with(const char* src, const char* dst, bool ignoreCase)
	{
		return StringCompareHelper::StartsWithC(src, dst, ignoreCase);
	}

	bool cends_with(const char* src, const char* dst, bool ignoreCase /*= false*/)
	{
		return StringCompareHelper::EndsWithC(src, dst, ignoreCase);
	}

	bool ccontains(const char* src, const char* dst, bool ignoreCase)
	{
		return StringCompareHelper::ContainsC(src, dst, ignoreCase);
	}
	//////////////////////////////////////////////////////////////////////////
	void trim(std::string& src) {
		StringTrimHelper::trim(src, CxTrimChars);
	}

	void trim(std::wstring& src) {
		StringTrimHelper::trim(src, CxWTrimChars);
	}

	void trim(const std::string& src, std::string& dst) {
		StringTrimHelper::trim_copy(src, dst, CxTrimChars);
	}

	void trim(const std::wstring& src, std::wstring& dst) {
		StringTrimHelper::trim_copy(src, dst, CxWTrimChars);
	}

	void trim(const std::string& src, std::string& dst, const std::string& trimChars) {
		StringTrimHelper::trim_copy(src, dst, trimChars);
	}

	void trim(const std::wstring& src, std::wstring& dst, const std::wstring& trimChars) {
		StringTrimHelper::trim_copy(src, dst, trimChars);
	}

	std::string  trim_copy(const std::string& src) {
		return StringTrimHelper::trim_copy(src, CxTrimChars);
	}

	std::wstring trim_copy(const std::wstring& src) {
		return StringTrimHelper::trim_copy(src, CxWTrimChars);
	}

	std::string trim_copy(const std::string& src, const std::string& trimChars) {
		return StringTrimHelper::trim_copy(src, trimChars);
	}

	std::wstring trim_copy(const std::wstring& src, const std::wstring& trimChars) {
		return StringTrimHelper::trim_copy(src, trimChars);
	}

	void trim_start(std::string& src) {
		StringTrimHelper::trim_start(src, CxTrimChars);
	}

	void trim_start(std::wstring& src) {
		StringTrimHelper::trim_start(src, CxWTrimChars);
	}

	void trim_start(const std::string& src, std::string& dst) {
		StringTrimHelper::trim_start_copy(src, dst, CxTrimChars);
	}

	void trim_start(const std::wstring& src, std::wstring& dst) {
		StringTrimHelper::trim_start_copy(src, dst, CxWTrimChars);
	}

	void trim_start(const std::string& src, std::string& dst, const std::string& trimChars) {
		StringTrimHelper::trim_start_copy(src, dst, trimChars);
	}

	void trim_start(const std::wstring& src, std::wstring& dst, const std::wstring& trimChars) {
		StringTrimHelper::trim_start_copy(src, dst, trimChars);
	}

	std::string  trim_start_copy(const std::string& src) {
		return StringTrimHelper::trim_start_copy(src, CxTrimChars);
	}

	std::wstring trim_start_copy(const std::wstring& src) {
		return StringTrimHelper::trim_start_copy(src, CxWTrimChars);
	}

	std::string trim_start_copy(const std::string& src, const std::string& trimChars) {
		return StringTrimHelper::trim_start_copy(src, trimChars);
	}

	std::wstring trim_start_copy(const std::wstring& src, const std::wstring& trimChars) {
		return StringTrimHelper::trim_start_copy(src, trimChars);
	}

	void trim_end(std::string& src) {
		StringTrimHelper::trim_end(src, CxTrimChars);
	}

	void trim_end(std::wstring& src) {
		StringTrimHelper::trim_end(src, CxWTrimChars);
	}

	void trim_end(const std::string& src, std::string& dst) {
		StringTrimHelper::trim_end_copy(src, dst, CxTrimChars);
	}

	void trim_end(const std::wstring& src, std::wstring& dst) {
		StringTrimHelper::trim_end_copy(src, dst, CxWTrimChars);
	}

	void trim_end(const std::string& src, std::string& dst, const std::string& trimChars) {
		StringTrimHelper::trim_end_copy(src, dst, trimChars);
	}

	void trim_end(const std::wstring& src, std::wstring& dst, const std::wstring& trimChars) {
		StringTrimHelper::trim_end_copy(src, dst, trimChars);
	}

	std::string  trim_end_copy(const std::string& src) {
		return StringTrimHelper::trim_end_copy(src, CxTrimChars);
	}

	std::wstring trim_end_copy(const std::wstring& src) {
		return StringTrimHelper::trim_end_copy(src, CxWTrimChars);
	}

	std::string trim_end_copy(const std::string& src, const std::string& trimChars) {
		return StringTrimHelper::trim_end_copy(src, trimChars);
	}

	std::wstring trim_end_copy(const std::wstring& src, const std::wstring& trimChars) {
		return StringTrimHelper::trim_end_copy(src, trimChars);
	}

	bool equals(const std::string& src, const std::string& dst, bool ignoreCase /*= false*/)
	{
		if (src.length() != dst.length()) return false;

		return StringCompareHelper::equals(src, dst, ignoreCase);
	}

	bool equals(const std::wstring& src, const std::wstring& dst, bool ignoreCase /*= false*/)
	{
		if (src.length() != dst.length()) return false;

		return StringCompareHelper::equals(src, dst, ignoreCase);
	}

	bool starts_with(const std::string& src, const std::string& dst, bool ignoreCase /*= false*/)
	{
		return StringCompareHelper::starts_with(src, dst, ignoreCase);
	}

	bool starts_with(const std::wstring& src, const std::wstring& dst, bool ignoreCase /*= false*/)
	{
		return StringCompareHelper::starts_with(src, dst, ignoreCase);
	}

	bool ends_with(const std::string& src, const std::string& dst, bool ignoreCase /*= false*/)
	{
		return StringCompareHelper::ends_with(src, dst, ignoreCase);
	}

	bool ends_with(const std::wstring& src, const std::wstring& dst, bool ignoreCase /*= false*/)
	{
		return StringCompareHelper::ends_with(src, dst, ignoreCase);
	}

	bool contains(const std::string& src, const std::string& dst, bool ignoreCase /*= false*/)
	{
		return StringCompareHelper::contains(src, dst, ignoreCase);
	}

	bool contains(const std::wstring& src, const std::wstring& dst, bool ignoreCase /*= false*/)
	{
		return StringCompareHelper::contains(src, dst, ignoreCase);
	}

	void to_lower(std::string& src) {
		StringCaseHelper::to_lower(src);
	}

	void to_lower(std::wstring& src) {
		StringCaseHelper::to_lower(src);
	}

	void to_lower(const std::string& src, std::string& dst) {
		StringCaseHelper::to_lower_copy(src, dst);
	}

	void to_lower(const std::wstring& src, std::wstring& dst) {
		StringCaseHelper::to_lower_copy(src, dst);
	}

	std::string  to_lower_copy(const std::string& src) {
		return StringCaseHelper::to_lower_copy(src);
	}

	std::wstring to_lower_copy(const std::wstring& src) {
		return StringCaseHelper::to_lower_copy(src);
	}

	void to_upper(std::string& src) {
		StringCaseHelper::to_upper(src);
	}

	void to_upper(std::wstring& src) {
		StringCaseHelper::to_upper(src);
	}

	void to_upper(const std::string& src, std::string& dst) {
		StringCaseHelper::to_upper_copy(src, dst);
	}

	void to_upper(const std::wstring& src, std::wstring& dst) {
		StringCaseHelper::to_upper_copy(src, dst);
	}

	std::string  to_upper_copy(const std::string& src) {
		return StringCaseHelper::to_upper_copy(src);
	}

	std::wstring to_upper_copy(const std::wstring& src) {
		return StringCaseHelper::to_upper_copy(src);
	}

	// from stl_string.h
	template <class _TStr, class _TIter>
	static void split_str(const _TStr& s, _TIter iter, const _TStr& sep, bool exceptEmpty = false, bool trimStr = false)
	{
		_TStr dst;

		if (s.size() == 0)
			return;

		for (size_t i = 0; i < s.size(); i++)
		{
			size_t id = sep.find(s[i]);
			if (id != _TStr::npos)
			{
				if (!exceptEmpty || dst.size() > 0)
				{
					if (trimStr) cx::trim(dst);
					*iter = dst;
					dst.resize(0);
				}
			}
			else
			{
				dst += s[i];
			}
		}

		if (!exceptEmpty || dst.size() > 0)
		{
			if (trimStr) cx::trim(dst);
			*iter = dst;
		}
	}

	void split(const std::string& s, const std::string& sep, std::vector<std::string>& strArray, bool excludeEmpty /*= false*/, bool trimStr /*= false*/)
	{
		strArray.clear();
		split_str(s, std::back_insert_iterator<std::vector<std::string> >(strArray), sep, excludeEmpty, trimStr);
	}

	void split(const std::wstring& s, const std::wstring& sep, std::vector<std::wstring>& strArray, bool excludeEmpty /*= false*/, bool trimStr /*= false*/)
	{
		strArray.clear();
		split_str(s, std::back_insert_iterator<std::vector<std::wstring> >(strArray), sep, excludeEmpty, trimStr);
	}

	void split(const std::string& s, const std::string& sep, std::list<std::string>& strList, bool excludeEmpty /*= false*/, bool trimStr /*= false*/)
	{
		strList.clear();
		split_str(s, std::back_insert_iterator<std::list<std::string> >(strList), sep, excludeEmpty, trimStr);
	}

	void split(const std::wstring& s, const std::wstring& sep, std::list<std::wstring>& strList, bool excludeEmpty /*= false*/, bool trimStr /*= false*/)
	{
		strList.clear();
		split_str(s, std::back_insert_iterator<std::list<std::wstring> >(strList), sep, excludeEmpty, trimStr);
	}

	void format_args(const char* fmt, va_list args, std::string& dstStr)
	{
		if (fmt == 0) {
			return;
		}

		va_list args2;
		va_copy(args2, args);
		size_t nLength = vsnprintf(NULL, 0, fmt, args2);
		va_end(args2);

		dstStr.resize(nLength);
		vsnprintf(&dstStr[0], nLength + 1, fmt, args);
	}

	std::string format_args(const char* fmt, va_list args)
	{
		std::string s;

		format_args(fmt, args, s);

		return s;
	}

	std::string format(const char* fmt, ...)
	{
		std::string s;
		va_list argList;
		va_start(argList, fmt);
		format_args(fmt, argList, s);
		va_end(argList);

		return s;
	}

	char* format_args_to_buffer(char* buffer, const char* fmt, va_list args)
	{
		if (fmt == NULL || buffer == NULL)
			return buffer;

		vsprintf(buffer, fmt, args);
		return buffer;
	}

	char* format_to_buffer(char* buffer, const char* fmt, ...)
	{
		va_list argList;
		va_start(argList, fmt);
		format_args_to_buffer(buffer, fmt, argList);
		va_end(argList);

		return buffer;
	}

	char* format_to_buffer_append(char* buffer, const char* fmt, ...)
	{
		va_list argList;
		va_start(argList, fmt);
		format_args_to_buffer(buffer + strlen(buffer), fmt, argList);
		va_end(argList);

		return buffer;
	}

}
