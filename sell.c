#include <stdio.h>
#include <stdlib.h>

int main()
{
        /*char *command = NULL;
        size_t len = 0;*/

        setenv(" MY_VAR ", "hello world", 1);
        char* path = getenv( "MY_VAR" );
        printf("MY_VAR: %s\n", path);


        /*while (true)
        {
                // user_input = read_input()
                // parsed_input = parse_input(user_input)
                // action
                //
                // *ENVIRONMENT*
                // A collection of key-value pairs that represent various system settings, such as the current working directory, the path to the system binaries, and so on.
                // By default, when a process is started, it inherits the environment of its parent process.
                printf("EMMYtech ");
                getline(&command, &len, stdin);
                printf("%s", command);
        }
        free(command);*/
        return (0);
}

