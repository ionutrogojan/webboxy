# Webboxy (Webbox-C)

<p align="center"><img src="https://raw.githubusercontent.com/ionutrogojan/webbox/8f35d08f14740561eeb43aa785575d9928cff137/icon/webbox_icon.svg" width="480px"/></p>

### A light weight cli tool written in `C` for its low level direct execution.

---

### Available on some major platforms:

- [x] [Linux](https://github.com/ionutrogojan/webboxy/releases/tag/0.1.0) - v0.1.0
- [] Windows
- [] MacOS
- [x] [Source]() - v0.1.0

---

## Create a shortcut for direct access

### *LINUX*
1. open `webboxy.desktop`
2. update the paths:
```ini
  Icon=/path_to_icon/webboxy_icon.svg
  Exec=/path_to_executable/webboxy
```
3. run in the terminal 
```
mv webboxy.desktop ~/.local/share/applications
```
4. reboot the system to apply changes

---

## Building from source

### *Linux*
1. open the folder containing the `makefile`
```sh
cd ~/../webboxy
```
2. run the make command in the terminal
```sh
make # the default process is for release
make dev # the dev process is for testing and development
```
3. run the binary
```sh
./webboxy.o # release
./webboxy-dev.o # development and testing
```
4. use `valgrind` to check for memory leaks
```sh
valgrind --leak-check=full /path/to/webboxy-dev.o
```