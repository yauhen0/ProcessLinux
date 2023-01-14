#include <iostream>
#include <string>
#include <signal.h>
#include <cstring>

void kill(const char* processName)
{
    char buffer[512];
    std::string str = processName;
    FILE *cmdPipe = popen(("pidof " + str).c_str(), "r");
    fgets(buffer,512,cmdPipe);
    pid_t pid = strtoul(buffer,NULL,10);
    std::string pids = buffer;
    pclose(cmdPipe);
    char* id = strtok(&pids.front(), " ");
    while(id != NULL)
    {
        kill(std::atoi(id), SIGTERM);
        id = strtok(NULL, " ");
    }
}

void kill()
{
    char *str = getenv("PROC_TO_KILL");

    char* ptr = strtok(str, ",");
    while(ptr != NULL)
    {
        killByName(ptr);
        ptr = strtok(NULL, ",");
    }
}


int main(int argc, char* argv[]) {

    kill();

    for (int i = 0; i < argc; ++i) {
        if(!strcmp(argv[i], "--id"))
            kill(std::atoi(argv[i+1]), SIGTERM);
        if(!strcmp(argv[i], "--name"))
            kill(argv[i + 1]);
    }
}
