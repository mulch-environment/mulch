#ifndef __mulch__DebugLog_h__
#define __mulch__DebugLog_h__

#include <iostream>

namespace mulch
{
    class DebugLog
    {
    public:
        // Constructor
        DebugLog() {}

        // Overloaded operator<<
        template<typename T>
        inline DebugLog& operator<<(const T& value);

        // Static member function to set the debug mode
        static void setDebugMode(bool mode);

    private:
        static bool debugMode;  // Declaration of static member variable
    };
};

template<typename T>
inline mulch::DebugLog& mulch::DebugLog::operator<<(const T& value)
{
    if (debugMode)
    {
        std::cout << value << std::endl;
    }
    return *this;
}

#endif 

// DEBUGLOG_H

 // DEBUGLOG_H


// #ifndef __mulch__DebugLog_h__
// #define __mulch__DebugLog_h__
// #include <iostream>

// namespace mulch
// {
//     class DebugLog
//     {
//     public:
//         // Constructor
//             DebugLog() {};
//             bool debugMode = true;  // Static member variable
//             // Overloaded operator<<
//             template<typename T>
//             inline DebugLog& operator<<(const T& value);
//             void setDebugMode(bool mode) 
//             {
//                 debugMode = mode;
//             }
//     };
// };



// template<typename T>
// inline mulch::DebugLog& mulch::DebugLog::operator<<(const T& value) 
// {
//     if (debugMode) 
//     {
//         std::cout << value << std::endl;
//     }
//     return *this;
// }


// #endif // DEBUGLOG_H
