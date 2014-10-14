#ifndef JATLAS_H
#define JATLAS_H

#include <QObject>
#include <QHash>
#include <QMutex>
#include <QDebug>
#include <QRectF>
#include <QtOpenGL>

class JAtlas : public QObject
{
    Q_OBJECT
public:
    static JAtlas *instance(QObject *parent = nullptr)
    {
        static QMutex mutex;
        if(!m_inst)
        {
            mutex.lock();

            if (!m_inst)
                m_inst = new JAtlas(parent);

            mutex.unlock();
            qDebug() << "making JAtlas instance";
        }
        return m_inst;
    }

    void load();

    static void drop()
    {
        static QMutex mutex;
        mutex.lock();
        delete m_inst;
        m_inst = nullptr;
        mutex.unlock();
        qDebug() << "droping JAtlas instance";
    }

    QHash<QString, QVector2D> sources;
    QPixmap *image;
private:
    static JAtlas *m_inst;
    JAtlas(QObject *parent = nullptr);
    ~JAtlas();
    JAtlas &operator=(const JAtlas&);
signals:

public slots:

};

#endif // JATLAS_H
