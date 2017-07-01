#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H

#include <windows.h>
#include <mysql.h>

#include <vector>
#include <string>

using namespace std;

typedef vector<string> Strings;

class __export MySQLConnection
{
    public:
        bool connected, initialized;
        MYSQL sql;

        MySQLConnection();

        bool connect(const char* host, const char* db, const char* user, const char* passwd, unsigned int port);
        bool init();
        void close();

        Strings tables();
};

#endif
