#include <iostream>

class CDatabase
{

protected:
     // Declare all the required variable here ...
     int database;
     int a; //will get inherited  but can't be accessed directly using obj;
     virtual SingletonWrapper *getInstance() = 0;
};

class SingletonWrapper : private CDatabase
{
     static SingletonWrapper CDBinstance; // if need to allocate on heap  declare this instance as a Pointer and \
                                   check if it is NULL or not and create a new instance based on that
     SingletonWrapper *DBgetInstance()
     {
          return &CDBinstance;
     }
     friend class CCamera;

public:
     SingletonWrapper() = default;
};

class CCamera
{

protected:
     unsigned char *imagebuffer;
     int srNo;
     int exposure;

public:
     int iwidth;
     int iheigth;
     CCamera() : exposure(0), srNo(0), iwidth(0), iheigth(0) {}
     void releaseBuffer();
     bool initDatabase(const SingletonWrapper &obj)
     {
          obj.database; //open the database connecction here
     }
};

class CBaumerCam : private CCamera
{
};

int main()
{
     // CDBWrapper cdw;
}