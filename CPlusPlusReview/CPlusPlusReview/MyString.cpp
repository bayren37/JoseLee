#include "MyString.h"

#include <iostream>
#include <limits>
#include <cassert>
#include <algorithm>

namespace jtd {
	constexpr auto _BLANK_ = ' ';

	MyString::MyString(const char single_character, const unsigned int duplicate_count)
	{
		if (duplicate_count == 0)
			assert(false);

		capacity_ = duplicate_count * 2;
		length_ = duplicate_count;
		contents_ = new char[capacity_];

		for (size_t i = 0; i < duplicate_count; i++)
			contents_[i] = single_character;
	}

	MyString::MyString(const char* src)
	{
		const auto srcLength = (unsigned int)::strlen(src);
		if (srcLength > UINT_MAX)
			assert(false);

		capacity_ = srcLength * 2;
		length_ = srcLength;
		contents_ = new char[capacity_];

		for (size_t i = 0; i < srcLength; i++)
			contents_[i] = src[i];
	}

	MyString::MyString(const MyString& other)
	{
		capacity_ = other.capacity_;
		length_ = other.length_;
		contents_ = new char[other.length_];
		copyContents(other);
	}

	MyString::~MyString()
	{
		delete[] contents_;
	}

	unsigned int MyString::capacity() const
	{
		return capacity_;
	}

	void MyString::reserve(const unsigned int size)
	{
		if (size < length_)
			assert(false);
		capacity_ = size;
	}

	MyString& MyString::assign(const MyString& src, const unsigned int assign_position)
	{
		return assign(src.contents_, assign_position);
	}
	MyString& MyString::assign(const char* src, const unsigned int assign_position)
	{
		const auto srcLength = ::strlen(src);
		if (assign_position + srcLength - 1 < length_) {
			for (size_t i = 0; i < srcLength; i++)
				contents_[assign_position + i] = src[i];
		}
		else {

			length_ = assign_position + srcLength;
			if (capacity_ < length_) {
				capacity_ = length_ * 2;
				reallocation(capacity_);
			}

			auto copy = MyString(*this);
			copyContents(MyString(*this));

			if (copy.strlen() < assign_position) {
				for (size_t i = copy.strlen(); i < assign_position; i++)
					contents_[i] = _BLANK_;
			}

			for (size_t i = 0; i < srcLength; i++)
				contents_[assign_position + i] = src[i];
		}
		return *this;
	}

	MyString& MyString::assign(const char src, const unsigned int assign_position)
	{
		if (assign_position < length_) {
			contents_[assign_position] = src;
		}
		else {
			auto copy = MyString(*this);

			length_ = assign_position + 1;
			if (capacity_ < length_) {
				capacity_ = length_ * 2;
				reallocation(capacity_);
			}
			copyContents(copy);

			for (size_t i = copy.strlen(); i < assign_position; i++)
				contents_[i] = _BLANK_;

			contents_[assign_position] = src;
		}
		return *this;
	}

	MyString& MyString::append(const MyString& addition)
	{
		return assign(addition, length_);
	}

	MyString& MyString::append(const char* addition)
	{
		return assign(addition, length_);
	}

	MyString& MyString::append(const char addition)
	{
		return assign(addition, length_);
	}

	MyString& MyString::insert(const MyString& src, const unsigned int insert_position)
	{
		return insert(src.contents_, insert_position);
	}

	MyString& MyString::insert(const char* src, const unsigned int insert_position)
	{
		if (insert_position < length_) {
			length_ += ::strlen(src);//TODO: implement with MyString 
			if (capacity_ < length_) {
				capacity_ = length_ * 2;
				reallocation(capacity_);
			}

			for (size_t i = length_; i > insert_position; --i)
				contents_[i] = contents_[i - ::strlen(src)];

			assign(src, insert_position);
		}
		return *this;
	}

	MyString& MyString::insert(const char src, const unsigned int insert_position)
	{
		if (insert_position < length_) {
			if (capacity_ < ++length_) {
				capacity_ = length_ * 2;
				reallocation(capacity_);
			}

			for (size_t i = length_; i > insert_position; --i)
				contents_[i] = contents_[i - 1];

			assign(src, insert_position);
		}
		return *this;
	}

	MyString& MyString::erase(const unsigned int position, const int count)
	{
		if (position > length_)
			return *this;

		if (count > 0) {
			for (int i = position; i < length_ - count; i++) {
				contents_[i] = contents_[i + count];
			}
			length_ -= count;
		}
		else {
			for (int i = position; i > -count; i--) {
				contents_[i - 1] = contents_[i + count];
			}
			length_ += count;
		}
		return *this;
	}

	int MyString::find(const MyString& str, const int find_from) const
	{
		if (str.length_ == 0 || length_ == 0)
			return -1;

		int i, j = 0;
		for (i = 0; i < length_; i++)
		{
			for (j = i; j < i + str.length_; j++)
			{
				if (str.contents_[j] != contents_[j])
					break;
			}
		}

		if (j == str.length_)
			return i;

		return -1;
	}

	int MyString::find(const char* str, const int find_from) const
	{
		return find(MyString(str), find_from);
	}

	int MyString::find(const char c, const int find_from) const
	{
		return find(MyString(c), find_from);
	}

	int MyString::compare(const MyString& str) const
	{
		if (str.length_ == 0 && length_ == 0)
			return 0;

		for (size_t i = 0; i < std::min(length_, str.length_); i++)
		{
			auto difference = contents_[i] - str.contents_[i];
			if (difference < 0)
				return -1;
			else if (difference > 0)
				return 1;
		}
		return 0;
	}

	int MyString::compare(const char* str) const
	{
		return compare(MyString(str));
	}

	void MyString::reallocation(unsigned int capacity)
	{
		delete[] contents_;
		contents_ = new char[capacity];
	}

	void MyString::copyContents(const MyString& src)
	{
		for (size_t i = 0; i < src.length_; i++)
			contents_[i] = src.contents_[i];
	}

	unsigned int MyString::strlen() const
	{
		return length_;
	}

	void MyString::print() const
	{
		for (size_t i = 0; i < length_; i++)
			std::cout << contents_[i];
	}

	void MyString::dissect() const
	{
		for (size_t i = 0; i < length_; i++)
			std::cout << contents_[i] << ' ';
		std::cout << std::endl;
	}

	char MyString::at(const unsigned int position) const
	{
		if (position > length_)
			return NULL;
		return contents_[position];
	}

}
