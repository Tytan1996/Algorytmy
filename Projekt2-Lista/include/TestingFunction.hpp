//Algorytmy Dynamiczna Tablica
//Damian Szopinski 185394
//Maciej Pestka 170088

/*
*TESTINGFUNCTION_HPP_FILE
*/
#ifndef TESTINGFUNCTION_HPP
#define TESTINGFUNCTION_HPP

#include "DoublyLinkedList.h"

#include <cstddef>
#include <sstream>
#include <functional>
#include <chrono>
#include <string>
#include <random>
#include <variant>
#include <limits>
#include <windows.h>

#include <memory>

#include "Logger.hpp"



namespace AiSD
{
    using T=Record;
    struct noneV{};

    class ClassTest
    {
    public:
        std::unique_ptr<DLL> pointer;
        ClassTest()
        {
            pointer=std::unique_ptr<DLL>(new DLL());
        }
        virtual void test(bool debugMode);
        using arg_t = std::variant <bool, T, size_t,noneV>;
        using return_t = std::function<arg_t(DLL& a,T t1,size_t i1)>;
        struct FunctionInfo
        {
            std::string type;
            return_t func;
        };
        FunctionInfo FunctionByNO(short int NO);

        arg_t DoFunction(DLL& arr,short int NO,T t,size_t i,bool debugMode);
    };

    class OverflowTable : public ClassTest
    {
        int repeat;
    public:
        OverflowTable(int repeatOperation):ClassTest()
        {
            repeat=repeatOperation;
        }

        void test(bool debugMode) override;
    };

    class DistortionsSimulation : public ClassTest
    {
    private:
        int t;
    public:
        DistortionsSimulation(int NumberOfOperations):ClassTest()
        {
            t=NumberOfOperations;
        }
        void test(bool debugMode) override;

        std::string randomStringGenerator();
        void doMultipleTimes(unsigned int times,bool debugMode);
    };

    class Presentation : public ClassTest
    {
    public:
        Presentation():ClassTest(){}
        void test(bool debugMode) override;
        template<typename G> G getNum();
    };
}



#endif // TESTINGFUNCTION_HPP
