// Abdessabour Arous
//
//
// Code repris depuis https://github.com/skuhl/sys-prog-examples/blob/master/simple-examples/chroot.c
// Merci à Mr Scott A. Kuhl, Associate Professor of Computer Science at Michigan Tech.
//
//
// Démonstration du chroot
// Usage: ./chroot
//

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	char buf[1024];
	getcwd(buf, 1024);
	printf("Repertoire current: %s\n", buf);
	
	// Le repertoire "/" va devenir dès maintenant le repertoire current
	getcwd(buf, 1024);
	printf("Repertoire current: %s\n", buf);
	// Le fichier "/temoins" doit exister!
	if(stat("/temoins", &statBuf) == -1)
		perror("stat(/temoins)");
	else
		printf("trouvé /temoins\n");
	
	if(chroot(buf) == -1) // chrooter? /
	{
		perror("chroot");
		printf("Etes vous root?\n");
		exit(EXIT_FAILURE);
	}
	
	// Reverifier
	getcwd(buf, 1024);
	printf("Repertoire current: %s\n", buf);
	
	// Lister les fichiers du repertoire current
	printf("Liste des fichiers dans le repertoire current:\n");
	execlp("ls", "/", NULL);
}