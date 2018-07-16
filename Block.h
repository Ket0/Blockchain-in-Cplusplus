#ifndef BLOCK_H
#define BLOCK_H

#include "iostream"

class Block
{
    public:
        Block();
        virtual ~Block();

        unsigned int Getm_idx() const { return m_idx; }
        void Setm_idx(unsigned int val) { m_idx = val; }

        std::string Getm_preHash() const { return m_preHash; }
        void Setm_preHash(std::string val) { m_preHash = val; }

        std::string Getm_timestamp() const { return m_timestamp; }
        void Setm_timestamp(std::string val) { m_timestamp = val; }

        std::string Getm_data() const { return m_data; }
        void Setm_data(std::string val) { m_data = val; }

    protected:
    private:
        unsigned int m_idx;
        std::string m_preHash;
        std::string m_timestamp;
        std::string m_data;
};

#endif // BLOCK_H
