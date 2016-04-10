#ifndef ABSTR_CC_STATUS_WORD_H
#define ABSTR_CC_STATUS_WORD_H

/*
 * Abstract status word (flag)
 * Support controling flag's bits. therefore word_t should be an integer type
 * (or other class which support <<, |, ~, &)
*/

namespace abstr_cc
{
    template <typename word_t>
    class StatusWord
    {
    public:
        virtual ~StatusWord() {}

        StatusWord():
            _flag(word_t())
        {}

        StatusWord(const word_t &flag):
            _flag(flag)
        {}

        //Setting bit in _flag
        void set(int flagNumber, bool value)
        {
            if (value)
                _flag |= (1 << flagNumber);
            else
                _flag &= ~(1 << flagNumber);
        }

        bool get(int flagNumber) const { return (_flag & (1 << flagNumber)) != 0; }

        word_t getValue() const { return _flag; }

    private:
        word_t _flag;
    };
}

#endif // ABSTR_CC_STATUS_WORD_H

