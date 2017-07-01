#include "mysqlconnection.h"

//---------------------------------------------------------------------------
MySQLConnection::MySQLConnection()
{
    connected   = false;
    initialized = false;
}

//---------------------------------------------------------------------------
bool MySQLConnection::init()
{
    initialized = (mysql_init(&sql) != NULL);
    return initialized;
}

//---------------------------------------------------------------------------
bool MySQLConnection::connect(const char* host, const char* db, const char* user, const char* passwd, unsigned int port)
{
    if (initialized) connected = (mysql_real_connect(&sql,host,user,passwd,db,port,NULL,0) !=NULL);
    return connected;
}

//---------------------------------------------------------------------------
void MySQLConnection::close()
{
    if(connected == true)
    {
        mysql_close(&sql);
        connected = false;
    }
}

//---------------------------------------------------------------------------
Strings MySQLConnection::tables()
{
    Strings vTables;

    if( connected )
    {
        MYSQL_RES *res = NULL;
        MYSQL_ROW row;

        res = mysql_list_tables(&sql,"%");

        while( (row = mysql_fetch_row(res)) != NULL ) vTables.push_back(row[0]);

        mysql_free_result(res);
    }

    return vTables;
}

