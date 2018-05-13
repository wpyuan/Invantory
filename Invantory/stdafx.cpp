
// stdafx.cpp : 只包括标准包含文件的源文件
// Invantory.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

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
	m_editFont.CreatePointFont(180, "宋体");//一级标题
	m_Font2.CreatePointFont(130, "宋体");//2级标题
	m_Font3.CreatePointFont(120, "宋体");//3级标题
}
//检测是否连接数据库
void datebase()
{
	mysql_init(&m_sqlCon);
    if(!mysql_real_connect(&m_sqlCon,"localhost","root","root","inventory",3306,NULL,0))// localhost  IP地址  账号  密码  数据库名称  端口  
    {
		MessageBox(NULL,_T("访问数据库失败!"),"系统提示",NULL);
		CString e=mysql_error(&m_sqlCon);//需要将项目属性中字符集修改为“使用多字节字符集”或“未设置”
		MessageBox(NULL,e,"错误",NULL);
		return;
	}
	else{
		/*MessageBox(NULL,"连接数据库成功","系统提示",NULL);*/
	}
	mysql_query(&m_sqlCon,"set names gbk;");//解决录入信息到数据库中后汉字乱码显示的问题
}
