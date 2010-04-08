#include <stdio.h>
#include <string.h>
#include "command.h"
#include "readline.h"

#define MAX_LINE 255

static CmdFx *cmds;

int help(const char *cmd) {
  CmdFx *c;
  if (!cmds) return 1;
  for ( c=cmds ; c->command ; ++c ) {
    if (!*cmd || !strcmp(cmd,c->command)) {
      printf("%s",c->command);
      if ( c->description ) printf("\t- %s.\n",c->description);
      else putchar('\n');
    }
  }
  return 0;
}

int command(const char *prompt, CmdFx *commands) {
  char line[MAX_LINE+1], *arg;
  CmdFx *c;
  cmds = commands;
  while(printf("%s",prompt),readline(line,MAX_LINE)) {
    for(arg=line ; *arg ; ++arg )
      if (*arg==' ') { *arg=0; ++arg; break; }
    for ( c=cmds ; c->command ; ++c ) {
      if ( !strcmp(line,c->command) ) {
        if (!c->fx || c->fx(arg)) return 1;
        break;
      }
    }
    if (!c->command) printf("%s ?\n",line);
  }
  return 0;
}

