#include "hstring.h"
#include<iostream>

//private
//获得字符长度
unsigned short hstring::GetLen(const char* cstr) const
{
	unsigned len{};
	while (cstr[len++]);
	return len;
}
//拷贝字符
void hstring::CopyStrs(char* dest, const char* source)
{
	int len = GetLen(source);
	if (len > usmlen)
	{
		delete[] cstr;
		cstr = new char[len];//re-allocation
		usmlen = len;//修正内存大小
	}
	memcpy(cstr, source, len);
	uslen = len;//放在外面是为了包含不重新分配的情况
	//uslen = sizeof(source);
	//dest = (char*)malloc(uslen);
	//for (int i = 0; i < uslen; i++)
	//dest[i] = source[i];
}


//public
//提供的getter
char* hstring::c_str()
{
	return this->cstr;
}
//构造函数们,三种构造方式
hstring::hstring()
{
	usmlen = (0x32);
	uslen = 0;
	cstr = new char(usmlen);
}
hstring::hstring(const char* _str)	
{
	cstr = (char*)_str;
}
hstring::hstring(const hstring& _str) :hstring()
{
	CopyStrs(cstr, _str.cstr);
}




hstring& hstring::operator = (const hstring& str)
{
	CopyStrs(cstr, str.cstr);
	return *this;
}

hstring& hstring::operator << (const hstring& str)
{
	unsigned short slen = GetLen(str.cstr);
	slen = uslen + slen - 1;//两个字符长度和 -1是因为两个'\0'
	if (slen > usmlen)
	{
	//	delete[] cstr;
		cstr = new char[slen];
		usmlen = slen;
	}
	memcpy(cstr + uslen - 1, str.cstr, slen - uslen + 1);
	uslen = slen;
	return *this;
}
