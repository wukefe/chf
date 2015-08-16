## Installation Instructions
1. Download from ***release branch*** (https://github.com/isagalaev/highlight.js/releases)
2. Read build document [link](http://highlightjs.readthedocs.org/en/latest/building-testing.html)
3. Install node.js: `npm config set registry http://registry.npmjs.org/` after meet errors when run `node install` to check the dependency of the package.
4. Build `eli` and `q`: `node tools/build.js -n q eli`   ***Most used***
5. Build common languages (`eli` and `q` are not included): `node tools/build.js :common`
6. Build all languages for node.js platform (may be not appliable to `eli`): `node tools/build.js -t node`

**Note: don't download developing branch, not reliable**

## File Location
- src/languages/eli.js
- test/detect/eli/default.txt
