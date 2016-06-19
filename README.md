# SP-projekat
README

	Ovaj projekat je kao rezultat dao simulaciju videoteke, koja ima punu funkcionalnost videoteke u pravom životu. Dakle sam interface programa je prilagođen Balkanskom govornom području ali uz male izmjene moguće ga je prilagoditi i za englesko govorno područje. Program omogućava dva tipa učesnika , a to bi bili administrator ili korisnik. U oba slučaja potrebno je specificirati korisničko ime te se prijaviti (logovati )u sam program,pri čemu svaki učesnik posjeduje šifru nakon čijeg validnog unosa,učesniku se nude određene funkcionalnosti , te se nakon prijave dakle određuje da li je u pitanju administrator ili korisnik . Dakle korisniku je omogućeno da posuđuje, vraća i vrši preglede filmova, pri čemu je ograničen na maksimalno 3 filma istovremeno.Opcije uključuju pristup listi svih filmova u ponudi kao i , pregled pojedinačnih filmova, nakon čega se evidencija void u .txt file-u. Administrator se pretpostavlja da je vlasnik videoteke i njemu je omogućen širi spektar opcija, uključujući pristup listi filmova, kao i pristup listi korisnika.Administrator je u mogućnosti da ažurira i listu korisnika, kao i listu filmova pri čemu, može mjenjati atribute članova gore spomenutih listi. Takođe na raspolaganju mu je i pristup .txt fajlovima u kojima se nalaze evidentirani svi korisnici i filmovi, te omogućena mu je opcija “Blacklist” , koja će izbaciti sve potencijalne članove koji imaju posuđena 3 filma. Videoteka ostaje otvorena sve dok administrator ne odluči da je zatvori, pri čemu se sve promjene dokumentiraju.

LISTA AUTORA I SURADNIKA:

	Aner Ćatović
	Ferid Bešić

KONTAKTI

	Ukoliko imate prijedloge,žalbe ili ideje za daljnji razvoj programa, molimo kontaktirajte nas putem mail-a:
	ferid.besic@fet.ba
	aner.catovic@fet.ba

Prijavljeni problemi ili neočekivano ponašanje programa, će biti sanirano u što kraćem roku. Hvala vam puno

SAJT ZA DOWNLOAD
	https://github.com/limunlimun/videostore_tanfe3512.git


UPUTSTVO
	Nakon što klonirate sadržaj repozitorija,ili ga download-ate  pratite sljedeće korake:
Za Linux platformu:
	1. Odaberite direktorij videostore_tanfe3512. putem opcije cd
	2. make clean
	3. make
	4. ./program
Za Windows platformu:
	1.	Nađite .exe file
	2.	Pokrenite .exe file
	Vaš program je sada pokrenut i spreman za upotrebu.

LISTA FAJLOVA:
	
	main.cpp

	Arhiva.txt 
	
	Bst.h 
	
	admin.h 
	
	datum.h 
	
	film.h 
	
	historija.h 
	
	korisnik.h 
	
	lista.hxx 
	
	lista_filmova.h 
	
	lista_filmova.txt 
	
	lista_historija.h 
	
	Lista_korisnika.h 
	
	makefile 
	
	osoba.h 
	
	trhistorija.txt 
	
	ukhistorija.txt
