#include <iostream>

class CDatabase
{
     static CDatabase *dbPtr;
     CDatabase() = default;

protected:
     // Add method here so that only friend class can access the methood not obj;

public:
     static CDatabase *getInstance()
     {

          if (dbPtr != NULL)
          {
               dbPtr = new CDatabase;
          }
     }

     friend class CCamera;
};

class CCamera
{
     CDatabase *dbPtr;

public:
     CDatabase *initDatabase()
     {
          dbPtr = CDatabase::getInstance();
     }
};

int main()
{
     CCamera *camObjPtr = new CCamera;
     camObjPtr->initDatabase();
}