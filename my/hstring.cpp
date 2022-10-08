#include "hstring.h"
#include<iostream>

//private
//����ַ�����
unsigned short hstring::GetLen(const char* cstr) const
{
	unsigned len{};
	while (cstr[len++]);
	return len;
}
//�����ַ�
void hstring::CopyStrs(char* dest, const char* source)
{
	int len = GetLen(source);
	if (len > usmlen)
	{
		delete[] cstr;
		cstr = new char[len];//re-allocation
		usmlen = len;//�����ڴ��С
	}
	memcpy(cstr, source, len);
	uslen = len;//����������Ϊ�˰��������·�������
	//uslen = sizeof(source);
	//dest = (char*)malloc(uslen);
	//for (int i = 0; i < uslen; i++)
	//dest[i] = source[i];
}


//public
//�ṩ��getter
char* hstring::c_str()
{
	return this->cstr;
}
//���캯����,���ֹ��췽ʽ
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
	slen = uslen + slen - 1;//�����ַ����Ⱥ� -1����Ϊ����'\0'
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
