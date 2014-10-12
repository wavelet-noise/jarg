#include "blockdata.h"

BlockData::BlockData()
{

}

BlockData &BlockData::operator=(const BlockData &val)
{
    if (this != &val)
    {
        m_id = val.m_id;
        name = val.name;
        description = val.description;
        color = val.color;
        symbol = val.symbol;
    }
    return *this;
}

BlockData::BlockData(const BlockData &val) :
    name(val.name),
    description(val.description),
    color(val.color),
    symbol(val.symbol),
    m_id(val.m_id)
{
}
