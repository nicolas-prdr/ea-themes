# Centralisation des thèmes **Europ Assistance**

Composer requirements:

```sh
composer require drupal/radix:5.0.0.alpha-1
composer require drupal/components
```

Pour modifier le **thème principal** il est necessaire d'utiliser **npm**:
```
$ cd web/themes/custom/ea
$ npm install
$ npm run watch
```
Pour une optimisation des assets (version prod), utiliser:
```
$ npm run production
```
Pour les **thèmes enfants**, utiliser (depuis le repertoire du thème enfant):
```
$ npm run sass-watch
```
⚠️ **Si des modifications sont apportées au thème parent (*ea*), il faut penser à recompiler les css des thèmes enfants afin que ces derniers bénéficient des modifications.** ⚠️

