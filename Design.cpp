#include <iostream>

class CDatabase
{
     static CDatabase *dbInstance;
     CDatabase() = default;

protected:
     // Add method here so that only friend class can access the methood not obj;
     // REad from database
     // insert inito db
     void open()
     {
          std::cout << "Check is connection opened and Open connection";
     }
     void fetch();

public:
     static CDatabase *getInstance()
     {
          if (dbInstance != nullptr)
          {
               dbInstance = new CDatabase;
          }
          return dbInstance;
     }

     friend class CCamera;
};

CDatabase *CDatabase::dbInstance = nullptr; // static member defining outside;

class CCamera
{

protected:
     unsigned char *imagebuffer;
     int exposure;

public:
     // constructor and Destructor
     CCamera()
     {
          CDatabase::getInstance(); // whenever we create an object of CCamera const gets called and  \
                                        database instance gets created
          initDatabase(*CDatabase::dbInstance);
     };
     ~CCamera()
     {
          releaseImageBuffer();
     }

     //
     void initDatabase(CDatabase &dbObj)
     {
          dbObj.open();
     }
     // Methods to access the protected members
     void releaseImageBuffer()
     {
          delete[] imagebuffer;
     }
     void getExposrue()
     {
          //  exposure = dbPtr->fetch();
     }

     // Methods to be implemented in the derived class. Which we assumes implementation \
         will be different func name is similar
     virtual void initCam() = 0;
};

class CBaumerCam : public CCamera
{
public:
     void initCam()
     {
          std::cout << "initializing camera";
     }
};

int main()
{
     CCamera *camObjPtr = new CBaumerCam; //constr of CBaumerCam and CCamera gets called\
                                           CCcam constrt creates db instance and open connection.
     camObjPtr->initCam();

     // CCamera is  an abstract class, eventhough we can't create an obje of that class we can create a pointer \
     object for that class which points to the derived camera. and we can call its functin as shown above we \
     discussed
     return 0;
}
