#ifndef MYSQLROW_H
#define MYSQLROW_H

#include <windows.h>
#include <mysql.h>
#include "mysqlfield.h"

using namespace std;

typedef vector<MySQLField> MySQLFields;

class __export MySQLRow
{
    public:
        MySQLRow();
        ~MySQLRow();

        MySQLField operator[](unsigned int i);
        bool assign(MYSQL_RES *res);
        unsigned int size();
        inline void free();

    private:
        MySQLFields fields;
};


#endif
 