//
// Created by andyh on 12/1/21.
//

#ifndef CQUENCEDB_DOCUMENT_H
#define CQUENCEDB_DOCUMENT_H

// Store
#include <store/data_types.h>

// STL
#include <map>
#include <string>
#include <vector>
#include <atomic>
#include <cstddef>

namespace cquence::store
{
    namespace internal
    {
        typedef struct
        {
            std::vector<std::byte> raw;
            DataTypes type;
        } DocumentEntry;
    }

    class Document
    {
    public:
        Document(const uint64_t& _id);
        ~Document() = default;

        uint64_t getID() const;
    private:
        // Data
        uint64_t _id;
        std::map<std::string, internal::DocumentEntry> _data;

        // Bool marked true if being written, disables reads and writes
        std::atomic<bool> _writeInProgress;
    };
}


#endif //CQUENCEDB_DOCUMENT_H
