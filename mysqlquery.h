#ifndef MYSQLQUERY_H
#define MYSQLQUERY_H

#include "mysqlconnection.h"
#include "mysqlrow.h"

typedef vector<MySQLRow> MySQLRows;

class __export MySQLQuery
{
    public:
        MySQLQuery(MySQLConnection* con);
        ~MySQLQuery();

        MySQLRow& operator[](unsigned int i);
        bool query(const string &q);
        void free();
        unsigned int size();

    private:
        MySQLRows rows;
        MYSQL_RES *res;
        MySQLConnection* con;
};

#endif

 