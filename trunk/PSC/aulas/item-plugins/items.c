/* 
 * ISEL - DEETC - LEIC
 * Programação em Sistemas Computacionais
 * João Trindade
 *
 * Uso de plug-ins com interface Item.
 * 
 * Desafio: alterar o código para guardar a colecção de Items, de modo
 * a que as chamadas a toString só ocorram no fim de showAllItemsInFile.
 */

#include "Item.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <dlfcn.h>
#include <assert.h>

typedef struct item_plugin {
	const char *       soname;
	void *             handle;
	CreateItemFunction createItem;
} ItemPlugin;

ItemPlugin * loadItemPlugin(const char * name, ItemPlugin * pPlugin) {
	char soname[256];

	void * dlh;
	CreateItemFunction createItem;

	sprintf(soname, "./%s.so", name);
	dlh = dlopen(soname, RTLD_NOW | RTLD_LOCAL);
	if (dlh != NULL) {
		*(void**)&createItem = dlsym(dlh, "createItem");
		if (createItem != NULL) {
			pPlugin->soname = strdup(soname);
			pPlugin->handle = dlh;
			pPlugin->createItem = createItem;
			return pPlugin;
		}
		dlclose(dlh);
	}
	return NULL;
}

void unloadItemPlugin(ItemPlugin * pPlugin) {
	assert(pPlugin->handle != NULL);
	free((void *)(pPlugin->soname));
	dlclose(pPlugin->handle);
	memset(pPlugin, 0, sizeof (ItemPlugin));
}

char * removeNL(char * str, size_t * plen) {
	if (str[*plen - 1] == '\n') {
		str[--*plen] = 0;
	}
	return str;
}

void showAllItemsInFile(FILE * f) {
	char line[256];

	ItemPlugin plugin;
	Item * pItem = NULL;

	while (fgets(line, sizeof(line), f) != NULL) {
		size_t line_len = strlen(line);
		removeNL(line, &line_len);

		if (strncmp(line, "BEGIN ", 6) == 0) {
			assert(pItem == NULL);
			/* Carregar o plugin */
			if (loadItemPlugin(line + 6, &plugin) != NULL) {
				/* Criar o Item */
				pItem = plugin.createItem();
				assert(pItem != NULL);
			} else {
				printf("Unsupported item type: \"%s\"\n", line + 6);
			}
		} else if (strncmp(line, "END", 3) == 0) {
			if (pItem != NULL) {
				char text[256];
				/* Mostrar o Item */
				pItem->vptr->toString(pItem, text, sizeof(text)); /* DESAFIO: usar toString e mostrar só no fim de showAllItemsInFile */
				puts(text);
				/* Eliminar a instância */
				pItem->vptr->destroy(pItem);
				pItem = NULL;
				/* Descarregar o plugin */
				unloadItemPlugin(&plugin);  /* DESAFIO: descarregar só no fim de showAllItemsInFile */
			}
		} else if (isalpha(line[0])) {
			if (pItem != NULL) {
				char * field = strtok(line, ":");
				if (field != NULL) {
					pItem->vptr->setField(pItem, field, strtok(NULL, ""));
				}
			}
		}

	}
}

int main(int argc, char * argv[]) {
	if (argc != 2) {
		fprintf(stderr, "use: %s file.def\n", argv[0]);
		exit(1);
	} else {
		FILE * f = fopen(argv[1], "r");
		if (f == NULL) {
			fprintf(stderr, "error: failed to open \"%s\"\n", argv[1]);
			exit(2);
		} else {
			showAllItemsInFile(f);
			fclose(f);
		}
	}
	return 0;
}
