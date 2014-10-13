#ifndef BLOCKDATABASE_H
#define BLOCKDATABASE_H
#include "blockdata.h"
#include <unordered_map>
#include <vector>
#include <QJsonObject>

class BlockDataBase : public QObject
{
        Q_OBJECT
public:

        static BlockDataBase *instance()
        {
            static QMutex mutex;
            if(!m_inst)
            {
                mutex.lock();

                if (!m_inst)
                    m_inst = new BlockDataBase();

                mutex.unlock();
            }
            return m_inst;
        }

        static void drop()
        {
            static QMutex mutex;
            mutex.lock();
            delete m_inst;
            m_inst = nullptr;
            mutex.unlock();
        }

        static BlockData *getBlockData(const QString &id)
        {
            auto a = BlockDataBase::instance();
            if(a->data.contains(id))
                return a->data[id];
            return a->data["error"];
        }

        QMap<QString, BlockData*> data;

        void load();

private:
        BlockDataBase();
        ~BlockDataBase();
        BlockDataBase(const BlockDataBase &root);
        BlockDataBase &operator=(const BlockDataBase &);

        static BlockDataBase *m_inst;
};

#endif // BLOCKDATABASE_H
