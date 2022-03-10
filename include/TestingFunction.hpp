/*
*TESTINGFUNCTION_HPP_FILE
*/
#ifndef TESTINGFUNCTION_HPP
#define TESTINGFUNCTION_HPP

using namespace std;


#include "DynamicArray.h"


#include <cstddef>
#include <sstream>
#include <functional>
#include <chrono>

#include <string>


namespace AiSD
{
    /**@brief
    *   This function save the logs to the file
    *
    *@param[out] src
    *   Path to the file
    *@param[out] in
    *   Content of the log
    */
    void Log(string ,string );

    /**@brief
    *   This function is performing Dynamic Array functions by "Numero Sign"
    *   Returning measured time in float
    *
    *@param[out] arr
    *   Dynamic Array pointer
    *@param[out] NO
    *   Numero Sign of function
    *@param[out] t
    *   First parameter
    *@param[out] i
    *   Secound parameter
    */
    float BridgeFunction(DynamicArray& arr,int NO,T t,size_t i);

    /**@brief
    *   This function simulates distortions, and test potential crashes for random data entry
    *   Its measures time of the operation and log it to the log.txt file
    *
    *@param[out] arr
    *   Dynamic Array pointer
    *@param[out] t
    *   number of operations
    */
    void DistortionsSimulation(DynamicArray& arr,int t);

}

#endif // TESTINGFUNCTION_HPP