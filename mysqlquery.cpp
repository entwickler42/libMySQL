#include "mysqlquery.h"
#include <stdio.h>

//---------------------------------------------------------------------------
MySQLQuery::MySQLQuery(MySQLConnection* con)
{
    MySQLQuery::res     = NULL;     MySQLQuery::con     = con;
}

//---------------------------------------------------------------------------
MySQLQuery::~MySQLQuery()
{
    free();
}

//---------------------------------------------------------------------------
bool MySQLQuery::query(const string &q)
{
    bool ret = false;

    rows.clear();

    if(con->connected)
    {
        if(mysql_real_query(&con->sql, q.c_str(), q.length()) == 0) ret = true;
        res = mysql_store_result(&con->sql);

        if( res != NULL )
        {
            MySQLRow row;
            while(row.assign(res)) rows.push_back(row);

            mysql_free_result(res);
            res = NULL;
        }
    }

    return ret;
};

//---------------------------------------------------------------------------
void MySQLQuery::free()
{
    if( res != NULL )
    {
        mysql_free_result(res);
        res = NULL;
    }
    rows.clear();    
}

//---------------------------------------------------------------------------
MySQLRow& MySQLQuery::operator[](unsigned int i)
{
    return rows[i];
}

//---------------------------------------------------------------------------
unsigned int MySQLQuery::size()
{
    return rows.size();
}
