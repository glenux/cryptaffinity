# CryptAffinity

## 1. Description

CryptAffinity est un logiciel libre permettant de déchiffrer des texte
obfusqués par des systemes Affines ou l'algorithme de Vigenère. Il possède les
caractéristiques suivantes :

  * Il est distribue sous la licence [GNU General Public License](http://www.gnu.org/copyleft/gpl.html)
  * Il est écrit en C++.
  * Il implémente pour l'instant uniquement une analyse par fréquences, à partir d'une liste de "priorités" de lettres dans un texte clair, et de la proportion que représentent les X premières lettres "prioritaires" dans le texte.

### 1.1. Auteurs

CryptAffinity a été concçu et realisé par Glenn ROLLAND
<[glenux@glenux.net](mailto:glenux@glenux.net)> et Roland LAURÈS
<[shamox@mac.com](mailto:shamox@mac.com)> à l'occasion de travaux pratiques du
cours de système du Master 2 Ingenierie Informatique - Systèmes, Reseaux et
Internet.


## 2. Pre-requis

CryptAffinity nécessite les bibliothèques de fonctions suivantes (dans leur
version de développement si compilez le programme vous-même):

  * glib-2.0


### 2.1. Sur un système Debian GNU/Linux

Il vous suffit de taper (en tant qu'administrateur) les commandes suivantes
pour installer le nécessaire: 

    # apt-get install libglib-2.0-dev


### 2.2. Sur un système Apple MacOS X (>= 10.3)

Il est nécessaire d'avoir installé les autotools (automake,
autoconf...) dans leur dernière version. À partir de là, il
suffit de taper les commandes suivantes dans un terminal :

    # sudo fink install glib2-dev


### 2.3. Sur un système Microsoft Windows

Cela ne fut pas testé, mais il est probable que cela
fonctionne sous Cygwin ou équivalent.


## 3. Se procurer CryptAffinity

Vous pouvez télécharger la version la plus récente du projet sur le depôt Git du projet.

Afin d'obtenir les sources, il vous suffit d'avoir Git installé sur votre système et de taper la commande suivante :

    $ git clone https://github.com/glenux/cryptaffinity.git


## 4. Utiliser CryptAffinity


### 4.1. Compilation

Si vous avez téléchargé une archive, commencez par la décompressez :

    $ tar -xzvf CryptAffinity-0.2.tar.gz

Rendez vous ensuite dans le dossier qui vient d'etre crée lors de la
décompression.

    $ cd CryptAffinity-0.2

Puis lancez l'auto-configuration du logiciel, puis la compilation.

    $ ./autogen
    $ ./configure
    $ make

Le programme sous forme binaire se trouvera alors dans le sous-dossier
src/tools/, sous le nom break_affinity


### 4.2. Utilisation

CryptAffinity necessite de nombreux parametres, avec la syntaxe suivante:

    Usage: break_affinity -a <fichier> -e <float> -f <float> -p <fichier> -t <fichier> -m

Ou les parametres sont les suivants:  &nbs
p_place_holder;   

**-a**, **--alphabet** _FILE_
: Fichier contenant les lettres de l'alphabet, dans l'ordre.

**-e**, **--epsilon** _FLOAT_
: Tolerance pour le test des clefs.

**-f**, **--frequencies** _FLOAT_
: Proportion moyenne que représentent les 9 lettres "prioritaires" dans le texte
clair.

**-k**, **--keylength** _UINT_
: Taille de la clef maximum (obsolète)

**-p**, **--priorities** _FILE_
: Lettres ordonnées par fréquence décroissante d'apparition dans le texte clair.

**-t**, **--text** _FILE_
: Fichier contenant le texte chiffre.

**-m**, **--mode** _MODE_
: Sélection du mode "Affine" (a) ou "Vigenère" (v)


### 4.3. Exemples

Pour utiliser le décodeur Affine : 

    break_affinity -a data/alphabet.txt -f 0.7 -m a -p data/priority.txt \
        -t demo/affine.txt -e 0.1

Pour utiliser le décodeur Vigenère : 

    break_afinity -a data/alphabet.txt -f 0.7 -m v -p data/priority.txt \
        -t demo/vigenere.txt -e 0.05


## 5. Documentation

### 5.1. Code

Vous pouvez générer la documentation du code de CryptAffinity avec doxygen
et la consulter dans le dossier doc/html de l'application.

Pour ce faire, tapez :

    $ doxygen doxygen.conf


### 5.2. Principe du "décodeur Affine"

On génère l'espace des clefs possibles pour l'alphabet donne
en entrée:

    int alpha_size; //taille de l'alphabet
    std::list<int> orb; // nombre premiers avec alpha_size
    MathTools mt; // bibliotheque d'outils mathematiques
    std::list<KeyAffine> keyList;
    std::list<int>::iterator orbIt;
    
    for (i=1; i<alpha_size; i++){
        if (mt.pgcd(i, alpha_size) == 1) {
    	orb.push_back(i);
        }
    }
    // 1 - generer l'espace des 312 clefs
    for (orbIt = orb.begin(); orbIt != orb.end(); orbIt++){
        KeyAffine key;
        key.setCoefA((*orbIt));
        for (i=0; i<alpha_size; i++){
    	key.setCoefB(i);
    	keyList.push_back(key);
      }
    }


Puis on fait une attaque par analyse de frequence sur les textes obtenus par
"décodage" du texte chiffre avec les clefs essayees.

    float frequencies; // frequence cumulee des 9 lettres les
    plus presentes
    float epsilon; // marge d'erreur
    std::list<KeyAffine>::iterator kLIt;
  
    for (kLIt = keyList.begin(); kLIt != keyList.end(); kLIt++){
        float score = 0;
        printf("Trying key %s\n", (*kLIt).toString().c_str());
  
        plainText = codec.decode(cypherText, *kLIt);   
        plainText.setAlphabet(this->_config.getAlphabet());
  
        for (int i=0; i<9; i++){
	    score +=   plainText.getCountOf(prio_conf[i]);
        }
  
        score = score / plainText.size();
  
        if (fabs(score - frequencies) < epsilon){
	    printf("KEY = %s\n",(*kLIt).toString().c_str());
  
	    printf("PLAIN TEXT(%f) = %s\n", fabs(score-frequencies),
  
		    plainText.toAlphabet().c_str());
        }
    }
  

### 5.3. Principe du "décodeur Vigenère"

On commence par détecter les groupes de carateres qui se repetent dans le
texte.

Une fois ces groupes repétes de lettres obtenus (dans l'ordre décroissant en
fonction de leur longueur), on calcule la distance separant les deux premiers
groupes (note d1) puis la distance entre les deux suivant (d2).

On pose K = PGCD(d1, d2). Il est fortement probable que K soit un multiple de
la longueur de la clef. L'hypothese sous-jacente est que ces groupes de
lettres sont issue du chiffrement des memes bouts de mots avec les memes bouts
de la clef. Si le K = 1 on peut raisonnablement supposer que ce n'est pas le
cas, et qu'il n'y a pas de repetitions.


L'etape suivante consiste a faire une analyse de frequence en découpant le
texte en K colonnes. On classe ensuite les lettres
apparaissant dans les colonnes en fonction de leur nombre d'apparitions.

Dans un monde utopique, il suffirait de calculer la distance entre la lettre
apparaissant le plus souvent dans la colonne, et celle apparaissant le plus
souvent dans le langage attendu pour le texte clair (l'anglais en
l'occurrence).

Cependant il arrive frequemment que l'ordre de lettre soit legerement change
par rapport au resultat attendu. Dans le programme, on calcule donc pour
chaque colonne les distances entre les X lettres les plus frequentes dans la
colonne et la lettre la plus frequente dans le langage.

On génère ensuite un espace de X ^ K clefs a partir des combinaisons de ces
differents décalages obtenus sur chaque colonne.

  
Enfin, on décode ensuite le texte avec chacune des clef génerees, et en
fonction de donnees statistiques relative a notre connaissance prealable du
texte et d'une petite marge d'erreur, on filtre les texte déchiffres.

(Exemple: les 9 lettres les plus frequentes representent 70% du texte, et on
une marge de +/- 4%).

En jouant sur la marge d'erreur, on laisse passer plus ou moins de textes
déchiffres, parmi lesquels devrait se trouver le texte clair attendu.

