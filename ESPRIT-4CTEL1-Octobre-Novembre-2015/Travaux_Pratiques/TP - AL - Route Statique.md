### Travaux Pratique - ACCESS LIST

###### DESCRIPTION:
Access Control Lists .

> ###### AUTEUR:
> > **Abdessabour Arous**.


> ###### NOTICE RELATIVE AU DROIT D'AUTEUR:

> >  1. Vous pouvez copier, modifier, et/ou utiliser ce documents (diapositives + manuels de TPs) pour des fins non lucratifs à condition de mentionner leur origine.
> >  2. L'auteur (Abdessabour Arous) souhaite (non obligatoire) juste qu'il soit notifier lors de l'utilisation de ces documents.
> >  3. Toute utilisation de ces documents dans des formations payantes est strictement interdite sauf après avoir reçu une autorisation écrite de l'auteur (Abdessabour Arous)


##### OUTILS
- GNS3

##### INSTRUCTIONS
1. Fichier 'acl.png'
	* PC1
	````
	PC1> ip 172.16.1.2/24 172.16.1.1
	PC1> save
	```
	
	* PC2
	````
	PC2> ip 172.16.1.3/24 172.16.1.1
	PC2> save
	```
	
	* PC3
	````
	PC3> ip 172.16.2.2/24 172.16.2.1
	PC3> save
	```
	
	* PC4
	````
	PC4> ip 172.16.3.2/24 172.16.3.1
	PC4> save
	```
	
	* ROUTER1
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip address 172.16.1.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# end
	router# conf t
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 10.11.0.1 255.255.0.0
	Router(config-if)# no shutdown
	Router(config-if)# end
	router# conf t
	router(config)# interface Serial 1/1
	Router(config-if)# ip address 10.12.0.1 255.255.0.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# ip route 172.16.2.0 255.255.255.0 10.11.0.2
	router(config)# ip route 172.16.3.0 255.255.255.0 10.12.0.2
	router(config)# exit
	router# show ip route
	router# copy running-config startup-config
	```
	
	* ROUTER2
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip address 172.16.2.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# end
	router# conf t
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 10.11.0.2 255.255.0.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# ip route 172.16.1.0 255.255.255.0 10.11.0.1
	router(config)# ip route 172.16.3.0 255.255.255.0 10.11.0.1
	router(config)# exit
	router# show ip route
	router# copy running-config startup-config
	```
	
	* ROUTER3
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip address 172.16.3.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# end
	router# conf t
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 10.12.0.2 255.255.0.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# ip route 172.16.1.0 255.255.255.0 10.12.0.1
	router(config)# ip route 172.16.2.0 255.255.255.0 10.12.0.1
	router(config)# exit
	router# show ip route
	router# copy running-config startup-config
	```
