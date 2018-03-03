#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
    pid_t pid; // integer that can store a process ID (use pid_t for portability)

    if ((pid = fork()) == -1) // system functions also set a variable called "errno"
    {
        perror("fork"); // this function automatically checks "errno"
        // and prints the error plus what you give it
        return EXIT_FAILURE;
    }
// ---- by when you get here there will be two processes
    /*
		Hy voer eers die parent proses uit en dan kom hy later weer terug vir die ander een.
		Dis asof hy in 'n loop is maar ek weet nie wat aangaan nie.
    */
    if (pid == 0) // child process
    {
        cout << "Input parameters:" << endl;
        for(int i = 0; i < argc; ++i)
        {
        	//cout << argv[i][0] << endl;

            //as dit 'n option is
            if(argv[i][0] == '-' && (unsigned)strlen(argv[i]) == 2)
                cout << argv[i] << endl;

            //as dit 'n argument is
            else if(argv[i][0] != '-')
                cout << argv[i] << endl;

            else 
                cout << "Don't recognize this character: " << argv[i] << endl;
        }
    }

    else // parent process
    {
    	std::cout << "Doen die parent funksie se goed." << pid << std::endl;
    }

    return EXIT_SUCCESS;
}