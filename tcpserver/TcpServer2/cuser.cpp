#include "cuser.h"

CUser::CUser()
{
    strcpy(m_userName,"");
    strcpy(m_password,"");
    prop = 'l';
}

CUser::CUser(char* strName,char* strPassWord)
{
    strcpy(m_userName,strName);
    strcpy(m_password,strPassWord);
    prop = 'l';
}

char* CUser::getUserName()
{
    return m_userName;
}

void CUser::setUserName(char* strName)
{
    strcpy(m_userName,strName);
}

char* CUser::getPassWord()
{
    return m_password;
}

void CUser::setPassWord(char* strPassWord)
{
    strcpy(m_password,strPassWord);
}

char CUser::getProp()
{
    return prop;
}

void CUser::setProp(char chprop)
{
    prop = chprop;
}
