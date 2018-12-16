# compilation_s5

Synthèse de la grammaire et de la syntaxe

## Déclarations 
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
`SI expression ALORS { instructions } SINON { instructions }`

### Appel
`IDF(elem)`  
En sachant que IDF est déclarée comme procédure ou fonction et elem son ou ses paramètres

### Lecture / Ecriture
`Read(Type);`  
`Write(IDF);`

### Retour
`Return elem`
Sachant que elem est du même Type que ce que doit renvoyer la suite d'instructions

## Expressions
### Opérations binaires
`&&` : ET    
`||` : OU    
`!` : NON  

### Concaténation
`s1 + s2`  
Sachant `s1` et `s2` deux variables de type String

### Constante
`True` ou `False`

### Comparaison
`e1 op e2`  
Sachant `e1` et `e2` tous deux réels ou entiers  
et op parmis:  
* `<`  : Inférieur  
* `<=` : Inférieur ou égal  
* `>`  : Supérieur  
* `>=` : Supérieur ou égal  
* `==` : Égal  
* `!=` : Différent  
