# bash-multi

Execute a COMMAND in many FOLDERs.

## Example
```bash
$ multi ~/bin ~/.profile.d -- ls
$ multi */ -- pwd
$ multi *git_repo*/ -- git fetch --prune
```

## Known limitations
Some commands may fail
```bash
$ multi */ -- cat README.md | grep '#' # Will succeed
$ multi */ -- grep '#' README.md       # Will fail ¯\_(ツ)_/¯
```

Multiple commands are not supported, neither by using `;` nor `&&`
```bash
$ multi *git_repo*/ -- git status && git pull # Will not execute at all the 2nd command.
$ multi *git_repo*/ -- git status ; git pull  # Will not execute at all the 2nd command.
```
