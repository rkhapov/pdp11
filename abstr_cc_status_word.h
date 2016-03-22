#ifndef ABSTR_CC_STATUS_WORD_H
#define ABSTR_CC_STATUS_WORD_H

//Abstract status word (flag)
//word_t should be an integer type

namespace abstr_cc
{
    template <typename word_t>
    class StatusWord
    {
    public:

        //Setting bit in _flag
        void set(int flagNumber, bool value)
        {
            if (value)
                _flag |= (1 << flagNumber);
            else
                _flag &= ~(1 << flagNumber);
        }

        word_t getValue() const { return _flag; }

    private:
        word_t _flag;
    };
}

#endif // ABSTR_CC_STATUS_WORD_H

