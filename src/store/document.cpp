//
// Created by andyh on 12/1/21.
//

#include "document.h"

using namespace cquence::store;

Document::Document(const uint64_t& _id)
    : _id(_id),
      _writeInProgress(false)
{

}

uint64_t Document::getID() const
{
    return _id;
}
