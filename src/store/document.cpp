//
// Created by andyh on 12/1/21.
//

#include "document.h"

using namespace cquence::store;

Document::Document(const uint64_t& _id)
    : _id(_id),
      _writeInProgress(false),
      _readInProgress(false)
{

}

uint64_t Document::getID() const
{
    return _id;
}

internal::DocumentReturn Document::getRawDocument(const std::string& field) const
{
    while(_writeInProgress);

    _readInProgress = true;

    if(_data.find(field) == _data.end())
    {
        _readInProgress = false;
        internal::DocumentReturn ret;
        ret.valid = false;
        return ret;
    }
    else
    {
        const auto doc = _data.at(field);
        _readInProgress = false;
        internal::DocumentReturn ret;
        ret.doc = doc;
        ret.valid = true;
        return ret;
    }
}

bool Document::updateDocument(const uint64_t _id, const std::string& field, const internal::DocumentEntry& value)
{
    while(_readInProgress);

    _writeInProgress = true;

    if(_data.find(field) == _data.end())
    {
        _data.emplace(field, value);
        return true;
    }
    else
    {
        _data.at(field) = value;
        return true;
    }
}

internal::DocumentReturn Document::removeDocument(const uint64_t _id, const std::string& field)
{
    while(_readInProgress);

    _writeInProgress = true;

    if(_data.find(field) == _data.end())
    {
        _writeInProgress = false;
        internal::DocumentReturn ret;
        internal::DocumentEntry entry;
        entry.raw = {};
        entry.type = DataTypes::_T_NULL;
        ret.doc = entry;
        ret.valid = false;
        return ret;
    }
    else
    {
        const auto doc = _data.at(field);
        _data.erase(field);
        _writeInProgress = false;
        internal::DocumentReturn ret;
        ret.doc = doc;
        ret.valid = true;
        return ret;
    }
}

