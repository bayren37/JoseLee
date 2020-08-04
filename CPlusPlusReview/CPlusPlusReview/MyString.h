#pragma once
/*
*	Constructor https://modoocode.com/188#page-heading-4
*	
*	문자(char) 로 부터의 문자열 생성, C 문자열 (char *) 로 부터의 생성
*	문자열 길이를 구하는 함수
*	문자열 뒤에 다른 문자열 붙이기(append)
*	문자열 내에 포함되어 있는 문자열 구하기
*	문자열이 같은지 비교
*	문자열 크기 비교 (사전 순)
*/

namespace jtd {

	class MyString {
	public:
		MyString(const char single_character, const unsigned int duplicate_count = 1);
		MyString(const char* src);
		MyString(const MyString& other);
		~MyString();

		unsigned int capacity() const;
		void reserve(const unsigned int size);

		MyString& assign(const MyString& src, const unsigned int assign_position);
		MyString& assign(const char* src, const unsigned int assign_position);
		MyString& assign(const char src, const unsigned int assign_position);

		MyString& append(const MyString& addition);
		MyString& append(const char* addition);
		MyString& append(const char addition);

		MyString& insert(const MyString& src, const unsigned int insert_position);
		MyString& insert(const char* src, const unsigned int insert_position);
		MyString& insert(const char src, const unsigned int insert_position);

		MyString& erase(const unsigned int position, const int count);

		int find(const MyString& str, const int find_from) const;
		int find(const char* str, const int find_from) const;
		int find(const char c, const int find_from) const;
		
		int compare(const MyString& str) const;
		int compare(const char* str) const;
	
	private:
		void reallocation(unsigned int capacity);
		void copyContents(const MyString& src);

	public:
		unsigned int strlen() const;
		void print() const;
		void dissect() const;
		char at(const unsigned int position) const;

	private:
		char*			contents_;
		unsigned int	length_;
		unsigned int	capacity_;
	};
}