
# Minishell

## 🖥️ Présentation du projet Minishell

Le projet **Minishell** est une réimplémentation simplifiée d'un interpréteur de commandes (shell) Unix. Il permet de comprendre le fonctionnement des shells en gérant l'exécution de commandes, les redirections d'entrée/sortie, ainsi que la gestion des processus. Ce projet offre l'opportunité de développer des compétences approfondies en programmation C, en gestion de la mémoire et en traitement des chaînes de caractères.

## 🧭 Table des matières

1. [Traitement du parsing](#traitement-du-parsing)
2. [Exécution de commandes](#exécution-de-commandes)
3. [Gestion des pipes et multipipes](#gestion-des-pipes-et-multipipes)
4. [Redirections d'entrée/sortie](#redirections-dentrée-sortie)
5. [Variables d'environnement](#variables-denvironnement)
6. [Historique des commandes](#historique-des-commandes)
7. [Gestion des built-ins](#gestion-des-built-ins)
8. [Installation](#installation)
9. [Utilisation](#utilisation)
10. [Exemples](#exemples)
11. [Captures d’écran](#captures-d’écran)

## ✨ Fonctionnalités

### Traitement du parsing

Le parsing est une étape cruciale dans l'interprétation des commandes saisies par l'utilisateur. Minishell inclut un système de parsing sophistiqué qui décompose les entrées en tokens, permettant une analyse correcte des commandes et des redirections. 

- **Analyse des entrées** : Gère les espaces, les redirections, les pipes et les commandes intégrées.
- **Construction de structures de données** : Crée une représentation interne des commandes, des arguments et des redirections pour un traitement ultérieur.

**Exemple de parsing :**
- **Entrée** : `ls -l | grep 'txt' > output.txt`
- **Sortie du parser** : Une structure qui contient les informations sur les commandes et les redirections.

### Exécution de commandes

Minishell permet d'exécuter des commandes de manière similaire à un shell Unix traditionnel. Il gère la recherche des exécutables dans les répertoires spécifiés par la variable d'environnement `PATH`.

**Exemple d'exécution de commandes :**
```bash
$ ./minishell
> ls -l
```

### Gestion des pipes et multipipes

Le projet supporte l'utilisation des pipes pour connecter la sortie d'une commande à l'entrée d'une autre, permettant de créer des chaînes de traitement efficaces.

- **Gestion des pipes** : Permet d'exécuter plusieurs commandes en utilisant des pipes pour la communication entre les processus.
  
**Exemple de gestion des pipes :**
```bash
$ ./minishell
> ls -l | grep 'txt'
```

- **Multipipes** : Minishell gère également les multipipes, permettant l'exécution de plusieurs commandes en parallèle.

**Exemple de multipipes :**
```bash
$ ./minishell
> ls -l | grep 'txt' | wc -l
```

### Redirections d'entrée/sortie

Minishell gère les redirections d'entrée et de sortie pour diriger le flux des données vers et depuis des fichiers. Cela inclut les redirections simples (`>`, `<`), ainsi que les redirections append (`>>`) et heredoc (`<<`).

- **Redirection de sortie** :
**Exemple de redirection de sortie :**
```bash
$ ./minishell
> echo "Hello, World!" > output.txt
```

- **Redirection d'entrée** :
**Exemple de redirection d'entrée :**
```bash
$ ./minishell
> cat < input.txt
```

- **Redirection d'append** :
**Exemple de redirection d'append :**
```bash
$ ./minishell
> echo "Appending text." >> output.txt
```

- **Heredoc** :
**Exemple d'ici-doc :**
```bash
$ ./minishell
> cat << EOF
> Hello, World!
> EOF
```

### Variables d'environnement

Minishell permet d'accéder et de modifier les variables d'environnement. Les utilisateurs peuvent définir, afficher et supprimer des variables.

**Exemple de gestion des variables d'environnement :**
```bash
$ ./minishell
> export MY_VAR="Hello"
> echo $MY_VAR
Hello
```

### Historique des commandes

Le shell conserve un historique des commandes exécutées, permettant aux utilisateurs de naviguer dans leurs commandes précédentes.

**Exemple d'historique des commandes :**
```bash
$ ./minishell
> cd Documents
> cd ..
> history
```

### Gestion des built-ins

Minishell prend en charge plusieurs commandes intégrées (built-ins) essentielles, qui sont exécutées directement sans créer un nouveau processus. Les built-ins gèrent des opérations fréquentes nécessaires à l'interaction avec le shell :

- **`cd`** : Change le répertoire courant.
**Exemple de built-in cd :**
```bash
$ ./minishell
> cd /path/to/directory
```

- **`echo`** : Affiche une ligne de texte. Gère les options comme `-n` pour éviter le saut de ligne à la fin.
**Exemple de built-in echo :**
```bash
$ ./minishell
> echo "Hello, World!"
```

- **`export`** : Définit ou modifie des variables d'environnement.
**Exemple de built-in export :**
```bash
$ ./minishell
> export MY_VAR="Hello"
```

- **`unset`** : Supprime une variable d'environnement.
**Exemple de built-in unset :**
```bash
$ ./minishell
> unset MY_VAR
```

- **`env`** : Affiche toutes les variables d'environnement actuelles.
**Exemple de built-in env :**
```bash
$ ./minishell
> env
```

- **`exit`** : Quitte le shell avec un code de sortie optionnel. Le code de statut doit être fourni pour respecter les conventions de retour des programmes.
**Exemple de built-in exit :**
```bash
$ ./minishell
> exit 0
```

## 💻 Installation

Pour installer *Minishell*, clonez le dépôt et compilez le projet avec les commandes suivantes :

```bash
git clone https://github.com/ton-utilisateur/minishell.git
cd minishell
make
```

## 🚀 Utilisation

Pour exécuter le shell, utilisez la commande suivante :

```bash
./minishell
```

Vous pouvez alors saisir des commandes dans l'interface de ligne de commande.

## 📚 Exemples

Voici quelques exemples d'utilisation de *Minishell* :

- Exécuter une commande simple :
```bash
$ ./minishell
> pwd
```

- Chaîne de commandes avec pipes et redirections :
```bash
$ ./minishell
> cat input.txt | grep 'pattern' > output.txt
```

## 🖼️ Captures d’écran

![Capture d'écran 1](screenshots/screenshot1.png)
![Capture d'écran 2](screenshots/screenshot2.png)
