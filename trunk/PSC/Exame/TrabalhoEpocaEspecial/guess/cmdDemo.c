#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "command.h"


CmdFx cmds[] = {
  { "exit",  0, 		"Terminate demo" },
  { "help",  help, 	0 },
  { "exec",  system, "Execute system command" },
  {0,0,0}  /*End of comands*/
};

int main(int argc, char * argv[]) {
  command("> ",cmds);
  return 0;
}
