//#ifndef CUSER
//#define CUSER
#pragma once
#include <string.h>

class CUser
{
protected:
    char m_userName[20];
    char m_password[20];
    char prop;
public:
    CUser();
    CUser(char* strName,char* strPassWord);
    char* getUserName();
    void setUserName(char* strName);
    char* getPassWord();
    void setPassWord(char* strPassword);
    char getProp();
    void setProp(char chprop);
};

//#endif // CUSER

