/* * * * * * * * * * * * * * 
 * Ce fichier contient une liste de tests visant a confirmer 
 * la validation de l'extraction de commentaires provenant 
 * d'un fichier C++ (c/h - cpp/hpp).
 *
 * Ce fichier n'est pas un programme valide et ne compile pas.
 * Les accents ont ete retires afin de facilite l'affichage sur
 * une console Windows.
 * * * * * * * * * * * * * */

/* 1re serie : Tests des commentaires de style C */
 
/* Simples commentaires : style c */
/* Commentaires sur plusieurs lignes :
ligne 2
ligne 3
*/
/* Commentaires sur plusieurs lignes incluant quelques caracteres de controle :
multi ligne\
"une chaine de caracteres"
'c' un caractere
*/
/*en debut de ligne*/ int a = 0;
int b /*en milieu de ligne*/ = 0;
int c = 0; /* en fin de ligne*/

/* Autres tests */
/**************************************************/
/*T*E*S*T*/
/*\
/*\
*/

/* Bug - La prochaine ligne n'est pas un commentaires */
/\
* un bug */
/* Est-ce un commentaire? *\
/ 
ce commentaire est valide... mais termine a la ligne suivante 
et non pas a la ligne precedente.
*/

// 2e serie : Tests des commentaires de style C++

// Commentaires sur une ligne complete
int a1{ 0 }; // Commentaire en fin de ligne
int a2{ 0 }; // Commentaire en fin de ligne multi ligne\
qui va jusqu'ici\
et meme plus loin!
// Commentaire multi-lignes encore une fois \
qui termine ici!

// Bug - Les prochaines lignes ne sont pas des commentaires
/\
/ toujours un bug


// 3e serie : Divers

/* Cacartere et chaines de caractère sans commentaires */
char d = 'a';
char e = '\n';
char f = '\t';
char g = '\\';
char h = '\'';
char i = '\"';
char j[] = "/*Voici un faux commentaire.*/";
char k[] = "\'\"\n\a\\";
char l[] = "Avec un apostrophe ' ici";
char m[]{ "Chaine de caractere a l'interieur d'accolade" };

/* Avec multi lignes */
char n = '\
o';
char o[] = "ici il y a \
une chaine de caracteres";

/* 
Caractere et chaine de caracteres mal definies.
Genere des erreurs de compilation, mais servent a valider la structure des commentaires.
Ces 6 lignes generent 3 caracteres et 3 chaines de caracteres.
*/
char p = '';
char q = '
char r = 'o
char s[] = "";
char t[] = "
char u[] = "bug