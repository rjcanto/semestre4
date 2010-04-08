

typedef struct _cmdFx {
  char *command;         		/* Command name */
  int (*fx)(const char *arg); /* Function pointer to execute */
  char *description;          /* Help description */
} CmdFx;

int command(const char *prompt, CmdFx * cmds);

int help(const char *cmd);

