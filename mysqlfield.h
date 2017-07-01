#ifndef MYSQLFIELD_H
#define MYSQLFIELD_H

#include <string>
#include <vector>

using namespace std;

class __export MySQLField
{
    public:
        MySQLField(const string& s = "", const string& n = "");

        string value, name;
};

#endif

