#include "Utils.h"

Utils::Utils()
{

}

string Utils::getDir(string filename)
{
    string dir = QCoreApplication::applicationDirPath().toStdString() + "/" + filename;
    return dir;
}
