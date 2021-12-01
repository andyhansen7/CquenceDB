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

        typedef struct
        {
            DocumentEntry doc;
            bool valid;
        } DocumentReturn;
    }

    class Document
    {
    public:
        Document(const uint64_t& _id);
        ~Document() = default;

        uint64_t getID() const;

        internal::DocumentReturn getRawDocument(const std::string& field) const;
        bool updateDocument(const uint64_t _id, const std::string& field, const internal::DocumentEntry& value);
        internal::DocumentReturn removeDocument(const uint64_t _id, const std::string& field);
    private:
        // Data
        uint64_t _id;
        std::map<std::string, internal::DocumentEntry> _data;

        // Bool marked true if being written, disables reads and writes
        mutable std::atomic<bool> _writeInProgress;
        mutable std::atomic<bool> _readInProgress;
    };
}


#endif //CQUENCEDB_DOCUMENT_H
