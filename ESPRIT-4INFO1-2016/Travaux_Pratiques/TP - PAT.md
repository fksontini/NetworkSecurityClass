### Travaux Pratique - PAT

###### DESCRIPTION:
PORT Address Translation.

> ###### AUTEUR:
> > **Abdessabour Arous**.


> ###### NOTICE RELATIVE AU DROIT D'AUTEUR:

> >  1. Vous pouvez copier, modifier, et/ou utiliser ce documents (diapositives + manuels de TPs) pour des fins non lucratifs à condition de mentionner leur origine.
> >  2. L'auteur (Abdessabour Arous) souhaite (non obligatoire) juste qu'il soit notifier lors de l'utilisation de ces documents.
> >  3. Toute utilisation de ces documents dans des formations payantes est strictement interdite sauf après avoir reçu une autorisation écrite de l'auteur (Abdessabour Arous)


##### OUTILS
- GNS3

##### INSTRUCTIONS
1. Fichier 'pat.png'
	* PC1
	````
	PC1> ip 192.168.40.2/24 192.168.40.1
	PC1> save
	```
	
	* PC2
	````
	PC2> ip 192.168.40.3/24 192.168.40.1
	PC2> save
	```
	
	* PC3
	````
	PC3> ip 192.168.40.4/24 192.168.40.1
	PC3> save
	```
	
	* ROUTER1
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip address 192.168.40.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 191.54.17.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# ip route 0.0.0.0 0.0.0.0 191.54.17.2
	router(config)# exit
	router# copy running-config startup-config
	```
	
	* ROUTER2
	````
	router> en
	router# conf t
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 191.54.17.2 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router# copy running-config startup-config
	```
	
	* ROUTER1
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip nat inside
	Router(config-if)# exit
	router(config)# interface Serial 1/0
	Router(config-if)# ip nat outside
	Router(config-if)# exit
	router(config)# access-list 1 permit 192.168.40.0 0.0.0.255
	router(config)# ip nat inside source list 1 interface serial 1/0 overload 
	router(config)# exit
	router# copy running-config startup-config
	```