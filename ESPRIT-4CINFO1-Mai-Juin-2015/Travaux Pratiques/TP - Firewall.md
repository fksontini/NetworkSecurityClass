### Travaux Pratique - Firewall

###### DESCRIPTION:
Firewall .

> ###### AUTEUR:
> > **Abdessabour Arous**.


> ###### NOTICE RELATIVE AU DROIT D'AUTEUR:

> >  1. Vous pouvez copier, modifier, et/ou utiliser ce documents (diapositives + manuels de TPs) pour des fins non lucratifs à condition de mentionner leur origine.
> >  2. L'auteur (Abdessabour Arous) souhaite (non obligatoire) juste qu'il soit notifier lors de l'utilisation de ces documents.
> >  3. Toute utilisation de ces documents dans des formations payantes est strictement interdite sauf après avoir reçu une autorisation écrite de l'auteur (Abdessabour Arous)


##### OUTILS
- IPTABLES
- Berkley Packet Filter
- ENDIAN Firewall
- Palo Alto

##### INSTRUCTIONS
1. IPTABLES
	
	* Lister les politiques par défaut
	````
	# iptables -S
	```
	
	* Lister les règles de filtrage actives
	````
	# iptables -L
	```
	
	* Flasher les règles de filtrage actives
	````
	# iptables -F
	```
	
	* Changer la politique par défaut d'une chaine iptables
	````
	# iptables -P INPUT ACCEPT
	# iptables -P OUTPUT DROP
	```
	
	* Autoriser toutes les connexions sur l'interface Loopback
	````
	# iptables -I INPUT 1 -i lo -j ACCEPT
	```
	
	* Autoriser des connections vers des ports données
	````
	# iptables -A INPUT -p tcp --dport 523 -j ACCEPT
	# iptables -A INPUT -p tcp --dport 253 -j ACCEPT
	```
	
	* Bloquer une IP ou un plage d'IP
	````
	# iptables -A INPUT -s 192.168.10.210 -j DROP
	# iptables -A INPUT -i eth0 -p tcp -s 192.168.10.0/24 --dport 523 -m state --state NEW,ESTABLISHED -j ACCEPT
	# iptables -A INPUT -s 192.168.10.210 -p tcp --destination-port 140 -j DROP
	```