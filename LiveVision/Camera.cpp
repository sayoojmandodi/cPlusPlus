#include <iostream>

struct cameraSettings
{
     short int exposure, width, height, gain;
     cameraSettings() = default;
     cameraSettings(short int exp, short int width, short int height, short int gain)
         : exposure(exp), width(width), height(height), gain(gain) {}
};

class CDatabase
{
     static CDatabase *dbInstance;

     // Const in Private Section to avoid initialization of obj outside the class.

     CDatabase() = default;
     CDatabase(const CDatabase &dbObj) = delete;
     CDatabase(CDatabase &&dbObj) = delete;

public:
     // Declare all the required method here
     // Update database method
     // select method
     void openCon()
     {
          std::cout << "Check is connection opened and Open connection" << std::endl;
     }
     void insert()
     {
          std::cout << " Inserting Data into Database" << std::endl;
     }

     cameraSettings get(const char *printData)
     {
          std::cout << printData << std::endl;
          return cameraSettings(100, 1024, 520, 10);
     }

     static CDatabase *getInstance()
     {
          if (dbInstance == nullptr)
          {
               dbInstance = new (std::nothrow) CDatabase; // For New no need to check it's null/ new has \
                                                            its own exception handling. To make compiler know \
                                                            exceptino handling is not required (std::nothrow)
               if (dbInstance == nullptr)
               {
                    std::cout << "Heap allocation Error \n";
               }
          }
          return dbInstance;
     }
};

CDatabase *CDatabase::dbInstance = nullptr;

class CCamera
{
     // static CDatabase *dbInstance;

public:
     //ctor and dtor
     CDatabase *dbInstance;
     CCamera()
     {
          dbInstance = nullptr;
          auto &&db = CDatabase::getInstance(); // instantiate DB class and open the connectiong
          dbInstance = db;
          width = 0;
          height = 0;
          exposure = 0;
          gain = 0;
          imagebuffer = nullptr;
          initDatabase();
     }

     ~CCamera()
     {
          releaseImageBuffer();
     }

protected:
     short int width, height, exposure, gain;
     unsigned char *imagebuffer;

     void initDatabase()
     {
          CDatabase::getInstance()->openCon();
     }

     void releaseImageBuffer()
     {
          if (imagebuffer != nullptr)
          {
               delete[] imagebuffer;
               imagebuffer = nullptr;
          }
     }

     void initImageBuffer()
     {
          if (imagebuffer != nullptr)
          {
               releaseImageBuffer();
          }
          imagebuffer = new unsigned char[width * height * sizeof(unsigned char)];
     }
     void getCameraSettings()
     {
          cameraSettings camsettingObj; // = CDatabase::getInstance()->get("Exposure , width , height ");
          std::cout << "  Exposure : " << camsettingObj.exposure
                    << "  iwidth : " << camsettingObj.width
                    << "  height  : " << camsettingObj.height;
     }

public:
     virtual void initCam() = 0;
     virtual void integrateCam() = 0;
};

// CDatabase *CCamera::dbInstance = nullptr;

class CBaumerCam : public CCamera
{

public:
     void initCam() override
     {
          std::cout << "Init Camera Started" << std::endl;
          getCameraSettings();
          initImageBuffer();
          integrateCam();
          std::cout << "Init Camera Finished" << std::endl;
     }

     void integrateCam() override
     {
          std::cout << "Camera Integration Started"
                    << "------ ------------ ------"
                    << "Camera Integration Finished" << std::endl;
     }
};

int main()
{
     CCamera *camObj = new CBaumerCam();
     camObj->initCam();
     return 0;
}
