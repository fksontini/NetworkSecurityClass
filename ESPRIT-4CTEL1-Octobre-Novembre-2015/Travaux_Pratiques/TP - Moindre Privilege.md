### Travaux Pratique - Moindre Privilège

###### DESCRIPTION:
Teser le concept du moindre privilège.

> ###### AUTEUR:
> > **Abdessabour Arous**.


> ###### NOTICE RELATIVE AU DROIT D'AUTEUR:

> >  1. Vous pouvez copier, modifier, et/ou utiliser ce documents (diapositives + manuels de TPs) pour des fins non lucratifs à condition de mentionner leur origine.
> >  2. L'auteur (Abdessabour Arous) souhaite (non obligatoire) juste qu'il soit notifier lors de l'utilisation de ces documents.
> >  3. Toute utilisation de ces documents dans des formations payantes est strictement interdite sauf après avoir reçu une autorisation écrite de l'auteur (Abdessabour Arous)


##### OUTILS
- GCC
- ProRAT
- Software Restriction Policy
- Registre de Windows
- Sql Server
- DVWA
- Metasploit

##### INSTRUCTIONS
1. CHROOT
	
	* test du chroot
	````
	$ wget https://github.com/AbMaster/NetworkSecurityClass/raw/master/ESPRIT-4CTEL1-Octobre-Novembre-2015/Divers/chrootin.c
	$ gcc -o chrootin chrootin.c
	```
	
	* S'evader du chroot
	````
	$ wget https://github.com/AbMaster/NetworkSecurityClass/raw/master/ESPRIT-4CTEL1-Octobre-Novembre-2015/Divers/chrootout.c
	$ gcc -o chrootout chrootout.c
	```

2. Compte Administrateur Vs Compte Limité
	
	* 