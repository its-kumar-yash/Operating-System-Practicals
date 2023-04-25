// Code:  fork.c
// #include <stdio.h> 
// #include <sys/types.h> 
// #include <unistd.h> 

// int main() { 
//     pid_t pid=fork();
// 	if (pid == 0) 
//     printf("This is Child, its pid is %d\n",getpid()); 

// 	else
// 	printf("This is Parent, its pid is %d\n",getpid());
		 
// 	return 0; 
// }  


// Code:wait.c
// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/wait.h>
// #include<unistd.h>

// int main(){
//     pid_t cpid;
//     if(fork()==0)
//       exit(0);
//     else
//     cpid=wait(NULL);
//     printf("Parent pid=  %d\n",getpid());
//     printf("Child pid= %d\n",cpid);

//     return 0;
// }


// Code: getpid_getppid.cpp
// #include <iostream> 
// #include <unistd.h> 
// using namespace std; 

// // Driver Code 
// int main() { 
// int pid; 
// pid = fork(); 
// If (pid == 0) { 
// cout << "\nParent Process id : " << getpid() << endl; 
// cout << "\nChild Process with parent id : " << getppid() << endl; 
// }
// return 0; 
// }


// Code:exit.cpp
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// int main(void)
// {
//         pid_t pid = fork();
//         if ( pid == 0 ){
//         exit(999);
//         }
//         int status;
//         waitpid(pid, &status, 0);
//         if ( WIFEXITED(status) )        {
//                 int exit_status = WEXITSTATUS(status);
//                 printf("Exit code: %d\n", exit_status);
//        }
//       return 0;
// }