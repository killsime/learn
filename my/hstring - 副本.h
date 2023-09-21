#pragma once

class hstring
{
private:
	unsigned short usmlen;//字符串所占内存
	unsigned short uslen;//字符串长度
	char*		   cstr;//c风格字符串
	unsigned short GetLen(const char* cstr) const;//获取字符长度(循环实现)
	void CopyStrs(char* dest, const char* sources);//拷贝字符(memcpy实现)
public:
	char* c_str();//getter
	hstring(const char* str);//利用字符串构造
	hstring(const hstring& str);//利用hstring来构造
	hstring();//预分配内存
	hstring& operator = (const hstring & str);//重载赋值运算符
	hstring& operator << (const hstring& str);//连接多个字符
};

