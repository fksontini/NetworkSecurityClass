### Travaux Pratique - NAT Statique

###### DESCRIPTION:
Network Address Translation (Statique).

> ###### AUTEUR:
> > **Abdessabour Arous**.


> ###### NOTICE RELATIVE AU DROIT D'AUTEUR:

> >  1. Vous pouvez copier, modifier, et/ou utiliser ce documents (diapositives + manuels de TPs) pour des fins non lucratifs à condition de mentionner leur origine.
> >  2. L'auteur (Abdessabour Arous) souhaite (non obligatoire) juste qu'il soit notifier lors de l'utilisation de ces documents.
> >  3. Toute utilisation de ces documents dans des formations payantes est strictement interdite sauf après avoir reçu une autorisation écrite de l'auteur (Abdessabour Arous)


##### OUTILS
- GNS3

##### INSTRUCTIONS
1. Fichier 'nat statique.png'
	* PC1
	````
	PC1> ip 192.168.20.2/24 192.168.20.1
	PC1> save
	```

	* PC2
	````
	PC2> ip 192.168.20.3/24 192.168.20.1
	PC2> save
	```

	* PC3
	````
	PC3> ip 192.168.20.4/24 192.168.20.1
	PC3> save
	```

	* ROUTER1
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip address 192.168.20.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# interface Serial 2/0
	Router(config-if)# ip address 196.65.22.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# ip route 0.0.0.0 0.0.0.0 196.65.22.2
	router(config)# exit
	router# copy running-config startup-config
	```

	* ROUTER2
	````
	router> en
	router# conf t
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 196.65.22.2 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# ip route 0.0.0.0 0.0.0.0 196.65.22.1
	router(config)# exit
	router# copy running-config startup-config
	```

	* ROUTER1
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip nat inside
	Router(config-if)# exit
	router(config)# interface Serial 2/0
	Router(config-if)# ip nat outside
	Router(config-if)# exit
	router(config)# ip nat inside source static 192.168.20.2 196.65.22.50
	router(config)# exit
	router# copy running-config startup-config
	```
