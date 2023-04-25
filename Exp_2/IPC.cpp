// #include <stdio.h>
// #include <unistd.h>
// #include <sys/ipc.h>
// #include <sys/msg.h>
// #include <sys/wait.h>
// #include <string.h>
// // structure for message queue 
// struct mesg_buffer { 
//     long mesg_type; 
//     char mesg_text[100]; 
// } message; 
// int main(){
//     int pid;
//     pid = fork();
//     if(pid!=0){    
//         key_t key; 
//         int msgid; 
//        // ftok to generate unique key 
//         key = ftok("progfile", 65);  
//         // creates a message queue 
//         msgid = msgget(key, 0666 | IPC_CREAT); 
//         message.mesg_type = 1; 
//         printf("Process %d, Write Data : ",getpid()); 
//         gets(message.mesg_text);
//         //Sending the message 
//         msgsnd(msgid, &message, sizeof(message), 0);
//         // display the message 
//         printf("Data send is : %s \n", message.mesg_text); 
//         wait(0);
//     }
//     else{
//         sleep(5);
//         key_t key; 
//         int msgid; 
//         key = ftok("progfile", 65); 
//         msgid = msgget(key, 0666 | IPC_CREAT); 
//         //Receiving the message 
//         msgrcv(msgid, &message, sizeof(message), 1, 0); 
//         //Displaying the message 
//         printf("Process %d, Data Received is : %s \n",getpid(),message.mesg_text);
//         //Destroying the message queue 
//         msgctl(msgid, IPC_RMID, NULL);
//     }
//     return 0; 
// }