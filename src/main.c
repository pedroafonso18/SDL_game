#define MATE_IMPLEMENTATION
#include "../include/mate.h"

i32 main() {
  StartBuild();
  {
    Executable executable = CreateExecutable(
        (ExecutableOptions){.output = "main", .flags = "-Wall -Werror"});

    AddFile(executable, "./src/*.c");
    AddIncludePaths(executable, "/usr/include/SDL3");

    InstallExecutable(executable);

    RunCommand(executable.outputPath);
  }
  EndBuild();
}
