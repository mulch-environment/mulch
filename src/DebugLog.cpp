#include "DebugLog.h"

namespace mulch
{
    // Definition of static member variable
    bool DebugLog::debugMode = true;

    // Definition of static member function
    void DebugLog::setDebugMode(bool mode)
    {
        debugMode = mode;
        std::cout << debugMode << std::endl;
    }
}
