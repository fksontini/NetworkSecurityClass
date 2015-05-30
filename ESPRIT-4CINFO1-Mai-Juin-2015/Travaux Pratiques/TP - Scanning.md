### Travaux Pratique - Scanning

###### DESCRIPTION:
Scanning .

> ###### AUTEUR:
> > **Abdessabour Arous**.


> ###### NOTICE RELATIVE AU DROIT D'AUTEUR:

> >  1. Vous pouvez copier, modifier, et/ou utiliser ce documents (diapositives + manuels de TPs) pour des fins non lucratifs à condition de mentionner leur origine.
> >  2. L'auteur (Abdessabour Arous) souhaite (non obligatoire) juste qu'il soit notifier lors de l'utilisation de ces documents.
> >  3. Toute utilisation de ces documents dans des formations payantes est strictement interdite sauf après avoir reçu une autorisation écrite de l'auteur (Abdessabour Arous)


##### OUTILS
- NMAP
- NESSUS
- OpenVAS

##### INSTRUCTIONS
1. NMAP
	
	* Scanner une machine
	````
	# nmap www.monsite.com
	```
	
	* Scanner une adresse IP
	````
	# nmap 172.16.3.2
	```
	
	* Scanner une plage
	````
	# nmap 172.16.3.0/24
	```
	
	* Scanner une liste de machine contenue dans un fichier
	````
	# nmap -iL liste_ip.txt
	```
	
	* Scanner un port
	````
	# nmap -p 8080 172.16.3.2
	```
	
	* Scanner plusieurs ports
	````
	# nmap -p 1-100 172.16.3.2
	```
	
	* Faire un TCP connect Scan
	````
	# nmap -sT 172.16.3.2
	```
	
	* Faire un TCP SYN Scan
	````
	# nmap -sS 172.16.3.2
	```
	
	* Faire un UDP Scan
	````
	# nmap -sU -p 63 172.16.3.2
	```
	
	* Détecter le système d'exploitation et les services en cours d'execution
	````
	# nmap -A 172.16.3.2
	```
	
	* Détecter les services en cours d'execution
	````
	# nmap -sV 172.16.3.2
	```
	
	* Scanner et sauvegarder le résultat dans un fichier txt
	````
	# nmap -oN rapport_scan.txt 172.16.3.2
	```
	
	* Scanner et sauvegarder le résultat dans un fichier xml
	````
	# nmap -oX rapport_scan.txt 172.16.3.2
	```
	
	* Collecter les titres HTTP
	````
	nmap --script=http-title 172.16.3.2
	```
	
	
	* Collecter les headers HTTP
	````
	nmap --script=http-headers 172.16.3.2
	```
	
	* Collecter des informations sur l'adresse IP
	````
	nmap --script=asn-query,whois,ip-geolocation-maxmind 172.16.3.2
	```
	
2. OpenVAS

3. NESSUS