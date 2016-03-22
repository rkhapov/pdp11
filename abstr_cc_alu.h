#ifndef ABSTR_CC_ALU_H
#define ABSTR_CC_ALU_H

//Pure abstract arithmetical and logical unit
//ALU presents methods to execute mathematical and logical expressions

#include <utility>

#include "abstr_cc_status_word.h"

namespace abstr_cc
{
    template <class word_t>
    class Alu
    {
    public:

        //Standart arithmetical function
        //Returns result and new flags
        typedef std::pair<word_t, StatusWord<word_t> > result_t;

        virtual result_t add(const word_t &w1, const word_t &w2) const = 0;
        virtual result_t sub(const word_t &w1, const word_t &w2) const = 0;
        virtual result_t mul(const word_t &w1, const word_t &w2) const = 0;

        //Div returns quotient and modulo obtained by dividing
        virtual std::pair<std::pair<word_t, word_t>, StatusWord<word_t> > div(const word_t &w1, const word_t &w2) = 0;


        //Standart logical function

        virtual result_t logicalNot(const word_t &w) const = 0;
        virtual result_t logicalOr(const word_t &w1, const word_t &w2) const = 0;
        virtual result_t logicalAnd(const word_t &w1, const word_t &w2) const = 0;
        virtual result_t logicalXor(const word_t &w1, const word_t &w2) const = 0;


        //bit operation
        virtual result_t bitLeftShift(const word_t &w, int n) const = 0;
        virtual result_t bitRightShift(const word_t &w, int n) const = 0;
    };
}

#endif // ABSTR_CC_ALU_H

