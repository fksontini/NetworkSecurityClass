// Abdessabour Arous
//
//
// Code repris depuis https://github.com/skuhl/sys-prog-examples/blob/master/simple-examples/chroot.c
// Merci à Mr Scott A. Kuhl Associate Professor of Computer Science at Michigan Tech.
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
	printf("Reportoire current: %s\n", buf);


	// Le fichier "/temois" n'existe pas dans notre système.
	struct stat statBuf;
	if(stat("/temois", &statBuf) == -1)
		perror("stat(/temois)");
	else
		printf("/temois");
	
	if(chroot(buf) == -1) // chrooter? /
	{
		perror("chroot");
		printf("Etes vous root?\n");
		exit(EXIT_FAILURE);
	}

	// Le repertoire "/" va devenir dès maintenant le repertoire current
	getcwd(buf, 1024);
	printf("Reportoire current: %s\n", buf);
	// Le fichier "/temois" doit exister!
	if(stat("/temois", &statBuf) == -1)
		perror("stat(/temois)");
	else
		printf("found /temois\n");

	/* Technique de bypass du chroot documentée dans la chroot man page. */
	printf("Bypass du chroot....\n");
	mkdir("chroot.temp", 0777);
	chroot("chroot.temp"); // Maintenant nous nous sommes plus à l'interrieur du chroot!?!
	rmdir("chroot.temp"); // nettoyage

	getcwd(buf, 1024);
	printf("Reportoire current (technique de bypasse 1): %s\n", buf);

	// Essayer de changer de repertoire vers le racine reel.
	chdir("../../../../../../../../../../../../../../");

	getcwd(buf, 1024);
	printf("Reportoire current (technique de bypasse 2): %s\n", buf);

	// Sommes nous sortie du chroot?
	chroot(".");
	getcwd(buf, 1024);
	printf("Reportoire current (technique de bypasse 3): %s\n", buf);

	// Lister les fichiers pour vérifier que nous sommes plus à l'intérieur du chroot
	// out.
	printf("Liste des fichiers dans le repertoire\n");
	execlp("ls", "/", NULL);
}