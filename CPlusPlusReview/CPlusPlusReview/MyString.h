#pragma once
/*
*	Constructor https://modoocode.com/188#page-heading-4
*	
*	����(char) �� ������ ���ڿ� ����, C ���ڿ� (char *) �� ������ ����
*	���ڿ� ���̸� ���ϴ� �Լ�
*	���ڿ� �ڿ� �ٸ� ���ڿ� ���̱�(append)
*	���ڿ� ���� ���ԵǾ� �ִ� ���ڿ� ���ϱ�
*	���ڿ��� ������ ��
*	���ڿ� ũ�� �� (���� ��)
*/

namespace jtd {

	class MyString {
	public:
		MyString(const char single_character);
		MyString(const char single_character, const unsigned int duplicate_count);
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

		//MyString& erase(const unsigned int position, const int count);

		//unsigned int find(const int find_from, const MyString& str) const;
		//unsigned int find(const int find_from, const char* str) const;
		//unsigned int find(const int find_from, const char c) const;

		//int compare(const MyString& src) const;
		//int compare(const char* src) const;
	
	private:
		void initializeContents(unsigned int capacity);
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