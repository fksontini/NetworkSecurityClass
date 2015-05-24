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


	// The file "/temois" probably doesn't exist on your computer.
	struct stat statBuf;
	if(stat("/temois", &statBuf) == -1)
		perror("stat(/temois)");
	else
		printf("/temois");
	
	if(chroot(buf) == -1) // make the current directory be /
	{
		perror("chroot");
		printf("Etes vous root?\n");
		exit(EXIT_FAILURE);
	}

	// From this point on, this program will think that the root
	// directory "/" is this directory!
	getcwd(buf, 1024);
	printf("Reportoire current: %s\n", buf);
	// The file "/temois" should exist!
	if(stat("/temois", &statBuf) == -1)
		perror("stat(/temois)");
	else
		printf("found /temois\n");

	/* It is possible to break out of chroot using this approach. This
	 * general approach is not a secret and is documented in the
	 * chroot man page. */
	printf("Bypass du chroot....\n");
	mkdir("chroot.temp", 0777);
	chroot("chroot.temp"); // Now we are not inside of the new root!?!
	rmdir("chroot.temp"); // cleanup after ourselves

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

	// List the files in this directory so you can verify that we got
	// out.
	printf("Liste des fichiers dans le repertoire\n");
	execlp("ls", "/", NULL);
}