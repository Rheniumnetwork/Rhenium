
Debian
====================
This directory contains files used to package Rheniumd/Rhenium-qt
for Debian-based Linux systems. If you compile Rheniumd/Rhenium-qt yourself, there are some useful files here.

## Rhenium: URI support ##


Rhenium-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install Rhenium-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your Rheniumqt binary to `/usr/bin`
and the `../../share/pixmaps/Rhenium128.png` to `/usr/share/pixmaps`

Rhenium-qt.protocol (KDE)

