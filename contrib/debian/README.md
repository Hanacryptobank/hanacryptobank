
Debian
====================
This directory contains files used to package hanacryptobankd/hanacryptobank-qt
for Debian-based Linux systems. If you compile hanacryptobankd/hanacryptobank-qt yourself, there are some useful files here.

## hanacryptobank: URI support ##


hanacryptobank-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install hanacryptobank-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your hanacryptobank-qt binary to `/usr/bin`
and the `../../share/pixmaps/hanacryptobank128.png` to `/usr/share/pixmaps`

hanacryptobank-qt.protocol (KDE)

