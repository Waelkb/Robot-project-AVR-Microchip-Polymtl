# PathFinder

<div align="center">
  
  [<img src="https://img.shields.io/badge/-English-blue?style=for-the-badge">](#overview)
  [<img src="https://img.shields.io/badge/-Français-green?style=for-the-badge">](#aperçu)

</div>

---

## Overview

The **PathFinder** Project is designed to navigate a predefined course, detect endpoints and posts, and provide a report of its journey. The robot is equipped with various sensors and actuators, including line markers, motors, LEDs, and a sound player, to perform its tasks autonomously. The project is implemented using AVR microcontrollers and programmed in C++.

<div align="center">
    <img alt="Robot" width="400" src="https://github.com/tierChampion/inf1900-projet/blob/master/res/robots.jpg?raw=true">
    <br>
    <small>Image of a robot without connections and a robot ready for the program.</small>
</div>

## Mode Selection

The robot offers three distinct modes, which can be selected using a LED blinking system combined with a reset button (Reset). When the program starts, the LED cycles through three colors: green, red, and amber. Each color corresponds to a specific mode and stays lit for 2 seconds before switching to the next. Thus, a complete cycle lasts 6 seconds. If no mode is selected by the end of the cycle, the robot returns to the green color, marking the beginning of a new cycle. To select a mode, simply press the Reset button while the LED displays the color corresponding to the desired mode:

- 🟢 Green: Mode 1 (Search Endpoint)
- 🔴 Red: Mode 2 (Cross Course)
- 🟠 Amber: Mode 3 (Display Report)

Once a mode is selected, the LED blinks for 2 seconds in the corresponding mode color before starting the mode execution. The blinking frequency is 4 Hz (125 ms on, 125 ms off).

## Mode 1: Search Endpoint

In this mode, the robot is placed either in point A or B, in one of the four orientations: NE, NW, SE, SW. The robot navigates the course to find an endpoint (C, D, or E) depending on where it started. The robot needs to determine by itself where it started, its orientation, and where it ended. The robot must reach one of the endpoints of the path (C, D, or E) by moving only along the tape segments without skipping from one intersection to another. Once an endpoint is reached, the robot lights up a LED to indicate which one and plays a sound:
- C (green): Green LED.
- D (red): Red LED.
- E (amber): Amber LED.

## Mode 2: Cross Course

In this mode, the robot is placed either at point C or D and must follow the post that will be placed at the beginning either at point 1 or 2. The robot navigates to the detected post and stops exactly 10 cm away from it. After stopping, the post is moved to either point 3 or 4, and then to point 5 or 6. Each time the robot stops, the button must be pressed again for it to proceed to the next post. After detecting the last post (at point 5 or 6), the post is removed, and the robot, upon pressing the button, must navigate to point E and stop exactly at this endpoint. The robot plays a sound each time it detects a post and upon arriving at the endpoint. 

## Mode 3: Display Report

The robot displays a report of its journey, summarizing its activities in both Mode 1 and Mode 2. For Mode 1 (Search Endpoint), the report details the starting point (A or B), the endpoint reached (C, D, or E), and the initial orientation (NE, NW, SE, or SW). For Mode 2 (Cross Course), the report includes the starting point (C or D) and the number of each detected post during the course traversal.

## Library

- **Led**: Manages LEDs for visual indicators.

- **SoundPlayer**: Generates sounds for the robot's modes.

- **Sharp**: Detects the distance between the robot and objects.

- **Can**: Reads inputs on one of the PortA pins and performs analog-to-digital conversion to return a value.

- **Memoire_24**: Example of using an I2C EEPROM memory.

- **Motor**: Allows adjusting the speed and direction of the robot's wheels via PWM modulation.

- **RS232**: Serial communication (UART) between the ATmega324PA microcontroller and other devices.

- **Button**: Manages interactions with the button.

- **LineMarker**: Manages line-following sensors.

- **Path**: Manages the robot's path and navigation.

- **Robot**: Main class that orchestrates the robot's various functionalities, including mode selection and execution, memory management, and serial communication.

## Project Configuration

### Required Hardware

- AVR ATmega324PA microcontroller
- Development platform or breadboard
- Connectors and cables assembled with crimping
- Peripheral components: piezoelectric transducer, line-following sensor, infrared sensor
- AVR Atmega8 programmer

### Development Environment

- Operating system: Linux with Fedora distribution, or macOS.
- Programming language: C++.

## Building the Project

To build the project, navigate to the root directory and run the following commands:

```sh
cd lib
make clean
make
cd ..
cd app
make clean
make
```

## Running the Project

After building the project, you can upload the generated binary to the AVR microcontroller using the following command:
```sh
make install
```
Ensure that the microcontroller is connected via USB. The microcontroller along with the robot car should be properly set up with the pins configured as specified in the code.

---

<br><br><br>

---

## Aperçu

Le projet **PathFinder** est conçu pour naviguer sur un parcours prédéfini, détecter les points de fin et les bornes, et fournir un rapport de son parcours. Le robot est équipé de divers capteurs et actionneurs, notamment des détecteurs de lignes, des moteurs, des LEDs et un lecteur sonore, afin d'effectuer ses tâches de manière autonome. Le projet est implémenté à l'aide de microcontrôleurs AVR et programmé en C++.

<div align="center">
    <img alt="Robot" width="400" src="https://github.com/tierChampion/inf1900-projet/blob/master/res/robots.jpg?raw=true">
    <br>
    <small>Image d’un robot sans connexions et d’un robot prêt pour le programme.</small>
</div>

## Sélection des modes

Le robot propose trois modes distincts, qui peuvent être sélectionnés à l'aide d'un système de clignotement LED combiné avec un bouton de réinitialisation (Reset). Lorsque le programme démarre, la LED alterne entre trois couleurs : vert, rouge et ambre. Chaque couleur correspond à un mode spécifique et reste allumée pendant 2 secondes avant de passer à la suivante. Ainsi, un cycle complet dure 6 secondes. Si aucun mode n'est sélectionné à la fin du cycle, le robot revient à la couleur verte, marquant le début d'un nouveau cycle. Pour sélectionner un mode, appuyez simplement sur le bouton Reset pendant que la LED affiche la couleur correspondant au mode souhaité :

- 🟢 Vert : Mode 1 (Recherche du point de fin)
- 🔴 Rouge : Mode 2 (Traversée du parcours)
- 🟠 Ambre : Mode 3 (Affichage du rapport)

Une fois le mode sélectionné, la LED clignote pendant 2 secondes dans la couleur du mode correspondant avant de commencer l'exécution. La fréquence de clignotement est de 4 Hz (125 ms allumée, 125 ms éteinte).

## Mode 1 : Recherche du point de fin

Dans ce mode, le robot est placé au point A ou B, dans l'une des quatre orientations : NE, NO, SE, SO. Le robot navigue sur le parcours pour trouver un point de fin (C, D ou E) en fonction de son point de départ. Il doit déterminer par lui-même son point de départ, son orientation initiale et son point d'arrivée. Le robot doit atteindre l'un des points de fin (C, D ou E) en se déplaçant uniquement le long des segments de bande sans sauter d'une intersection à une autre. Une fois qu'un point de fin est atteint, le robot allume une LED pour indiquer lequel et joue un son :
- C (vert) : LED verte.
- D (rouge) : LED rouge.
- E (ambre) : LED ambre.

## Mode 2 : Traversée du parcours

Dans ce mode, le robot est placé au point C ou D et doit suivre un poteau qui sera initialement positionné au point 1 ou 2. Le robot navigue jusqu'au poteau détecté et s'arrête à exactement 10 cm de celui-ci. Une fois arrêté, le poteau est déplacé au point 3 ou 4, puis au point 5 ou 6. Chaque fois que le robot s'arrête, il faut appuyer sur le bouton pour qu'il continue vers le prochain poteau. Après avoir détecté le dernier poteau (au point 5 ou 6), le poteau est retiré, et le robot, sur pression du bouton, doit naviguer jusqu'au point E et s'arrêter exactement à cet endroit. Le robot joue un son à chaque détection de poteau et lorsqu'il atteint le point final.

## Mode 3 : Affichage du rapport

Le robot affiche un rapport de son parcours, résumant ses activités dans les modes 1 et 2. Pour le mode 1 (Recherche du point de fin), le rapport détaille le point de départ (A ou B), le point de fin atteint (C, D ou E), ainsi que l'orientation initiale (NE, NO, SE ou SO). Pour le mode 2 (Traversée du parcours), le rapport inclut le point de départ (C ou D) et le numéro de chaque poteau détectée lors de la traversée du parcours.

## Librairie

- **Led** : Gestion des LED pour les indicateurs visuels.

- **SoundPlayer** : Génération de sons pour les modes du robot.

- **Sharp** : Détection de la distance entre le robot et les objets.

- **Can** : Lecture des entrées sur une des broches du PortA et conversion analogique-numérique pour retourner une valeur.

- **Memoire_24** : Exemple d'utilisation d'une mémoire EEPROM I2C.

- **Motor** : Permet le réglage de la vitesse et de la direction des roues du robot via la modulation PWM.

- **RS232** : Communication série (UART) entre le microcontrôleur ATmega324PA et d'autres dispositifs.

- **Button** : Gestion des interactions avec le bouton.

- **LineMarker** : Gestion des capteurs de suivi de ligne.

- **Path** : Gestion du chemin et de la navigation du robot.

- **Robot** : Classe principale qui orchestre les différentes fonctionnalités du robot, incluant la sélection et l'exécution des modes, la gestion de la mémoire, et la communication série.

## Configuration du Projet

### Matériel Requis

- Microcontrôleur AVR ATmega324PA
- Plateforme de développement ou breadboard
- Connecteurs et câbles assemblés avec un sertissage
- Composants périphériques : transducteur piézoélectrique, capteur de suivi de ligne, capteur infrarouge
- Programmateur AVR Atmega8

### Environnement de Développement

- Système d'exploitation : Linux avec distribution Fedora, ou bien macOS.
- Utilisation du langage de programmation C++.

## Compilation du projet

Pour compiler le projet, accédez au répertoire racine et exécutez les commandes suivantes :

```sh
cd lib
make clean
make
cd ..
cd app
make clean
make
```

## Exécution du projet

Après avoir compilé le projet, vous pouvez téléverser le binaire généré sur le microcontrôleur AVR en utilisant la commande suivante :
```sh
make install
```
Assurez-vous que le microcontrôleur est connecté via USB. Le microcontrôleur ainsi que la voiture robot doivent être correctement configurés avec les broches spécifiées dans le code.
#   R o b o t - p r o j e c t - A V R - M i c r o c h i p - P o l y m t l  
 