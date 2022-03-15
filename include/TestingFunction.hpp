/*
*TESTINGFUNCTION_HPP_FILE
*/
#ifndef TESTINGFUNCTION_HPP
#define TESTINGFUNCTION_HPP

#include "DynamicArray.h"

#include <cstddef>
#include <sstream>
#include <functional>
#include <chrono>
#include <string>
#include <random>


namespace AiSD
{

    /**@brief
    *   This function save the logs to the file
    *
    *@param src
    *   Path to the file
    *@param in
    *   Content of the log
    */
    void Log(std::string ,std::string );

    /**@brief
    *   This function is performing Dynamic Array functions by "Numero Sign".
    *   Return is transfered from DynamicArray functions but in size_t (true = 1, false = 0)
    *   Also saves all the operations to the file (LogFileName), and measures time.
    *
    *@param arr
    *   Dynamic Array pointer
    *@param NO
    *   Numero Sign of function
    *@param t
    *   First parameter
    *@param i
    *   Second parameter
    */
    size_t BridgeFunction(DynamicArray& arr,int NO,T t,size_t i);

    /**@brief
    *   Returning function of Dynamic Array indexed by NO. Depends of ARGV.
    *@param NO
    *   Number of function
    */
    function<size_t (DynamicArray& a,T t1,size_t i1)> FunctionByNO(int NO);


    /**@brief
    *   This function simulates distortions, and test potential crashes for random data entry
    *
    *@param arr
    *   Dynamic Array pointer
    *@param t
    *   number of operations
    */
    void DistortionsSimulation(DynamicArray& arr,int t);

    /**@brief
    *   Repeat the same functions until the array is full, and empty for the most pesimistic scenario. Measures time.
    *
    *@param arr
    *   Dynamic Array
    */
    void OverflowTable(DynamicArray& arr);

    /**@brief
    *   User interactions function (ENDLESS LOOP!!!)
    *@param arr
    *   Dynamic Array
    */
    void Presentation(DynamicArray& arr);

    /**@brief
    *   Small function capturing time.
    */
    auto _setNow();

    /**@brief
    *   Time between two chronotimes.
    */
    std::string _timeTook(auto a,auto b);
}



#endif // TESTINGFUNCTION_HPP
