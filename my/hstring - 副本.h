#pragma once

class hstring
{
private:
	unsigned short usmlen;//�ַ�����ռ�ڴ�
	unsigned short uslen;//�ַ�������
	char*		   cstr;//c����ַ���
	unsigned short GetLen(const char* cstr) const;//��ȡ�ַ�����(ѭ��ʵ��)
	void CopyStrs(char* dest, const char* sources);//�����ַ�(memcpyʵ��)
public:
	char* c_str();//getter
	hstring(const char* str);//�����ַ�������
	hstring(const hstring& str);//����hstring������
	hstring();//Ԥ�����ڴ�
	hstring& operator = (const hstring & str);//���ظ�ֵ�����
	hstring& operator << (const hstring& str);//���Ӷ���ַ�
};

