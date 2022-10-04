#  INF224 - OLIVEIRA MACHADO DE SOUSA Lucas

This is a project for the course "INF224 - Paradigmes de Programmation" at Télécom Paris. It consists of two parts: a C++ one, where classes are defined to handle different types of media (such as images and videos), and a Java Swing part where the GUI is implemented. Below, you can find comments about each step of development, with the steps being followed as proposed in the course website (https://perso.telecom-paristech.fr/elc/cpp/TP-C++.html).
The TP was fully done in my machine running Ubuntu 20.04, but it was tested in a school machine afterwards and it functioned normally.

## C++
- **Steps 1 to 3**:

No necessary comments about these steps. The makefile was correctly updated with new sources, functions that don't change instance variables were declared with keyword *const*.

- **Step 4**:

> Comme pour la fonction d'affichage, la fonction pour jouer l'objet ne modifie pas l'objet et elle doit être déclarée dans les classes  **Photo**  et  **Video**  et dans la  **classe de base**  afin de permettre un appel polymorphique sur la hiérarchie de classes. Cependant, contrairement à la fonction d'affichage, elle ne peut pas avoir d'implementation au niveau de la classe de base (car a priori chaque type d'objet nécessite un utilitaire différent pour être joué). Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?

This kind of method is called *abstract method*, a method without an implementation. This kind of method shows us a concept specification for which the realization will be different for different subclasses.
To declare the abstract method we add the keyword *virtual* in the beginning of the declaration and we assign 0 to it. To actually use such a method, we have to redefine and implement it in a subclass.

> Modifier le  _Makefile_  si nécessaire (on rappelle qu'il ne faut pas mettre les .h dans  _SOURCES_). Compiler, corriger les éventuelles erreurs et tester le programme. Si vous avez fait correctement ce qui précède, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?

The methods don't have an implementation anymore (since they're now abstract methods).

- **Step 5**

> On veut maintenant pouvoir traiter génériquement une liste comprenant à la fois des photos et des vidéos. Pour ce faire créer dans  _main.cpp_  un tableau dont les éléments sont tantôt une photo tantôt une vidéo. Ecrire ensuite une boucle permettant d'afficher les attributs de tous les élements du tableau (ou de les "jouer"). Cette boucle n'a  **pas besoin de connaître le type**  des élements : elle doit pouvoir traiter de la même manière tous les objets dérivant de la classe de base. Quelle est la propriété caractéristique de l'**orienté objet**  qui permet de faire cela ?

This characteristic is called inheritance polymorphism, in which an object can be seen in different ways (a square can be seen as a square, a rectangle, a polygon, etc).

> Qu'est-il spécifiquement  **nécessaire de faire dans le cas du C++**  ?

If a method is redefined, we have to change it to *virtual* in the base class.

> Quel est le type des éléments du tableau : est-ce que ce tableau contient les objets ou des  **pointeurs**  vers ces objets ? Pourquoi ? Comparer à Java.

The table contains pointers to the objects. The difference between Java and C++ in this case is that Java always calls the method of the *pointed*, while in C++ it depends if we use a dynamic linking (method of the *pointed*) or static linking (method of the *pointer*).

- **Step 6**

> Que faut-il faire pour que l'objet Film ait  **plein contrôle sur ses données**  et que son tableau de durées des chapitres ne puisse pas être modifié (ou pire, détruit) à son insu ? (c'est l'objet qui doit pouvoir modifier ce qui lui appartient, pas les autres !)

We need to create a deep-copy of the object and let Film handle this copy.

> **Attention**, le même problème se pose si un accesseur  **retourne directement ce tableau sans prendre les précautions nécessaires**  : la encore le contenu du tableau n'est pas récopié et l'appelant peut le modifier à sa guise. Quelle est la solution très simple que propose C/C++ pour éviter ce problème ?

Adding a *const* to the method declaration is enough.

- **Step 7**

> Contrairement à Java ou C#, C/C++ ne gère pas la  _mémoire dynamique_  automatiquement (*) : comme il n'y a pas de ramasse miettes, tout ce qui a été créé avec  _new_  doit être détruit avec  _delete_  sinon on aura des fuites mémoires. Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait  **pas de fuite mémoire**  quand on détruit leurs instances ?

Only the Film class, since it's the only one we used "new" to create an object.

> De même, la  **copie d'objets**  peut poser problème dans certains cas. Pourquoi et que faudrait-il faire ?

If we use a shallow copy, the pointer of the copy and of the original object will point to the same object, so we'll end up trying to destroy an object twice. Therefore, we must use deep copies.

- **Step 8**

> Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de  **pointeurs**  d'objets. Pourquoi ? Comparer à Java.

With a list of pointers, we can use Polymorphism and treat different objects in a similar manner, as explained in **Step 5**.

- **Step 9**

Nothing to comment about this step.  The code was updated in order to use smart pointers and I simplified the writing using *typedef*.

- **Step 10**

> Les méthodes précédentes permettent d'assurer la **cohérence de la base de données** car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec _new_ (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?

We could use the keyword *protected* in the definition of the constructor of these classes.

- **Step 11**

No specific comments about this step. Just to clarify about the #ifdef VERSION_TRUC suggested, I didn't include it since I did the versioning using a private repository on GitHub, but the tests for each step are included as commented code in the *main.cpp* file.

- **Overview**

Steps 1 to 11 were implemented following the suggestions in the TP page, without including many extras (but I did include some functions such as the ability to delete a media or a group).

## Java Swing
There are no questions in the Java Swing part of the TP, so I'll give a brief overview. The four steps were implemented. For the buttons, I've used the 3rd strategy seen in the course, with nested classes. For the second step, I've implemented the solution encouraged with the use of Action Listeners using subclasses of *AbstractAction*.
As said before, I've implemented some extra functions in the C++ side (like deleting a media), but I chose to not implement it in the GUI since it'd take a little extra time.

## Final considerations

The program was tested in a school machine and it performed as expected. For the upload. I'm not uploading the media used to test with the work (I believe it's not quite clear if we should include some media for testing when submitting our work) and therefore I've commented the part of the code where some medias are created in the *main.cpp* file.

The Doxygen documentation is accessible through the file *index.html* in the html folder.
