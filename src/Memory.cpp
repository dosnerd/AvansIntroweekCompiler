//
// Created by david on 21-2-19.
//

#include <Memory.h>

#include "../inc/Memory.h"

Compiler::Memory &Compiler::Memory::GetInstance() {
    static Memory instance;
    return instance;
}

Compiler::Memory::Memory()
        : m_stack(0) {

}

int Compiler::Memory::GetStack() {
    return m_stack;
}

int Compiler::Memory::GetHeap(std::string name) {
    if (!IsNameValid(name))
        throw INVALID_NAME;

    if (m_heap.find(name) == m_heap.end())
        throw VAR_NOT_FOUND;
    else
        return m_heap[name];
}

void Compiler::Memory::SetStack(int value) {
    m_stack = value;
}

bool Compiler::Memory::SetHeap(std::string name, int value) {
    if (!IsNameValid(name))
        throw INVALID_NAME;

    m_heap[name] = value;
    return true;
}

void Compiler::Memory::Reset() {
    m_stack = 0;
    m_heap.clear();
}

bool Compiler::Memory::IsNameValid(std::string name) {
    if (name.find("OUTPUT_") != 0 && name.find("INPUT_") != 0 && name[0] != '_')
        return false;

    if (name[0] == '_') return true;
    if (name[0] == 'I' && name.length() > 6) return true;

    return name[0] == 'O' && name.length() > 7;

}
