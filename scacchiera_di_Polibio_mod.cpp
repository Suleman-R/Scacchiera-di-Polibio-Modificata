#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#define RIGHE 3
#define COLONNE 3
#define CELLA_LENG 4
const char ALFABETO[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 
                         'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                         'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                         'y', 'z', ' '};

// Classe Cella per constrizione della Matrice
struct Cella{
    char charList[CELLA_LENG] = {' ', ' ', ' ', '\0'}; // '\0' -> e' un caratere nullo per finire l'array
};

// Classe per Generare una chiave config Matrice
class KeyGen{
    // class Generatore chiave per la comfig Matrice
    // Chiave config: R D S R° R' R"
    // R D S -> configurazine chelle intere
    // R° R' R" -> configurazione singoli carateri con i carateri delle altre celle 
    // Significato: RuotazioneCelle DirezioneRuotazione SwapCentraleConCella 
    //              ScalaggioPrimoCaratere ScalaggioSecondoCaratere ScalaggioTerzoCaratere
    private:
        string key = "";

    public:
        // Costuttore -> Genera Key
        KeyGen(){
            GenNewKey();
        }
        // Metodo Generatore Key
        void GenNewKey(){
            key = "";
            int ruotaCella = rand() % 8;
            int direzione = rand() % 2;
            int scambio = rand() % 8;
            int r1 = rand() % 8;
            int r2 = rand() % 8;
            int r3 = rand() % 8;
            key += to_string(ruotaCella);
            key += to_string(direzione);
            key += to_string(scambio);
            key += to_string(r1);
            key += to_string(r2);
            key += to_string(r3);
        }
        // Verifica Key (bool)
        bool verificaKey(string pKey){
            int rCella = pKey[0] - '0';
            int dCella = pKey[1] - '0';
            int sCella = pKey[2] - '0';
            int r1 = pKey[3] - '0';
            int r2 = pKey[4] - '0';
            int r3 = pKey[5] - '0';
            
            if (rCella >= 0 && rCella < 8
                && dCella >= 0 && dCella < 2
                && sCella >= 0 && sCella < 8
                && r1 >= 0 && r1 < 8
                && r2 >= 0 && r2 < 8
                && r3 >= 0 && r3 < 8
            ){
                return true;
            }
            
            return false;
        }
        // Gettare La Key
        string GetKey(){
            return key;
        }
        // Settare Propria Key
        void SetKey(string pKey){
            if (verificaKey(pKey)){
                key = "000000";
                key = pKey;
            }else{
                key = "";
            }
        }
};

// Classe Matrice
class Matrice{
    private:
        // Obj Key Generator (creazione, verifica, Get, Set)
        KeyGen keyConfig;
        
        // Coordinate per sostari nell'Matice
        int arrX[8] = {0, 1, 2, 2, 2, 1, 0, 0};
        int arrY[8] = {0, 0, 0, 1, 2, 2, 2, 1};
        
        // Metodi ausigliari (privati):
        
        // - Metodi Swap celle overloaded
        void SwapCella(int xCella1, int yCella1, int xCella2, int yCella2){
            Cella *c1;
            Cella *c2;
            Cella temp;
            
            c1 = &matrice[xCella1][yCella1];
            c2 = &matrice[xCella2][yCella2];
            
            temp = *c2;
            *c2 = *c1;
            *c1 = temp;
        }
        // Metodo utilizzato nella 3 cifra -> S cambia con un numero random
        void SwapCella(Cella *c1, Cella *c2){
            Cella temp;
            temp = *c2;
            *c2 = *c1;
            *c1 = temp;
            
        }
        // - Metodi Swap per caratere
        void SwapChar(char *p1, char *p2){
            char temp;
            temp = *p2;
            *p2 = *p1;
            *p1 = temp;
        }
        
        // Metodi privati per la config Matice:
        
        // - Cifre R e D -> Ruotazione delle Cella in una direzione
        // NON TOCCARE QUESTA CAZZ DI METODO
        void RuotazioneCella(int nRuotazione, int direzione){
            Cella temp;
            
            // config matice direzione orario = 0
            int startIndex = 2, endIndex = 8;
            int Xswap = 1, Yswap = 0;
            
            // config matici direzione antiorario = 1
            if (direzione == 1){
                startIndex = 6, endIndex = 0;
                Xswap = 0, Yswap = 1;
            }
            
            // Numero di volte della ruotazione celle
            for (int j = 0; j < nRuotazione; j++){
                
                // applicazione della configurazione
                temp = matrice[Xswap][Yswap];
                matrice[Xswap][Yswap] = matrice[0][0];
                
                bool fine = false;
                int i = startIndex;
                
                while (!fine){
                    // swappa la cella cella
                    if (direzione == 0){
                        if (i < endIndex){
                            SwapCella(&temp, &matrice[arrX[i]][arrY[i]]);
                            i += 1;
                        }else fine = true;
                    }else{
                        if (i > endIndex){
                            SwapCella(&temp, &matrice[arrX[i]][arrY[i]]);
                            i -= 1;
                        }else fine = true;
                    }
                }
                matrice[0][0] = temp;
            }
            
        }
        void RuotazioneChar(int nRuotazione, int direzione, int colonnaChar){
            Cella temp;
            
            // config matice direzione orario = 0
            int startIndex = 2, endIndex = 8;
            int Xswap = 1, Yswap = 0;
            
            // config matici direzione antiorario = 1
            if (direzione == 1){
                startIndex = 6, endIndex = 0;
                Xswap = 0, Yswap = 1;
            }
            
            // Numero di volte della ruotazione celle
            for (int j = 0; j < nRuotazione; j++){
                
                // applicazione della configurazione
                temp.charList[colonnaChar] = matrice[Xswap][Yswap].charList[colonnaChar];
                matrice[Xswap][Yswap].charList[colonnaChar] = matrice[0][0].charList[colonnaChar];
                
                bool fine = false;
                int i = startIndex;
                
                while (!fine){
                    // swappa la cella cella
                    if (direzione == 0){
                        if (i < endIndex){
                            SwapChar(&temp.charList[colonnaChar], &matrice[arrX[i]][arrY[i]].charList[colonnaChar]);
                            i += 1;
                        }else fine = true;
                    }else{
                        if (i > endIndex){
                            SwapChar(&temp.charList[colonnaChar], &matrice[arrX[i]][arrY[i]].charList[colonnaChar]);
                            i -= 1;
                        }else fine = true;
                    }
                }
                matrice[0][0].charList[colonnaChar] = temp.charList[colonnaChar];
            }
            
        }
        
        // Creazione Matrice con shema base
        void BaseMatrice(){
            // var indice per l'ALFABETO
            int indexAlfabbeto = 0;
            for (int j = 0; j < COLONNE; j++){
                for (int k = 0; k < RIGHE; k++){
                    for (int q = 0; q < CELLA_LENG - 1; q++){
                        matrice[k][j].charList[q] = ALFABETO[indexAlfabbeto];
                        indexAlfabbeto++;
                    }
                }
            }
        }
        
    public:
        // matrice 2d di tipo celle -> 3d
        Cella matrice[RIGHE][COLONNE];
        
        // Costruttore che Genera la Matrice default + Key
        Matrice(){
            // Shema Matrice Base + Modifiche
            GenMatrice(keyConfig.GetKey());
        }
        
        // Genera matrice data una Chiave
        void GenMatrice(string pKey){
            // Ricreazione Matrice
            BaseMatrice();
            // Verifica Chiave Inserita if false -> return
            if (!keyConfig.verificaKey(pKey)) return;
            
            // ---- Creazione Matice ----
            // - 1:
            // Cifre 1 e 2 -> R D (Ruotazione&Direzione)
            RuotazioneCella(pKey[0] - '0', pKey[1] - '0');
            // - 2:
            // Cifre 4, 5 e 6 -> (Ruotazione & Direzione dei singoli carateri nella cella)
            RuotazioneChar(pKey[3] - '0', pKey[1] - '0', 0);
            RuotazioneChar(pKey[4] - '0', pKey[1] - '0', 1);
            RuotazioneChar(pKey[5] - '0', pKey[1] - '0', 2);
            // - 3:
            // Cifra 3 -> Swap cella centrale con una random
            SwapCella(1, 1, arrX[pKey[2] - '0'], arrY[pKey[2] - '0']);
            
            // SetKey
            keyConfig.SetKey(pKey);
        }
        
        // Stampa Matrice
        void printMatrice(){
            cout<<"    -------------------\n";
            for (int j = 0; j < COLONNE; j++){
                cout<<"    | ";
                for (int k = 0; k < RIGHE; k++){
                    cout<<matrice[k][j].charList<<" | ";
                }
                cout<<endl;
            }
            cout<<"    -------------------\n";
            cout<<"    |   Key: "<<keyConfig.GetKey()<<"   |\n";
            cout<<"    -------------------\n";
        }
        
        // Metodi fondamentali -> find per la ricerca 
        string find(char c){ // char into matrix indexs
            string cordinate = ""; // -> j k i
            for (int k = 0; k < COLONNE; k++){
                for (int j = 0; j < RIGHE; j++){
                    for (int i = 0; i < CELLA_LENG - 1; i++){
                        if (matrice[j][k].charList[i] == c){
                            cordinate += to_string(j);
                            cordinate += to_string(k);
                            cordinate += to_string(i);
                            return cordinate;
                        }
                    }
                }
            }
            return "";
        } // char -> index
        char find(string msg){
            // string(indexs matrix) into char
            int j = msg[0] - '0';
            int k = msg[1] - '0';
            int i = msg[2] - '0';
            
            if (j >= 0 && j < 3 && k >= 0 && k < 3 && i >= 0 && i < 3){
                return matrice[j][k].charList[i];
            }else{
                return '\0';
            }
        } // index -> char
        
        // Get keyConfig
        string GetKey(){
            return keyConfig.GetKey();
        }
        void SetKey(string pKey){
            keyConfig.SetKey(pKey);
        }
        bool verificaKey(string pKey){
            return keyConfig.verificaKey(pKey);
        }
};

// Class Cripto utilizzando la classe Matrice
class Cripto{
    private:
        Matrice matrice;
        string msgCod;
        string msgDecod;
        
    public:
        // Metodi Codifica Messaggio
        void Codifica(string msg){
            msgCod = "";
            for (int i = 0; i < msg.size(); i++){
                string res = matrice.find(msg[i]);
                if (res != ""){
                    msgCod += res;
                }else{
                    msgCod = "Errore";
                    break;
                }
            }
        } // solo msg (key default)
        void Codifica(string msg, string matxKey){
            msgCod = "";
            matrice.GenMatrice(matxKey);
            
            for (int i = 0; i < msg.size(); i++){
                string res = matrice.find(msg[i]);
                if (res != ""){
                    msgCod += res;
                }else{
                    msgCod = "Errore";
                    break;
                }
            }
        } // msg + key
        // Metodi Decodifica Messaggio
        void Decodifica(string msg){
            int index = 0;
            msgDecod = "";
            string nextLetter = "";
            
            if (msg.size() % 3 != 0)
                return;
            
            for(int i = 0; i < msg.size(); i += 3){
                nextLetter = "";
                for(int j = 0; j < 3; j++){
                    nextLetter += msg[index];
                    index++;
                }
                
                if (matrice.find(nextLetter) != '\0'){
                    msgDecod += matrice.find(nextLetter);
                }else{
                    msgDecod = "Errore";
                    return;
                }
            }
        } // solo msg (key default)
        void Decodifica(string msg, string matxKey){
            int index = 0;
            msgDecod = "";
            string nextLetter = "";
            
            if (msg.size() % 3 != 0)
                return;
            
            matrice.GenMatrice(matxKey);
            
            for(int i = 0; i < msg.size(); i += 3){
                nextLetter = "";
                for(int j = 0; j < 3; j++){
                    nextLetter += msg[index];
                    index++;
                }
                
                if (matrice.find(nextLetter) != '\0'){
                    msgDecod += matrice.find(nextLetter);
                }else{
                    msgDecod = "Errore";
                    return;
                }
            }
        } // msg + key
        // Stampa matrice
        void printMatrice(){
            matrice.printMatrice();
        }
        // Get Matirice Key
        string GetKey(){
            return matrice.GetKey();
        }
        bool SetKey(string pKey){
            if (!matrice.verificaKey(pKey))
                return false;
            
            matrice.SetKey(pKey);
            return true;
        }
        void GenMatrice(){
            matrice.GenMatrice(matrice.GetKey());
        }
        // Metodi(overloaded) Get per il risultato
        string MsgCodificato() {
            return msgCod;
        }
        string MsgDecodificato() {
            return msgDecod;
        }
};

/**
 * Remember:
 *  Tutto funzionate apprentemente
 * 
 * Bug (lievi):
 *  A volte ci mette tanto per partire + errore 139 (overStack)
 * 
 * Todo:
 *  1: Implemantare Interfaccia automaticamente
 *  2: Prevenzione l'errore
 **/

int main(){
    srand(time(NULL));
    
    Cripto enigma;
    // Istaza dell'obj Cripto:
    // Genera automaticamente:
    //      Nuova Matrice Random + La Chiave
    
    int scelta, opzione;
    char opzInput;
    bool continua;
    string msgInput;
    
    while (true){
        cout<<"\n  --------ENIGMA--------\n";
        cout<<"  | 1 -> Codifica      |\n";
        cout<<"  | 2 -> Decodifica    |\n";
        cout<<"  | 3 -> Matrice(S/M)  |\n";
        cout<<"  | 0 -> Esci          |\n";
        cout<<"  ----------------------\n";
        
        cout<<"   - Inserisci -> ";
        cin>>scelta;
        
        if (scelta == 0) break;
        
        switch (scelta){
            case 1: // Codificare MSG
                continua = true;
                while (continua){
                    cout<<"\n   --- Modalita' Codifica --- \n";
                    enigma.printMatrice();
                    cout<<"\n  -------Codifica-------\n";
                    cout<<"  | 1 -> Chiave Def.   |\n";
                    cout<<"  | 2 -> Propria Chia. |\n";
                    cout<<"  | 3 -> Genera Nuova  |\n";
                    cout<<"  | 0 -> Menu' Princ.  |\n";
                    cout<<"  ----------------------\n";
                    
                    cout<<"\n   - Vuoi Codificare con -> ";
                    cin>>opzione;
                    
                    switch (opzione){
                        case 0:
                            continua = false;
                            break;
                            
                        case 1:
                            cout<<"\n   - Inserisci il messaggio da Codificare -> ";
                            cin>>msgInput;
                            enigma.Codifica(msgInput, enigma.GetKey());
                            cout<<"\n   - Il tuo messaggio codificato("<<enigma.GetKey()<<"): "<<enigma.MsgCodificato()<<endl;
                            cout<<"\n   - La chiave: "<<enigma.GetKey()<<endl;
                            continua = false;
                            break;
                            
                        case 2:
                            do{
                                cout<<"   - Inserisci la tua Chiave -> ";
                                cin>>msgInput;
                            }while(!enigma.SetKey(msgInput));
                            
                            cout<<"\n   - La tua Chiave e' VALIDA - \n";
                            enigma.GenMatrice();
                            cout<<"\n   - La tua Chiave e' stata impostata come Chiave def. - \n";
                            break;
                            
                        case 3:
                            while(true){
                                enigma.GenMatrice();
                                enigma.printMatrice();
                                cout<<"\n   - Ti piace (s/n) -> ";
                                cin>>opzInput;
                                if (tolower(opzInput) != 'n')
                                    break;
                            }
                            break;
                            
                        default:
                            cout<<"\n   - L'opzione NON VALIDA - \n";
                    }
                }
                break;
                
            case 2: // Decodificare MSG
                continua = true;
                while (continua){
                    cout<<"\n   --- Modalita' Decodifica --- \n";
                    enigma.printMatrice();
                    cout<<"\n  ------Decodifica------\n";
                    cout<<"  | 1 -> Chiave Def.   |\n";
                    cout<<"  | 2 -> Propria Chia. |\n";
                    cout<<"  | 0 -> Menu' Princ.  |\n";
                    cout<<"  ----------------------\n";
                    
                    cout<<"\n   - Vuoi Decodificare con -> ";
                    cin>>opzione;
                    
                    switch (opzione){
                        case 0:
                            continua = false;
                            break;
                            
                        case 1:
                            cout<<"\n   - Inserisci il messaggio da Decodificare -> ";
                            cin>>msgInput;
                            enigma.Decodifica(msgInput, enigma.GetKey());
                            cout<<"\n   - Il tuo messaggio Decodificato: "<<enigma.MsgDecodificato()<<endl;
                            cout<<"\n   - La chiave: "<<enigma.GetKey()<<endl;
                            continua = false;
                            break;
                            
                        case 2:
                            do{
                                cout<<"   - Inserisci la tua Chiave -> ";
                                cin>>msgInput;
                            }while(!enigma.SetKey(msgInput));
                            
                            cout<<"\n   - La tua Chiave e' VALIDA - \n";
                            enigma.GenMatrice();
                            cout<<"\n   - La tua Chiave e' stata impostata come Chiave def. - \n";
                            break;
                            
                        default:
                            cout<<"\n   - L'opzione NON VALIDA - \n";
                    }
                }
                break;
                
            case 3:
                cout<<"\n   --- Config. Matrice --- \n";
                
                continua = true;
                while (continua){
                    enigma.printMatrice();
                    cout<<"\n  -------Matrice-------\n";
                    cout<<"  | 1 -> Propria Chia. |\n";
                    cout<<"  | 2 -> Genera Nuova  |\n";
                    cout<<"  | 0 -> Menu' Princ.  |\n";
                    cout<<"  ----------------------\n";
                    
                    cout<<"\n   - Vuoi impostare con -> ";
                    cin>>opzione;
                    
                    switch (opzione){
                        case 0:
                            continua = false;
                            break;
                            
                        case 1:
                            do{
                                cout<<"   - Inserisci la tua Chiave -> ";
                                cin>>msgInput;
                            }while(!enigma.SetKey(msgInput));
                            
                            cout<<"\n   - La tua Chiave e' VALIDA - \n";
                            enigma.GenMatrice();
                            cout<<"\n   - La tua Chiave e' stata impostata come Chiave def. - \n";
                            break;
                        
                        case 2:
                            while(true){
                                enigma.GenMatrice();
                                enigma.printMatrice();
                                cout<<"\n   - Ti piace (s/n) -> ";
                                cin>>opzInput;
                                if (tolower(opzInput) != 'n')
                                    break;
                            }
                            break;
                            
                        default:
                            cout<<"\n   - L'opzione NON VALIDA - \n";
                    }
                }
                break;
            default:
                cout<<"\n --- L'opzione NON VALIDA --- \n";
        }
    }

    return 0;
}


