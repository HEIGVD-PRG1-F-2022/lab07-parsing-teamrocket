# Labo 07 - Parsing

La plupart des classes sont déjà faites.
Il vous reste seulement d'implémenter l'interprétation des fichiers dans une structure utilisable par l'algorithme.
Pour ceci, vous devrez compléter la méthode `Tunnels`.
Cette méthode est appelée avec un `string` qui contient le fichier complet.
L'algorithme a besoin des structures suivantes:

- `std::vector<std::string> valves` qui représente toutes les soupapes disponible dans le fichier
- `std::map<std::string, unsigned> rates` est une `map` qui contient la pression derrière chaque soupape 
- `std::map<std::string, std::vector<std::string>> links` est aussi une `map` qui contient les tunnels qui
sortent de chaque cave
- `unsigned fact` - le factoriel du nombre des sorties d'une cave maximale.
C'est utilisé pour calculer la sortie sans biais.

Pour les `map`s, tout ce que vous devez savoir est comment insérer un élément dans une `map`:

```c++
rates["AA"] = 0;
links["AA"] = vector<string>{"DD", "II", "BB"};
```

Ajoute la pression `0` pour la soupape `"AA"`, ainsi que des liens vers les soupapes `"DD"`, `"II"`, et `"BB"`.

## Bonus

Une fois la classe `Tunnels` complétée, vous pouvez trouver la bonne solution avec la recherche
génétique.
Regardez la méthode `main` et modifiez-la pour faire tourner plusieurs recherches génétiques en même temps.

Quand vous avez trouvé la bonne solution, ajoutez un autre `Solve`r pour montrer comment une version
seulement aléatoire fonctionne.

Finalement vous pouvez essayer de trouver la solution pour la deuxième partie, en utilisant le
`TwoPersons` au lieu du `OnePerson`.

# Consignes pour ce labo

- Utilisez les méthodes vues au cours pour les `string`
- Ajoutez des exceptions si quelque chose ne marche pas comme prévu
- Attrapez les exceptions dans les bons endroits et quittez avec une erreur compréhensible