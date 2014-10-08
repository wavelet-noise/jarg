#ifndef BLOCKDATABASE_H
#define BLOCKDATABASE_H
#include "blockdata.h"
#include <unordered_map>
#include <vector>
#include <QJsonObject>

class BlockDataBase
{
public:
        static BlockDataBase& Instance()
        {
                static BlockDataBase theSingleInstance;
                return theSingleInstance;
        }

        std::unordered_map<std::string, int> refs;
        std::vector<BlockData> data;

        void load();

private:
        BlockDataBase(){};
        BlockDataBase(const BlockDataBase& root);
        BlockDataBase& operator=(const BlockDataBase&);

        void write(QJsonObject &json);
};

#endif // BLOCKDATABASE_H