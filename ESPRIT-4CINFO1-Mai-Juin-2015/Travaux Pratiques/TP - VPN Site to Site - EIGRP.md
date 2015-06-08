### Travaux Pratique - SITE TO SITE VPN

###### DESCRIPTION:
PSITE TO SITE VPN.

> ###### AUTEUR:
> > **Abdessabour Arous**.


> ###### NOTICE RELATIVE AU DROIT D'AUTEUR:

> >  1. Vous pouvez copier, modifier, et/ou utiliser ce documents (diapositives + manuels de TPs) pour des fins non lucratifs à condition de mentionner leur origine.
> >  2. L'auteur (Abdessabour Arous) souhaite (non obligatoire) juste qu'il soit notifier lors de l'utilisation de ces documents.
> >  3. Toute utilisation de ces documents dans des formations payantes est strictement interdite sauf après avoir reçu une autorisation écrite de l'auteur (Abdessabour Arous)


##### OUTILS
- GNS3

##### INSTRUCTIONS
1. Fichier 'vpn_site_to_site_eigrp.png'
	* PC1
	````
	PC1> ip 10.11.0.11/24 10.11.0.1
	PC1> save
	```
	
	* PC2
	````
	PC2> ip 10.33.0.33/24 10.33.0.1
	PC2> save
	```
	
	* PC3
	````
	PC3> ip 192.168.70.2/24 192.168.70.1
	PC3> save
	```
	
	* PC4
	````
	PC3> ip 192.168.70.2/24 192.168.70.1
	PC3> save
	```
	
	* ROUTER1
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip address 10.11.0.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 10.12.0.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# router eigrp 1
	router(config-router)# network 0.0.0.0
	router(config)# exit 
	router# copy running-config startup-config
	```
	
	* ROUTER2
	````
	router> en
	router# conf t
	router(config)# interface FastEthernet 0/0
	Router(config-if)# ip address 10.33.0.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 10.23.0.1 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# router eigrp 1
	router(config-router)# network 0.0.0.0
	router(config)# exit 
	router# copy running-config startup-config
	```
	
	* ROUTER3
	````
	router> en
	router# conf t
	router(config)# interface Serial 1/0
	Router(config-if)# ip address 10.12.0.2 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# interface Serial 1/1
	Router(config-if)# ip address 10.23.0.2 255.255.255.0
	Router(config-if)# no shutdown
	Router(config-if)# exit
	router(config)# router eigrp 1
	router(config-router)# network 0.0.0.0
	router(config)# exit 
	router# copy running-config startup-config
	```
	
	##### Configuration du Tunnel VPN
	
	* ROUTER1
	````
	router> en
	router# conf t
	router(config)# crypto isakmp policy 1
	router(config-isakmp)# encryption aes
	router(config-isakmp)# authentication pre-share
	router(config-isakmp)# exit
	router(config)# crypto isakmp key Esprit123 address 0.0.0.0
	router(config)# ip access-list extended 100
	router(config-ext-nacl)# permit ip 10.11.0.0 0.0.0.255 10.33.0.0 0.0.0.255
	router(config-ext-nacl)# exit
	router(config)# crypto ipsec transform-set MYSET esp-sha-hmac esp-aes
	router(cfg-crypto-trans)# exit
	router(config)# crypto map MYMAP 1 ipsec-isakmp
	router(cfg-crypto-map)# set transform-set MYSET
	router(cfg-crypto-map)# set peer 10.23.0.1
	router(cfg-crypto-map)# match address 100
	router(cfg-crypto-map)# exit
	router(config)# interface serial 1/0
	router(config-if)# crypto map MYMAP
	router(config)# exit
	router# copy running-config startup-config
	```
	
	* ROUTER2
	````
	router> en
	router# conf t
	router(config)# crypto isakmp policy 1
	router(config-isakmp)# encryption aes
	router(config-isakmp)# authentication pre-share
	router(config-isakmp)# exit
	router(config)# crypto isakmp key Esprit123 address 0.0.0.0
	router(config)# ip access-list extended 100
	router(config-ext-nacl)# permit ip 10.33.0.0 0.0.0.255 10.11.0.0 0.0.0.255
	router(config-ext-nacl)# exit
	router(config)# crypto ipsec transform-set MYSET esp-sha-hmac esp-aes
	router(cfg-crypto-trans)# exit
	router(config)# crypto map MYMAP 1 ipsec-isakmp
	router(cfg-crypto-map)# set transform-set MYSET
	router(cfg-crypto-map)# set peer 10.12.0.1
	router(cfg-crypto-map)# match address 100
	router(cfg-crypto-map)# exit
	router(config)# interface serial 1/0
	router(config-if)# crypto map MYMAP
	router(config)# exit
	router# copy running-config startup-config
	```