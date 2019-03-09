//
// Created by david on 21-2-19.
//

#ifndef COMPILER_MEMORY_H
#define COMPILER_MEMORY_H

#include <map>
#define INVALID_NAME                std::string("INVALID_NAME")
#define VAR_NOT_FOUND               std::string("VAR_NOT_FOUND")

namespace Compiler {
    class Memory {
    public:
        static Memory&                      GetInstance();


#ifdef TESTING
    public:
#else
    private:
#endif
                                            Memory();
                                            ~Memory() = default;

    public:
        int                                 GetStack();
        int                                 GetHeap(std::string name);

    public:
        void                                SetStack(int value);
        bool                                SetHeap(std::string name, int value);
        void                                Reset();

    public:
        const std::map<std::string, int>&   GetHeap() const { return m_heap; };

    private:
        int                                 m_stack;
        std::map<std::string, int>          m_heap;

    private:
        bool                                IsNameValid(std::string name);
    };
};


#endif //COMPILER_MEMORY_H
