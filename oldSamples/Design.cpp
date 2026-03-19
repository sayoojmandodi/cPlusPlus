#include <iostream>

class CDatabase
{
     static CDatabase *dbInstance;
     int x;

     // Const in Private Section to avoid initialization of obj outside the class.
     CDatabase() = default;
     CDatabase(const CDatabase &dbObj) = delete;
     CDatabase(CDatabase &&dbObj) = delete;

     // Declare all the required method here
     // Update database method
     // select method
     void openCon()
     {
          std::cout << "Check is connection opened and Open connection";
     }
     int fetch();

public:
     static CDatabase &getInstance()
     {
          if (dbInstance != nullptr)
          {
               dbInstance = new CDatabase;
               if (dbInstance == nullptr)
               {
                    std::cout << "Heap allocation Error \n";
               }
          }
          return *dbInstance;
     }

     // Need to add the classes as friend which is going to do DB operations.
     friend class CCamera;
};

CDatabase *CDatabase::dbInstance = nullptr; // static member defining outside;

class CCamera
{

protected:
     unsigned char *imagebuffer;
     short int exposure;

public:
     // constructor and Destructor

     CCamera()
     {
          imagebuffer = new unsigned char[1024 * 1024];
          ; // whenever we create an object of CCamera const gets called and  \
                                        database instance gets created
          CDatabase::getInstance().openCon();
     };
     ~CCamera()
     {
          releaseImageBuffer();
     }

     // Methods to access the protected members
     void releaseImageBuffer()
     {
          delete[] imagebuffer;
     }
     void getExposrue()
     {
          exposure = CDatabase::getInstance().fetch();
     }

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
     return 0;
}