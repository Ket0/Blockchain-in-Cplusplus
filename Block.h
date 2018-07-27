#ifndef BLOCK_H
#define BLOCK_H

#include "iostream"

class Block{
    public:
        Block();
        Block(unsigned int p_idx, std::string p_preHash, std::string p_time , std::string p_hash);
        ~Block();

        const unsigned int Getm_idx() const { return m_idx; }
        void Setm_idx(unsigned int val) { m_idx = val; }
        const std::string Getm_preHash() const { return m_preHash; }
        void Setm_preHash(std::string val) { m_preHash = val; }
        const std::string Getm_timestamp() const { return m_timestamp; }
        void Setm_timestamp(std::string val) { m_timestamp = val; }
        const std::string Getm_data() const { return m_data; }
        void Setm_data(std::string val) { m_data = val; }
        const std::string Getm_blockhash() const { return m_blockhash; }
        void Setm_blockhash(std::string val) { m_blockhash = val; }

    private:
        unsigned int m_idx;
        std::string m_preHash;
        std::string m_timestamp;
        std::string m_data;
        std::string m_blockhash;

        /* GENESIS BLOCK
        const unsigned int m_idx = 0;
        const std::string m_preHash = "0";
        const std::string m_timestamp ="01012018";
        const std::string m_data = "The Times 03/Jan/2009 Chancellor on brink of second bailout for banks.";
        const std::string m_blockhash = genHash(B0);
        */

};
#endif // BLOCK_H
