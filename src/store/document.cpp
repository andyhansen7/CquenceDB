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
    while(!_writeInProgress);

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
