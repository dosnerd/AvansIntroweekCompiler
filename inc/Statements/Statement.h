//
// Created by david on 21-2-19.
//

#ifndef COMPILER_STATEMENT_H
#define COMPILER_STATEMENT_H

#include "../Memory.h"
#define INVALID_COUNT_PARAMS        std::string("INVALID_COUNT_PARAMS")
#define INVALID_PARAM(PARAM)        (std::string("INVALID_PARAM_") + std::to_string(PARAM))

namespace Compiler {
    namespace Statements {
        class Statement {
        protected:
                                        Statement();
            virtual                     ~Statement();

        public:
            virtual bool                Execute() = 0;

        protected:
            const Memory&               GetMemory() const;
            Memory&                     GetMemory();

#ifdef TESTING
        public:
            void                        SetMemory(Memory *memory);
#endif

        private:
#ifdef TESTING
            Memory                      *m_memory;
#endif
        };
    };
};


#endif //COMPILER_STATEMENTS_H
