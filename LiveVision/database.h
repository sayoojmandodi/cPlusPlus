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

public:
     CDatabase() = default;
     CDatabase(const CDatabase &dbObj) = delete;
     CDatabase(CDatabase &&dbObj) = delete;

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
