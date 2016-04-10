#ifndef ABSTR_CC_ALU_H
#define ABSTR_CC_ALU_H

//Pure abstract arithmetical and logical unit
//ALU presents methods to execute mathematical and logical expressions

#include <utility>

#include "abstr_cc_status_word.h"

namespace abstr_cc
{
    template <class word_t, class StatusWord>
    class Alu
    {
    public:
        virtual ~Alu() {}

        //Standart arithmetical function
        virtual word_t add(word_t w1, word_t w2, StatusWord &sw) const = 0;
        virtual word_t sub(word_t w1, word_t w2, StatusWord &sw) const = 0;

        //Standart logical function
        virtual word_t logicalNot(word_t w, StatusWord &sw) const = 0;
        virtual word_t logicalOr(word_t w1, word_t w2, StatusWord &sw) const = 0;
        virtual word_t logicalAnd(word_t w1, word_t w2, StatusWord &sw) const = 0;
        virtual word_t logicalXor(word_t w1, word_t w2, StatusWord &sw) const = 0;

    };
}

#endif // ABSTR_CC_ALU_H

