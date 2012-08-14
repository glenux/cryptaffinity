# CryptAfinity

  1. Description
    1. Auteurs
  2. Pre-requis
    1. Sur un systeme Debian GNU/Linux
    2. Sur un systeme Apple MacOSX (≥10.3)
    3. Sur un systeme Microsoft Windows
  3. Se procurer CryptAfinity
  4. Utiliser CryptAfinity
    1. Compilation
    2. Utilisation
  5. Documentation
    1. Code
    2. Decodeur "Afine"
    3. Decodeur "Vigenere"

## 1. Description

CryptAfinity est un logiciel libre permettant de dechiffrer des texte
obfusques par des systemes Afines ou l'algorithme de Vigenere. Il possede les
caracteristiques suivantes :

  * Il est distribue sous la licence [GNU General Public License](http://www.gnu.org/copyleft/gpl.html)
  * Il est ecrit en C++.
  * Il implemente pour l'instant uniquement une analyse par frequences, a partir d'une liste de "priorites" de lettres dans un texte clair, et de la proportion que representent les X premieres lettres "prioritaires" dans le texte.

### 1.1. Auteurs

CryptAfinity a ete entierement realise par Glenn ROLLAND
<[glenux@glenux.net](mailto:glenux@glenux.net)> et Roland LAURÈS
<[shamox@mac.com](mailto:shamox@mac.com)> a l'occasion de travaux pratiques du
cours de systeme du Master 2 Ingenierie Informatique - Systèmes, Reseaux et
Internet.

## 2. Pre-requis

CryptAfinity necessite les bibliotheques de fonctions suivantes (dans leur
version de developpement si compilez le programme vous-meme):

  * glib-2.0

### 2.1. Sur un systeme Debian GNU/Linux

Il vous suffit de taper (en tant qu'administrateur) les commandes suivantes
pour installer le necessaire: 

# apt-get install libglib-2.0-dev

### 2.2. Sur un systeme Apple MacOS X (>= 10.3)

Il est necessaire d'avoir installe les autotools (automake,
autoconf...) dans leur derniere version. À partir de la, il
suffit de taper les commandes suivantes dans un terminal :

# sudo fink install glib2-dev

### 2.3. Sur un systeme Microsoft Windows

Cela ne fut pas (encore) teste, mais il est tres probable que cela
fonctionne sous Cygwin.

## 3. Se procurer CryptAfinity

Vous pouvez telecharger la derniere archive des sources, ou bien directement
la version la plus recente du projet sur le depot Subversion du projet.

### 3.1. L'archive des sources

Elle est disponible a l'adresse :

[http://glenux2.free.fr/pub/projets/CryptAfinity/archives/](http://glenux2.fre
e.fr/pub/projets/CryptAfinity/archives/)

### 3.2. Le depot Subversion

Afin d'obtenir les sources les plus a jour, vous pouvez utiliser le logiciel
de controle de sources Subversion

$ svn checkout http://repository.glenux.ath.cx/svn/CryptAfinity/

Il n'y a pas de mot de passe, il suffit donc de presser la touche "Entree"
pour l'utilisateur "anonymous", si ce dernier vous est demande.

## 4. Utiliser CryptAfinity

### 4.1. Compilation

Commencez par decompressez l'archive.

$ tar -xzvf CryptAfinity-0.1.tar.gz

Rendez vous ensuite dans le dossier qui vient d'etre cree lors de la
decompression.

$ cd CryptAfinity-0.2

Puis lancez l'auto-configuration du logiciel, puis la compilation.

$ ./autogen

$ ./configure

$ make

Le programme sous forme binaire se trouvera alors dans le sous-dossier
src/tools/, sous le nom break_afinity

### 4.2. Utilisation

CryptAfinity necessite de nombreux parametres, avec la syntaxe suivante:

Usage: break_afinity -a <fichier> -e <float> -f <float> -p <fichier> -t
<fichier> -m

Ou les parametres sont les suivants:  &nbs
p_place_holder;   

-a, --alphabet <file> 
Fichier contenant les lettres de l'alphabet, dans l'ordre.

  
-e, --epsilon <float>
Tolerance pour le test des clefs.

-f, --frequencies <float>
Proportion moyenne que representent les 9 lettres "prioritaires" dans le texte
clair.

-k, --keylength <int>      
Taille de la clef maximul (obsolete)

-p, --priorities <file>
Lettres ordonnees par frequence decroissante d'apparition dans le texte clair.

-t, --text <file>
Fichier contenant le texte chiffre.

-m, --mode <a|v>
Selection du mode "Afine" ou "Vigenere"

## 5. Documentation

### 5.1. Code

Vous pouvez trouver la documentation du code de CryptAfinity dans le dossier
doc/html de l'application, ou en suivant [ce lien](html/index.html).

### 5.2. Principe du "decodeur Afine"

On genere l'espace des clefs possibles pour l'alphabet donne
en entree:

int alpha_size; //taille de l'alphabet

std::list<int> orb; // nombre premiers avec alpha_size

MathTools mt; // bibliotheque d'outils mathematiques

std::list<KeyAfine> keyList;

std::list<int>::iterator orbIt;

for (i=1; i<alpha_size; i++){

    if (mt.pgcd(i,
alpha_size) == 1) {

   
    orb.push_back(i);

    }

}

// 1 - generer l'espace des 312 clefs

for (orbIt = orb.begin(); orbIt != orb.end(); orbIt++){

    KeyAfine key;

   
key.setCoefA((*orbIt));

    for (i=0;
i<alpha_size; i++){

   
    key.setCoefB(i);

   
   
keyList.push_back(key);

    }

}

Puis on fait une attaque par analyse de frequence sur les textes obtenus par
"decodage" du texte chiffre avec les clefs essayees.

float frequencies; // frequence cumulee des 9 lettres les
plus presentes

float epsilon; // marge d'erreur

std::list<KeyAfine>::iterator kLIt;

for (kLIt = keyList.begin(); kLIt != keyList.end(); kLIt++){

    float score = 0;

    printf("Trying key
%s\n", (*kLIt).toString().c_str());

  
    plainText =
codec.decode(cypherText,
*kLIt);   

   
plainText.setAlphabet(this->_config.getAlphabet());

    for (int i=0; i<9;
i++){

   
    score +=
plainText.getCountOf(prio_conf[i]);

    }

    score = score /
plainText.size();

    if (fabs(score -
frequencies) < epsilon){

      printf("KEY =
%s\n",(*kLIt).toString().c_str());

   
  printf("PLAIN TEXT(%f) = %s\n", fabs
(score-frequencies),

     
  plainText.toAlphabet().c_str());

    }

  
}

### 5.3. Principe du "decodeur Vigenere"

On commence par faire recuperer les groupes de carateres qui se repetent dans
le texte.

  
Une fois les groupes repetes de lettres de plus grande longueur obtenus (dans
l'ordre decroissant en fonction de la longueur), on calcule la distance
separant les deux premiers groupes (note d1) puis la distance entre les deux
suivant (d2).

On pose K = PGCD(d1, d2). Il est fortement probable que K soit un multiple de
la longueur de la clef. L'hypothese sous-jacente est que ces groupes de
lettres sont issue du chiffrement des memes bouts de mots avec les memes bouts
de la clef. Si le K = 1 on peut raisonnablement supposer que ce n'est pas le
cas, et qu'il n'y a pas de repetitions.

  
L'etape suivante consiste a faire une analyse de frequence en decoupant le
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

On genere ensuite un espace de X ^ K clefs a partir des combinaisons de ces
differents decalages obtenus sur chaque colonne.

  
Enfin, on decode ensuite le texte avec chacune des clef generees, et en
fonction de donnees statistiques relative a notre connaissance prealable du
texte et d'une petite marge d'erreur, on filtre les texte dechiffres.

(Exemple: les 9 lettres les plus frequentes representent 70% du texte, et on
une marge de +/- 4%).

En jouant sur la marge d'erreur, on laisse passer plus ou moins de textes
dechiffres, parmi lesquels devrait se trouver le texte clair attendu.

