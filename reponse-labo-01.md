#Atelier 01

## 3a- Commandes linux/Unix - Préparation et stratégies
réponse à la question: on pourrait utiliser la commande mv qui sert à renommé le fichier en sortie.md

## 3b - Emvellir Linux - Activer les couleurs
### question 1: 
Décrire sous la forme d'un bash les étapes pour configurer et obtenir des couleur dans le terminal.
Pour obtenir des couleurs dans le terminal , on édite le fichier ~/.bashrc
en y ajoutant le commande suivant: alias ls='ls --color'
export PS1='\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]$ '

### question 2:
pouvez vous executer votre script de configuration plusieur fois?
Oui si on modifie les permissions"

### question3 : 
vous avez répondu non en Q2 corrigez-le.
donc Oui encore.

### question4 : 
Quelle commande active le changements permanent dans la session 
terminal active?
echo "PS1='\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]$ '" >> ~/.bashrc  
source ~/.bashrc

### question5
Décrire ce qui est mnecessaire pour parvenir à changer le prompt
ce qui est necessaire est d'ouvrir le fichier de configuration et y ajouter le PS1 avec une valeur
