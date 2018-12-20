# compilation_s5

Synthèse de la grammaire et de la syntaxe



## Les constantes
### Constante Entière
`0|([1-9][0-9]*)`  : suite simple de chiffres
0, 1, 2, 10, 121233 ...

### Constante Réelle
`(0|([1-9][0-9]*))"."([0-9]+)` : deux suites simples de chiffres avec un point les séparants
0.0, 0.1, 1.6, 2.0, 10.12414134, 121233.111111 ...

### Constante Caractère
`'[a-zA-Z]'` : un unique caractère alphabétique entouré de simples 'quotes'
'a', 'b', 'Z' ...

### Constante Chaine
`"[a-zA-Z0-9_]+"` : suites vide ou non de caractères alphabétique entouré de double "quotes"
"abc", "Abccc", "", "A" ...

## Déclarations 
### IDF
`[a-z][a-zA-Z0-9_]*` : Suite de caractères alphanumériques commençant par une minuscule
x, p, f ...  
~~Aazea~~  
~~1ae~~  

*dans l'ordre:*  
Suivent le même paterne:
Type|Var *IDF* : Définition de la variable *;*

### Type  
#### Structure  
`Type s : Struct elem : Int; elem2 : Chaine; Fstruct;`

#### Tableaux
`Type t : Tab [ Int#Int ] Of Type;`  
`Type t2 : Tab [ Int#Int,Int#Int ] Of Type;`

### Variable

#### Entiers
`Var x : Int`

#### Reels
`Var y : Float`

#### Booleens
`Var b : Bool`

#### Caractère
`Var c : Char`

#### Chaines de caractères
`Var s : String[Int]`

### Fonctions et Procedures
Contenant des instructions entre { }
#### Fonction 
```
Fonction f ~( IDF : Type )~ Return TypeR
{
    
    Return ~~variable ou constante de type TypeR~~;
};
```

#### Procédure
```
Procedure p ~( IDF : Type )~
{

};
```

## Instructions
### Affectation
`IDF = expression ;`

### Condition
`If expression Then { instructions } Else { instructions } ;`

### Appel
`IDF(elem)`  
En sachant que IDF est déclarée comme procédure ou fonction et elem son ou ses paramètres

### Tant que
`While Condition Do { instructions } ;`

### Lecture / Ecriture
`Read(Type);`  
`Write(IDF);`

### Vide
`Null;`
Par exemple pour n'avoir aucune instruction dans un bloc -> Else
### Retour
`Return elem`
Sachant que elem est du même Type que ce que doit renvoyer la suite d'instructions

## Expressions
### Opérations binaires
`&&` : ET    
`||` : OU    
`!` : NON  

### Concaténation
`s1 + s2`  
Sachant `s1` et `s2` deux variables de type String

### Constante
`True` ou `False`

### Comparaison
`e1 op e2`  
Sachant `e1` et `e2` tous deux réels ou entiers  
et op parmis:  
* `<`  : Inférieur  
* `<=` : Inférieur ou égal  
* `>`  : Supérieur  
* `>=` : Supérieur ou égal  
* `==` : Égal  
* `!=` : Différent  
