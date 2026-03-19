#include <sys/types.h> //This header file contains definitions of a number of data types used \
                        in system calls. These types are used in the next two include files.

#include <sys/socket.h> //The header file socket.h includes a number of definitions of structures \
                        needed for sockets.

#include <netinet/in.h> //The header file in.h contains constants and structures needed for\
                         internet domain addresses.
#include <errno.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define MAX_BUFFER 256

int newsockfd = 0;

enum errorCode
{
     SUCCESS = 200,
     ERROR_BINDING_SOCKET = 400,
     ERROR_CREATING_SOCKET = 401,
     ERROR_LISTEN_TO_CLIENT = 402,
     ERROR_ACCEPT_CLIENT = 403,
     ERROR_SETSOCKOPT = 404,
};

int initServerHost()
{

     printf(" --- Init Server Conn started --- \n");

     struct sockaddr_in serverAddr, clientAddr;

     int sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0)
          return ERROR_CREATING_SOCKET;
     printf("   SocketCreation Successfull ; SocketNo: %d ,\n", sockfd);

     bzero((char *)&serverAddr, sizeof(serverAddr));
     serverAddr.sin_family = AF_INET;
     serverAddr.sin_addr.s_addr = INADDR_ANY;
     serverAddr.sin_port = htons(SERVER_PORT);

     if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
          return ERROR_BINDING_SOCKET;

     printf("   SocketBinding Successfull\n");
     fflush(stdout); // To standard stdout buffer waits for its to get full and then dumps the output data \

     if (listen(sockfd, 5) < 0)
          return ERROR_LISTEN_TO_CLIENT;

     printf("   Listen Port Successfull \n");
     printf("   Waiting for client on  Port %d \n", SERVER_PORT);

     int clientlen = sizeof(clientAddr);

     /****** Adding Timeout For Accept Connection ******** i.e if client didn't connect \
           within in the below mentioned time , accept return error .

          struct timeval t;
          t.tv_sec = 60; // In Seconds
          t.tv_usec = 0;

          if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &t, sizeof(t)) < 0)
               return ERROR_SETSOCKOPT;

     // ********* Timeout Adding Completed ********/

     newsockfd = accept(sockfd, (struct sockaddr *)&clientAddr, &clientlen);
     if (newsockfd < 0)
          return ERROR_ACCEPT_CLIENT;
     printf("   Accept Client Successfull\n");

     /****** Adding Timeout For Send & Recv Operation *******
      
          t.tv_sec = 20; // In Seconds
          if (setsockopt(newsockfd, SOL_SOCKET, SO_RCVTIMEO, &t, sizeof(t)) < 0)
               return ERROR_SETSOCKOPT;

          if (setsockopt(newsockfd, SOL_SOCKET, SO_SNDTIMEO, &t, sizeof(t)) < 0)
               return ERROR_SETSOCKOPT;

     ****** Timeout adding Completed ********/

     printf(" --- Init Server Conn Finished --- \n\n");

     return SUCCESS;
}

int main()
{
     char str1Buffer[MAX_BUFFER];
     char str2Buffer[MAX_BUFFER];

     int result = initServerHost();
     if (result != SUCCESS)
          printf(" --- Init Server Failed --- ; Error Code is %d\n", result);
     else
     {
          while (1)
          {
               memset(str1Buffer, 0, MAX_BUFFER);
               memset(str2Buffer, 0, MAX_BUFFER);

               if (recv(newsockfd, str1Buffer, MAX_BUFFER, 0) < 0) //First String send by client'll be store in buffer1
               {
                    printf(" Error while recieving Data : %s \n ", strerror(errno));
               }
               printf("\n1st Recieved String is %s \n", str1Buffer);

               if (recv(newsockfd, str2Buffer, MAX_BUFFER, 0) < 0) //Second string send by client'll be stored in buffer2
                    printf(" Error While Recieving Data : %s\n", strerror(errno));

               printf("2nd Recieved String is %s \n", str2Buffer);

               if (strcmp(str1Buffer, "quit") == 0 || strcmp(str2Buffer, "quit") == 0) // any of input string is quit
               {
                    if (send(newsockfd, "quit", MAX_BUFFER, 0) < 0)
                         printf(" Error while sending response to client : %s \n\n", strerror(errno));
                    break;
               }
               else
               {
                    if (send(newsockfd, strcat(str1Buffer, str2Buffer), MAX_BUFFER, 0) < 0)
                    {
                         printf(" Error While sending Concatenate String to client %s \n Make Sure Client is running \n ", strerror(errno));
                         break; // Incase if client has gone down . Then recv will return -1 \
                              So we are forcefully terminating server
                    }
               }
          }
     }

     close(newsockfd); // Closing client connection
     printf("\nServer Stopped \n");
     return 1;
}