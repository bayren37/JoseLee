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