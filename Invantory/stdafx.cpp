
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// Invantory.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"
CFont m_editFont;
CFont m_Font2;
CFont m_Font3;
MYSQL m_sqlCon;
CString password;
bool KCTJ=false;
bool KCLS=false;
bool LR_flag=false;
bool edit=false;
CString customer_name;
bool edit_flag=false;
void Font()
{
	m_editFont.CreatePointFont(180, "����");//һ������
	m_Font2.CreatePointFont(130, "����");//2������
	m_Font3.CreatePointFont(120, "����");//3������
}
//����Ƿ��������ݿ�
void datebase()
{
	mysql_init(&m_sqlCon);
    if(!mysql_real_connect(&m_sqlCon,"localhost","root","root","inventory",3306,NULL,0))// localhost  IP��ַ  �˺�  ����  ���ݿ�����  �˿�  
    {
		MessageBox(NULL,_T("�������ݿ�ʧ��!"),"ϵͳ��ʾ",NULL);
		CString e=mysql_error(&m_sqlCon);//��Ҫ����Ŀ�������ַ����޸�Ϊ��ʹ�ö��ֽ��ַ�������δ���á�
		MessageBox(NULL,e,"����",NULL);
		return;
	}
	else{
		/*MessageBox(NULL,"�������ݿ�ɹ�","ϵͳ��ʾ",NULL);*/
	}
	mysql_query(&m_sqlCon,"set names gbk;");//���¼����Ϣ�����ݿ��к���������ʾ������
}
