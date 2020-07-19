#pragma once
/*
*	Copy Constructor https://modoocode.com/188#page-heading-4
*	�����غ���
*	�Ʒ��� ���� ���ڿ� Ŭ������ �ϼ��غ����� (���̵� : ��)
*/

namespace MyString {

	class string {
	public:
		string(const char character, const unsigned int duplicateCount);
		string(const char* string);
		string(const string& other);
		~string();

		void append(const string& s);
		void copy(const string& src);
		unsigned int strlen();

	private:
		char* string_;
		int length_;
	};

	void copy(const string& src, string& dest);
}