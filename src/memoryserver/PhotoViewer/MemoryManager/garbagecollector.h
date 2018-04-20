#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H

class VarStorage;
class GarbageCollector
{
public:
    GarbageCollector();
    static void deleteVariables(VarStorage * list);
};

#endif // GARBAGECOLLECTOR_H
