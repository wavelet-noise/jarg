#include "level.h"

Level::Level(QObject *parent) :
    QObject(parent),
    worker(nullptr)
{
    toRender = new SectorList;
}

void Level::render()
{
    for(Sector *a : toRender->data)
    {
        a->render();
    }
}

void Level::preload(int x, int y)
{
    toRender->data.push_back(worker->getSector(x, y));
}

void Level::setWorker(LevelWorker *w)
{
    worker = w;
}