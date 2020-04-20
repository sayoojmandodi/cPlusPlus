#include <sys/types.h> //This header file contains definitions of a number of data types used \
                        in system calls. These types are used in the next two include files.

#include <sys/socket.h> //The header file socket.h includes a number of definitions of structures \
                        needed for sockets.

#include <netinet/in.h> //The header file in.h contains constants and structures needed for\
                         internet domain addresses.

#include <errno.h>  // To fetch standard error we can rely on this header
#include <stdio.h>  //
#include <string.h> //  For manupulation of string

#define CLIENT_PORT 8090
#define SERVER_PORT 8080
#define CLIENT_IP "127.0.0.1"
#define SERVER_IP "127.0.0.1"
#define MAX_BUFFER 256

int sockfd = 0;

enum errorCode
{
     SUCCESS = 200,
     ERROR_CREATE_SOCKET = 400,
     ERROR_CONNECT_SERVER = 401,
     ERROR_BIND_SOCKET = 402,
};

int initClientHost()
{

     printf(" --- Init ClientHost started --- \n");

     struct sockaddr_in clientAddr, serverAddr;

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0)
          return ERROR_CREATE_SOCKET;
     printf("   Socket Creation Succefull socketNo %d \n", sockfd);

     bzero((char *)&clientAddr, sizeof(clientAddr));
     clientAddr.sin_family = AF_INET;
     clientAddr.sin_addr.s_addr = inet_addr(CLIENT_IP);
     clientAddr.sin_port = htons(CLIENT_PORT);

     if (bind(sockfd, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) < 0)
          return ERROR_BIND_SOCKET;
     printf("   Bind Socket Succefull \n ");

     bzero((char *)&serverAddr, sizeof(serverAddr));
     serverAddr.sin_family = AF_INET;
     serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
     serverAddr.sin_port = htons(SERVER_PORT);

     if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
     {
          printf("   Connect Server Failed: %s \n", strerror(errno));
          return ERROR_CONNECT_SERVER;
     }

     printf("  Connect Server Successfull\n");
     printf(" --- Init ClientHost Finished --- \n\n");

     return SUCCESS;
}

int main()
{
     char buffer[MAX_BUFFER];
     int result = initClientHost();
     if (result != SUCCESS)
          printf(" --- Init ClientHost Failed --- ; Error Code is %d \n", result);
     else
     {
          do
          {
               memset(buffer, 0, MAX_BUFFER);

               printf("Enter First String :");
               scanf("%s", buffer);
               if (send(sockfd, buffer, strlen(buffer) + 1, 0) < 0)
               {
                    printf(" Error while Sending Data %s: \n ", strerror(errno));
                    break; // In case if server is not running / Forcefull termination
               }

               printf("Enter Second String :");
               scanf("%s", buffer);
               if (send(sockfd, buffer, strlen(buffer) + 1, 0) < 0)
               {
                    printf("Error while Sending Data : %s \n", strerror(errno));
                    break; // We Are forcefully terminating server
               }

               if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0)
                    printf("Error While Recieving Data %s\n Make sure client is running \n", strerror(errno));

               printf("Recieved String : %s \n\n", buffer);

          } while (strcmp(buffer, "quit") != 0);
          printf("Client Stopped \n");
     }

     close(sockfd); // closing server connection

     return 1;
}