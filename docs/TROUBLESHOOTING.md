# Troubleshooting / Dépannage

## English

### The game does not start

Check that you are not loading two versions of the mod at the same time.

Do not load both:

- the Steam Workshop version;
- a local development version.

Keep only one version enabled.

### The keybind does not appear

Check that the mod is loaded on the client.

The keybind is listed under the Character controls category.

### Auto-forward does not work on a server

Check that:

- the client loads the mod;
- the server loads the mod if required by your setup;
- the client and server use compatible versions;
- signatures are valid;
- `John2022FR_DayZMods.bikey` is present on the server.

### Signature mismatch

Check that the server has the public key:

`John2022FR_DayZMods.bikey`

Check that the PBO and `.bisign` file come from the same release.

Do not mix an old `.bisign` with a new PBO.

### The mod appears twice in the Launcher

You probably have both a local copy and a Workshop copy.

Disable one of them.

### Speed adjustment does not use Ctrl or Shift

The mod does not use hardcoded keys.

It uses the player’s configured walk and sprint controls.

If you changed your keybinds in DayZ, use your own configured controls.

---

## Français

### Le jeu ne démarre pas

Vérifiez que vous ne chargez pas deux versions du mod en même temps.

Ne chargez pas à la fois :

- la version Steam Workshop ;
- une version locale de développement.

Gardez une seule version activée.

### La commande n’apparaît pas

Vérifiez que le mod est chargé côté client.

La commande est rangée dans la catégorie Personnage des contrôles.

### L’avance automatique ne fonctionne pas sur un serveur

Vérifiez que :

- le client charge le mod ;
- le serveur charge le mod si votre configuration l’exige ;
- le client et le serveur utilisent des versions compatibles ;
- les signatures sont valides ;
- `John2022FR_DayZMods.bikey` est présente sur le serveur.

### Erreur de signature

Vérifiez que le serveur possède la clé publique :

`John2022FR_DayZMods.bikey`

Vérifiez que le PBO et le fichier `.bisign` viennent de la même release.

Ne mélangez pas un ancien `.bisign` avec un nouveau PBO.

### Le mod apparaît deux fois dans le Launcher

Vous avez probablement à la fois une copie locale et une copie Workshop.

Désactivez l’une des deux.

### L’ajustement de vitesse n’utilise pas Ctrl ou Maj

Le mod n’utilise pas de touches codées en dur.

Il utilise les commandes configurées de marche et de sprint du joueur.

Si vous avez modifié vos touches dans DayZ, utilisez vos propres commandes configurées.
