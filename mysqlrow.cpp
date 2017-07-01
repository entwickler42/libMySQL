#include "mysqlrow.h"

//---------------------------------------------------------------------------
MySQLRow::MySQLRow() {}

//---------------------------------------------------------------------------
MySQLRow::~MySQLRow()
{
    free();
}

//---------------------------------------------------------------------------
bool MySQLRow::assign(MYSQL_RES *res)
{
    fields.clear();

    MYSQL_ROW row       = mysql_fetch_row(res);
    if(row == NULL) return false;

    unsigned int field_count = mysql_num_fields(res);
    MYSQL_FIELD *field       = mysql_fetch_fields(res);

    if(field == NULL) return false;

    for(unsigned int i=0; i<field_count; i++) fields.push_back(MySQLField(row[i],field[i].name));

    return true;
}

//---------------------------------------------------------------------------
MySQLField MySQLRow::operator[](unsigned int i)
{
    return fields[i];
}

//---------------------------------------------------------------------------
unsigned int MySQLRow::size()
{
    return fields.size();
}

//---------------------------------------------------------------------------
void MySQLRow::free()
{
    fields.clear();
}
