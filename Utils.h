#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <QCoreApplication>

using namespace std;

class Utils
{
public:
    Utils();
    static string getDir(string filename);
};

#endif // UTILS_H
