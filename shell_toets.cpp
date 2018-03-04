#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <vector>

using namespace std;

void getOptions(int,char**,char*);

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
            /*if(argv[i][0] == '-' && (unsigned)strlen(argv[i]) == 2)
                cout << argv[i] << endl;*/

            //as dit 'n argument is
            if(argv[i][0] != '-')
                cout << argv[i] << endl;

            else 
                cout << "Don't recognize this character: " << argv[i] << endl;
        }

        //char* v = new char[3];
        vector<char> v;
        getOptions(argc, argv, v);
    }

    else // parent process
    {
    	std::cout << "Doen die parent funksie se goed." << pid << std::endl;
    }

    return EXIT_SUCCESS;
}

//&& (unsigned)strlen(_argv[i]) > 1
/*void getOptions(int _argc, char** _argv, char* _options)
{
    for(int i = 0; i < _argc; ++i)
        if(_argv[i][0] == '-')
        {
            *_options = _argv[i][1];
            cout << _options << endl;
            _options++;
        }
}/**/

/*
    - Hulle het hier waar hulle die & voor die vektor sit om te se dis die pointer na
    die vektor toe seker.
    - Doen 'n toets waar jy kyk hoe hulle die vektors tussen die funksies stuur.
*/
/*
void getOptions(int _argc, char** _argv, vector<char> &_options)
{
    for(int i = 0; i < _argc; ++i)
        if(_argv[i][0] == '-')
        {
            //die * om te se dat die waarde van die pointer is
            _options.push_back((char)_argv[i][1]);
            cout << _options[i-1] << endl;
        }
}/**/