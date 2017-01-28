#ifndef DSU_EXCEPTIONS_H
#define DSU_EXCEPTIONS_H

#include <exception>
using namespace std;

/*this exceptions are used for DSU implementation*/

/*when item out of DSU range*/
class _out_of_range : public exception
{
    public:
        const char* what()const throw()
        {
            return "Item is out of range";
        }
};

/*when item is absent in the union*/
class item_is_absent : public exception
{
    public:
        const char* what()const throw()
        {
            return "Item is absent";
        }
};

#endif // DSU_EXCEPTIONS_H
