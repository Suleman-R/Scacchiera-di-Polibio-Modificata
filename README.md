# 🔐 Scacchiera di Polibio Modificata

Un progetto scolastico individuale focalizzato sulla crittografia classica e sulla programmazione orientata agli oggetti (OOP), sviluppato interamente in autonomia per l'indirizzo **Informatica** durante il 4° anno delle scuole superiori.

---

## 🚀 Panoramica del Progetto
Il software è un'applicazione C++ da riga di comando (CLI) che implementa una versione moderna e potenziata della celebre **Scacchiera di Polibio**. Grazie a un'architettura software flessibile, il programma permette di cifrare e decifrare stringhe di testo mantenendo il codice pulito, modulare e facilmente estendibile.

---

## 📚 Concetto Teorico e Logica di Funzionamento

### 1. La Scacchiera di Polibio Classica
Inventata dall'antico storico greco Polibio, la scacchiera classica è un sistema di cifratura a sostituzione frazionaria. 
* Tradizionalmente si basa su una griglia **5 × 5** contenente le 24 lettere dell'alfabeto classico (spesso unendo le lettere *I* e *J* nella stessa cella).
* Ogni lettera viene convertita in una coppia di numeri che rappresentano le sue coordinate nella griglia (**Riga, Colonna**).
* *Esempio:* Se la lettera 'A' si trova nella riga 1, colonna 1, il suo valore cifrato sarà `11`.

### 2. La Logica Modificata in questo Progetto
Il limite della scacchiera classica è l'impossibilità di cifrare numeri, spazi bianchi e simboli speciali senza alterare il testo originale. Questo progetto supera tale barriera introducendo una **versione modificata**:
* **Griglia Estesa:** La matrice è stata ampliata oltre il formato 5 × 5 per ospitare l'intero alfabeto moderno, i numeri da 0 a 9 e i principali caratteri speciali.
* **Preservazione della Spaziatura:** La logica modificata gestisce correttamente gli spazi vuoti, permettendo la cifratura di intere frasi complesse anziché di singole parole.
* **Robustezza:** I caratteri non supportati vengono scartati o gestiti in sicurezza per evitare crash del programma.

---

## 🛠️ Architettura del Codice e Logica OOP
Il punto di forza di questo sviluppo indipendente risiede nell'utilizzo del paradigma **Object-Oriented Programming (OOP)**, che eleva il codice rispetto alle classiche soluzioni procedurali scolastiche:

* **Incapsulamento:** La scacchiera, le funzioni di cifratura e quelle di decifratura sono incorporate all'interno di classi dedicate. I dati sensibili (come la struttura interna della matrice) sono nascosti (`private`) e accessibili solo tramite metodi pubblici sicuri.
* **Modularità e Separazione dei Compiti:** La logica crittografica è nettamente separata dalla logica di interazione con l'utente (Menu e Input/Output), rendendo il codice pulito e manutenibile.
* **Gestione della Memoria:** Ottimizzazione del passaggio dei parametri e dell'allocazione delle strutture dati per garantire un'esecuzione fluida.

---

## 💻 Tecnologie Utilizzate
* **Linguaggio di programmazione:** C++ (100%)
* **Paradigma:** Programmazione Orientata agli Oggetti (OOP)
* **Interfaccia Utente:** CLI (Interfaccia a riga di comando interattiva)
* **Compilatore Online Consigliato:** GDB Online (semplice e intuitivo)
* **Compilatore Consigliato:** GCC / Clang (compatibile con standard C++11 o successivi)

---

## 📦 Installazione ed Esecuzione

Puoi avviare ed eseguire il software in due modalità differenti: tramite l'eseguibile precompilato (metodo rapido) o compilando direttamente i file sorgente.

### Opzione 1: Esecuzione Rapida (File .exe)
Per motivi di test rapido o per chi non possiede un compilatore installato, è possibile utilizzare direttamente l'eseguibile precompilato presente nella repository (valido per sistemi Windows):
1. Scarica il file `scacchiera_di_Polibio_mod.exe` sul tuo computer.
2. Fai doppio clic sul file per avviare istantaneamente l'interfaccia a riga di comando del programma.

### Opzione 2: Compilazione da Terminale (File .cpp)
Se desideri compilare il codice sorgente autonomamente, assicurati di avere un compilatore C++ installato (es. `g++`) e segui questi passaggi:
1. Clona la repository sul tuo computer locale:
   ```bash
   git clone https://github.com/Suleman-R/Scacchiera-di-Polibio-Modificata.git
   ```
2. Entra nella directory del progetto:
   ```bash
   cd Scacchiera-di-Polibio-Modificata
   ```
3. Compila il file sorgente:
   ```bash
   g++ scacchiera_di_Polibio_mod.cpp -o scacchiera_polibio
   ```
4. Avvia l'applicazione:
   ```bash
   ./scacchiera_polibio
   ```

---

## 🧑‍💻 Autore
* **Suleman-R** - *Sviluppatore Unico* - Progetto scolastico individuale.
