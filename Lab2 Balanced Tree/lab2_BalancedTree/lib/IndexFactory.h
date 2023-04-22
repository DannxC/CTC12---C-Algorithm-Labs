#ifndef CES12_INDEXFACTORY_H
#define CES12_INDEXFACTORY_H

#include <IndexPointsStlMultimap.h>
#include <IndexPointsAluno.h>
#include <string>

class IndexFactory {
    
public:
    static  IndexPointsAbstract* makeIndex(std::string name);
    
    
};//factory



#endif
