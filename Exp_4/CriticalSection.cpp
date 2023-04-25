// The program defines two functions process1 and process2, which are two threads that will execute concurrently. Each thread contains a for loop that executes the critical section of code. In this case, the critical section is simply a print statement that displays a message on the console.

// The main function prompts the user to enter the number of times each thread should enter the critical section. It then creates two arrays of threads t1 and t2 with num elements each. The for loop creates num threads for each array, where each thread runs either the process1 or process2 function.

// To prevent race conditions, where both threads try to access the critical section simultaneously, the lock_guard object is used to acquire a lock on the mutexLock mutex before entering the critical section. This guarantees that only one thread can execute the critical section at a time. After the critical section has been executed, the lock is automatically released when the lock_guard object goes out of scope.

// Finally, the program waits for all threads to finish executing using the join method. When all threads have completed, the program prints a message indicating that execution is complete, and then returns 0 to exit the program.

// Overall, this program demonstrates how to use mutex locks to solve the critical section problem in a multi-threaded environment.

// #include <iostream>
// #include <thread>
// #include <mutex>
// using namespace std;
// std::mutex mutexLock;

// void process1(){
//     for (int i = 0; i < 5; i++){
//         std::lock_guard<std::mutex> lock(mutexLock);
//         std::cout << "Process 1 is in critical section.\n";
//     }
// }
// void process2(){
//     for (int i = 0; i < 5; i++){
//         std::lock_guard<std::mutex> lock(mutexLock);
//         std::cout << "Process 2 is in critical section.\n";
//     }
// }
// int main(){
//     int num;
//     std::cout << "Enter the number of times each process should enter the critical section: ";
//     std::cin >> num;
//     std::thread t1[num], t2[num];
//     for (int i = 0; i < num; i++){
//         t1[i] = std::thread(process1);
//         t2[i] = std::thread(process2);
//     }
//     for (int i = 0; i < num; i++){
//         t1[i].join();
//         t2[i].join();
//     }
//     std::cout << "Execution complete.\n";
//     return 0;
// }